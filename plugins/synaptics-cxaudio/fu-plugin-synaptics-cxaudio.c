/*
 * Copyright (C) 2019 Richard Hughes <richard@hughsie.com>
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */

#include "config.h"

#include <fwupdplugin.h>

#include "fu-synaptics-cxaudio-device.h"
#include "fu-synaptics-cxaudio-firmware.h"

static void
fu_plugin_synaptics_cxaudio_init(FuPlugin *plugin)
{
	FuContext *ctx = fu_plugin_get_context(plugin);
	fu_plugin_add_device_gtype(plugin, FU_TYPE_SYNAPTICS_CXAUDIO_DEVICE);
	fu_plugin_add_firmware_gtype(plugin, NULL, FU_TYPE_SYNAPTICS_CXAUDIO_FIRMWARE);
	fu_context_add_quirk_key(ctx, "CxaudioChipIdBase");
	fu_context_add_quirk_key(ctx, "CxaudioPatch1ValidAddr");
	fu_context_add_quirk_key(ctx, "CxaudioPatch2ValidAddr");
	fu_context_add_quirk_key(ctx, "CxaudioSoftwareReset");
}

void
fu_plugin_init_vfuncs(FuPluginVfuncs *vfuncs)
{
	vfuncs->build_hash = FU_BUILD_HASH;
	vfuncs->init = fu_plugin_synaptics_cxaudio_init;
}
