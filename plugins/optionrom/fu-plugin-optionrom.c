/*
 * Copyright (C) 2015-2016 Richard Hughes <richard@hughsie.com>
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */

#include "config.h"

#include <fwupdplugin.h>

#include "fu-optionrom-device.h"

static void
fu_plugin_optionrom_init(FuPlugin *plugin)
{
	fu_plugin_add_udev_subsystem(plugin, "pci");
	fu_plugin_add_rule(plugin, FU_PLUGIN_RULE_CONFLICTS, "udev");
	fu_plugin_add_device_gtype(plugin, FU_TYPE_OPTIONROM_DEVICE);
}

void
fu_plugin_init_vfuncs(FuPluginVfuncs *vfuncs)
{
	vfuncs->build_hash = FU_BUILD_HASH;
	vfuncs->init = fu_plugin_optionrom_init;
}
