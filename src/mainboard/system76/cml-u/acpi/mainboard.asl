/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2019 System76
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#if defined(CONFIG_BOARD_SYSTEM76_DARP6)
	#define COLOR_KEYBOARD 1
#elif defined(CONFIG_BOARD_SYSTEM76_GALP4)
	#define COLOR_KEYBOARD 0
#else
	#error Unknown Mainboard
#endif

Scope (\_SB) {
	#include "ac.asl"
	#include "battery.asl"
	#include "buttons.asl"
	#include "hid.asl"
	#include "lid.asl"
	#include "s76.asl"
	#include "sleep.asl"
}

#include "tbt.asl"

Scope (_GPE) {
	#include "gpe.asl"
}
