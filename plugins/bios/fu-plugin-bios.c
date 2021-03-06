/*
 * Copyright (C) 2020 Mario Limonciello <mario.limonciello@dell.com>
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */

#include "config.h"

#include <fwupdplugin.h>

static gboolean
fu_plugin_bios_startup(FuPlugin *plugin, GError **error)
{
	FuContext *ctx = fu_plugin_get_context(plugin);
	const gchar *vendor;

	vendor = fu_context_get_hwid_value(ctx, FU_HWIDS_KEY_BIOS_VENDOR);
	if (g_strcmp0(vendor, "coreboot") == 0) {
		g_set_error(error, FWUPD_ERROR, FWUPD_ERROR_NOT_FOUND, "system uses coreboot");
		return FALSE;
	}

	return TRUE;
}

static gboolean
fu_plugin_bios_coldplug(FuPlugin *plugin, GError **error)
{
	g_autofree gchar *sysfsfwdir = NULL;
	g_autofree gchar *esrt_path = NULL;

	/* are the EFI dirs set up so we can update each device */
#if defined(__x86_64__) || defined(__i386__)
	g_autoptr(GError) error_local = NULL;
	if (!fu_efivar_supported(&error_local)) {
		fu_plugin_add_flag(plugin, FWUPD_PLUGIN_FLAG_LEGACY_BIOS);
		fu_plugin_add_flag(plugin, FWUPD_PLUGIN_FLAG_USER_WARNING);
		return TRUE;
	}
#endif

	/* get the directory of ESRT entries */
	sysfsfwdir = fu_common_get_path(FU_PATH_KIND_SYSFSDIR_FW);
	esrt_path = g_build_filename(sysfsfwdir, "efi", "esrt", NULL);
	if (!g_file_test(esrt_path, G_FILE_TEST_IS_DIR)) {
		fu_plugin_add_flag(plugin, FWUPD_PLUGIN_FLAG_CAPSULES_UNSUPPORTED);
		fu_plugin_add_flag(plugin, FWUPD_PLUGIN_FLAG_USER_WARNING);
		return TRUE;
	}

	/* we appear to have UEFI capsule updates */
	fu_plugin_add_flag(plugin, FWUPD_PLUGIN_FLAG_DISABLED);
	return TRUE;
}

void
fu_plugin_init_vfuncs(FuPluginVfuncs *vfuncs)
{
	vfuncs->build_hash = FU_BUILD_HASH;
	vfuncs->startup = fu_plugin_bios_startup;
	vfuncs->coldplug = fu_plugin_bios_coldplug;
}
