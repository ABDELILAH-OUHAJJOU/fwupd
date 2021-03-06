/*
 * Copyright (C) 2021 Michael Cheng <michael.cheng@emc.com.tw>
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */

#pragma once

#include <gio/gio.h>

#define FU_CFU_DEVICE_OFFER_SKIP	  0x00
#define FU_CFU_DEVICE_OFFER_ACCEPT	  0x01
#define FU_CFU_DEVICE_OFFER_REJECT	  0x02
#define FU_CFU_DEVICE_OFFER_BUSY	  0x03
#define FU_CFU_DEVICE_OFFER_COMMAND	  0x04
#define FU_CFU_DEVICE_OFFER_NOT_SUPPORTED 0xFF

#define FU_CFU_DEVICE_FLAG_FIRST_BLOCK 0x80
#define FU_CFU_DEVICE_FLAG_LAST_BLOCK  0x40

#define FU_CFU_DEVICE_STATUS_SUCCESS		0x00
#define FU_CFU_DEVICE_STATUS_ERROR_PREPARE	0x01
#define FU_CFU_DEVICE_STATUS_ERROR_WRITE	0x02
#define FU_CFU_DEVICE_STATUS_ERROR_COMPLETE	0x03
#define FU_CFU_DEVICE_STATUS_ERROR_VERIFY	0x04
#define FU_CFU_DEVICE_STATUS_ERROR_CRC		0x05
#define FU_CFU_DEVICE_STATUS_ERROR_SIGNATURE	0x06
#define FU_CFU_DEVICE_STATUS_ERROR_VERSION	0x07
#define FU_CFU_DEVICE_STATUS_SWAP_PENDING	0x08
#define FU_CFU_DEVICE_STATUS_ERROR_INVALID_ADDR 0x09
#define FU_CFU_DEVICE_STATUS_ERROR_NO_OFFER	0x0A
#define FU_CFU_DEVICE_STATUS_ERROR_INVALID	0x0B

#define FU_CFU_DEVICE_REJECT_OLD_FIRMWARE	0x00
#define FU_CFU_DEVICE_REJECT_INV_COMPONENT	0x01
#define FU_CFU_DEVICE_REJECT_SWAP_PENDING	0x02
#define FU_CFU_DEVICE_REJECT_WRONG_BANK		0x04
#define FU_CFU_DEVICE_REJECT_SIGN_RULE		0xE0
#define FU_CFU_DEVICE_REJECT_VER_RELEASE_DEBUG	0xE1
#define FU_CFU_DEVICE_REJECT_DEBUG_SAME_VERSION 0xE2

const gchar *
fu_cfu_device_reject_to_string(guint8 val);
const gchar *
fu_cfu_device_status_to_string(guint8 val);
const gchar *
fu_cfu_device_offer_to_string(guint8 val);
