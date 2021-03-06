/*
 * Copyright (C) 2020 Benson Leung <bleung@chromium.org>
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */

#include "config.h"

#include <fwupdplugin.h>

#include "fu-cros-ec-firmware.h"
#include "fu-cros-ec-usb-device.h"

static void
fu_plugin_cros_ec_init(FuPlugin *plugin)
{
	fu_plugin_add_device_gtype(plugin, FU_TYPE_CROS_EC_USB_DEVICE);
	fu_plugin_add_firmware_gtype(plugin, NULL, FU_TYPE_CROS_EC_FIRMWARE);
}

void
fu_plugin_init_vfuncs(FuPluginVfuncs *vfuncs)
{
	vfuncs->build_hash = FU_BUILD_HASH;
	vfuncs->init = fu_plugin_cros_ec_init;
}
