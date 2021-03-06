/*
 * Copyright (C) 2016 Richard Hughes <richard@hughsie.com>
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */

#include "config.h"

#include <fwupdplugin.h>

#include "fu-dfu-device.h"

static void
fu_plugin_dfu_init(FuPlugin *plugin)
{
	FuContext *ctx = fu_plugin_get_context(plugin);
	fu_plugin_add_device_gtype(plugin, FU_TYPE_DFU_DEVICE);
	fu_context_add_quirk_key(ctx, "DfuAltName");
	fu_context_add_quirk_key(ctx, "DfuForceTimeout");
	fu_context_add_quirk_key(ctx, "DfuForceVersion");
}

void
fu_plugin_init_vfuncs(FuPluginVfuncs *vfuncs)
{
	vfuncs->build_hash = FU_BUILD_HASH;
	vfuncs->init = fu_plugin_dfu_init;
}
