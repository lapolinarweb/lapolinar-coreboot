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

#define COLOR_KEYBOARD 0

Scope (\_SB) {
    #include "ac.asl"
    #include "battery.asl"
    #include "buttons.asl"
    #include "hid.asl"
    #include "lid.asl"
    #include "s76.asl"
    #include "sleep.asl"
}

Scope (_GPE) {
    #include "gpe.asl"
}
