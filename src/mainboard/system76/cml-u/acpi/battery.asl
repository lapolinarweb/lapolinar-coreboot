/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2019 System76
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

Device (BAT0)
{
    Name (_HID, EisaId ("PNP0C0A") /* Control Method Battery */)  // _HID: Hardware ID
    Name (_UID, Zero)  // _UID: Unique ID
    Name (_PCL, Package (0x01)  // _PCL: Power Consumer List
    {
        _SB
    })
    Name (BFCC, Zero)
    Method (_STA, 0, NotSerialized)  // _STA: Status
    {
        If (One)
        {
            If (^^PCI0.LPCB.EC0.BAT0)
            {
                Return (0x1F)
            }
            Else
            {
                Return (0x0F)
            }
        }
        Else
        {
            Return (0x0F)
        }
    }

    Name (PBIF, Package (0x0D)
    {
        // Power unit (0)
        One,
        // Design capacity (1)
        0xFFFFFFFF,
        // Last full charge capacity (2)
        0xFFFFFFFF,
        // Battery technology (3)
        One,
        // Design voltage (4)
        0x39D0,
        // Design capacity of warning (5)
        Zero,
        // Design capacity of low (6)
        Zero,
        // Battery capacity granularity 1 (7)
        0x40,
        // Battery capacity granularity 2 (8)
        0x40,
        // Model (9)
        "BAT",
        // Serial (A)
        "0001",
        // Battery type (B)
        "LION",
        // OEM information (C)
        "Notebook"
    })
    Method (IVBI, 0, NotSerialized)
    {
        PBIF [One] = 0xFFFFFFFF
        PBIF [0x02] = 0xFFFFFFFF
        PBIF [0x04] = 0xFFFFFFFF
        PBIF [0x09] = " "
        PBIF [0x0A] = " "
        PBIF [0x0B] = " "
        PBIF [0x0C] = " "
        BFCC = Zero
    }

    Method (UPBI, 0, NotSerialized)
    {
        If (^^PCI0.LPCB.EC0.BAT0)
        {
            Local0 = (^^PCI0.LPCB.EC0.BDC0 & 0xFFFF)
            PBIF [One] = Local0
            Local0 = (^^PCI0.LPCB.EC0.BFC0 & 0xFFFF)
            PBIF [0x02] = Local0
            BFCC = Local0
            Local0 = (^^PCI0.LPCB.EC0.BDV0 & 0xFFFF)
            PBIF [0x04] = Local0
            Local0 = (^^PCI0.LPCB.EC0.BCW0 & 0xFFFF)
            PBIF [0x05] = Local0
            Local0 = (^^PCI0.LPCB.EC0.BCL0 & 0xFFFF)
            PBIF [0x06] = Local0
            PBIF [0x09] = "BAT"
            PBIF [0x0A] = "0001"
            PBIF [0x0B] = "LION"
            PBIF [0x0C] = "Notebook"
        }
        Else
        {
            IVBI ()
        }
    }

    Method (_BIF, 0, NotSerialized)  // _BIF: Battery Information
    {
        If (One)
        {
            UPBI ()
        }
        Else
        {
            IVBI ()
        }

        Return (PBIF) /* \_SB_.BAT0.PBIF */
    }

    Name (PBST, Package (0x04)
    {
        // State (0)
        Zero,
        // Present rate (1)
        0xFFFFFFFF,
        // Remaining capacity (2)
        0xFFFFFFFF,
        // Present voltage (3)
        0x3D90
    })
    Method (IVBS, 0, NotSerialized)
    {
        PBST [Zero] = Zero
        PBST [One] = 0xFFFFFFFF
        PBST [0x02] = 0xFFFFFFFF
        PBST [0x03] = 0x2710
    }

    Method (UPBS, 0, NotSerialized)
    {
        If (^^PCI0.LPCB.EC0.BAT0)
        {
            Local0 = Zero
            Local1 = Zero
            If (^^AC.ACFG)
            {
                If (((^^PCI0.LPCB.EC0.BST0 & 0x02) == 0x02))
                {
                    Local0 |= 0x02
                    Local1 = (^^PCI0.LPCB.EC0.BPR0 & 0xFFFF)
                }
            }
            Else
            {
                Local0 |= One
                Local1 = (^^PCI0.LPCB.EC0.BPR0 & 0xFFFF)
            }

            Local7 = (Local1 & 0x8000)
            If ((Local7 == 0x8000))
            {
                Local1 ^= 0xFFFF
            }

            Local2 = (^^PCI0.LPCB.EC0.BRC0 & 0xFFFF)
            Local3 = (^^PCI0.LPCB.EC0.BPV0 & 0xFFFF)
            PBST [Zero] = Local0
            PBST [One] = Local1
            PBST [0x02] = Local2
            PBST [0x03] = Local3
            If ((BFCC != ^^PCI0.LPCB.EC0.BFC0))
            {
                Notify (BAT0, 0x81) // Information Change
            }
        }
        Else
        {
            IVBS ()
        }
    }

    Method (_BST, 0, NotSerialized)  // _BST: Battery Status
    {
        If (One)
        {
            UPBS ()
        }
        Else
        {
            IVBS ()
        }

        Return (PBST) /* \_SB_.BAT0.PBST */
    }
}
