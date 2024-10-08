// Copyright 2024 Ashish Shrestha (@axhixh)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U
//RP2040 COLDSLEEP WAKEUP BUG
#define SPLIT_USB_TIMEOUT 5000
#define SPLIT_USB_TIMEOUT_POLL 25

#define EE_HANDS