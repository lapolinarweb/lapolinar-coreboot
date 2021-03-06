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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 */

#ifndef MAINBOARD_GPIO_H
#define MAINBOARD_GPIO_H

#include <soc/gpe.h>
#include <soc/gpio.h>

#ifndef __ACPI__

// Pad configuration in ramstage
static const struct pad_config gpio_table[] = {
// GPD
	// System Power Management
		// PM_BATLOW#
		PAD_CFG_NC(GPD0),
		// AC_PRESENT
		PAD_CFG_NF(GPD1, NONE, DEEP, NF1),
		// LAN_WAKEUP#
		_PAD_CFG_STRUCT(GPD2, 0x880500, 0x0),
		// PWR_BTN#
		PAD_CFG_NF(GPD3, UP_20K, DEEP, NF1),
		// SUSB#_PCH
		PAD_CFG_NF(GPD4, NONE, DEEP, NF1),
		// SUSC#_PCH
		PAD_CFG_NF(GPD5, NONE, DEEP, NF1),
		// SLP_A#
		PAD_CFG_NF(GPD6, NONE, DEEP, NF1),
		// NC
		PAD_CFG_NC(GPD7),
		// SUSCLK
		PAD_CFG_NF(GPD8, NONE, DEEP, NF1),
		// PCH_SLP_WLAN#
		PAD_CFG_NF(GPD9, NONE, DEEP, NF1),
		// SLP_S5#
		PAD_CFG_NC(GPD10),
		// PCH_GPD11
		PAD_CFG_NC(GPD11),

// GPP_A
	// LPC
		// TODO - SB_KBCRST#
		PAD_CFG_NF(GPP_A0, NONE, DEEP, NF1),
		// LPC_AD0
		PAD_CFG_NF(GPP_A1, NONE, DEEP, NF1),
		// LPC_AD1
		PAD_CFG_NF(GPP_A2, NONE, DEEP, NF1),
		// LPC_AD2
		PAD_CFG_NF(GPP_A3, NONE, DEEP, NF1),
		// LPC_AD3
		PAD_CFG_NF(GPP_A4, NONE, DEEP, NF1),
		// LPC_FRAME#
		PAD_CFG_NF(GPP_A5, NONE, DEEP, NF1),
		// SERIRQ
		PAD_CFG_NF(GPP_A6, NONE, DEEP, NF1),

	// PCIE/USB3/SATA
		// G_INT1
		PAD_CFG_NC(GPP_A7),

	// LPC
		// PM_CLKRUN#
		PAD_CFG_NF(GPP_A8, NONE, DEEP, NF1),
		// PCLK_KBC
		PAD_CFG_NF(GPP_A9, NONE, DEEP, NF1),
		// PCLK_TPM
		PAD_CFG_NF(GPP_A10, DN_20K, DEEP, NF1),

	// System Power Management
		// TODO - LAN_WAKEUP#
		PAD_CFG_NC(GPP_A11),

	// ISH
		// PCH_GPP_A12
		PAD_CFG_NC(GPP_A12),

	// System Power Management
		// SUSWARN#
		PAD_CFG_NF(GPP_A13, NONE, DEEP, NF1),

	// LPC
		// S4_STATE#
		PAD_CFG_NF(GPP_A14, NONE, DEEP, NF1),

	// System Power Management
		// SUSACK#
		PAD_CFG_NF(GPP_A15, NONE, DEEP, NF1),

	// SDIO/SDXC
		// NC
		PAD_CFG_NC(GPP_A16),
		// NC
		PAD_CFG_NC(GPP_A17),

	// ISH
		// TBTA_ACE_GPIO3
		PAD_CFG_TERM_GPO(GPP_A18, 1, NONE, DEEP),
		// SATA_PWR_EN
		PAD_CFG_GPO(GPP_A19, 1, DEEP),
		// TBTA_ACE_GPIO0
		PAD_CFG_TERM_GPO(GPP_A20, 0, NONE, DEEP),
		// TBT_FRC_PWR
		PAD_CFG_TERM_GPO(GPP_A21, 1, DN_20K, PLTRST),
		// PS8338B_SW
		PAD_CFG_TERM_GPO(GPP_A22, 0, NONE, PWROK),
		// PS8338B_PCH
		PAD_CFG_TERM_GPO(GPP_A23, 0, NONE, PWROK),

// GPP_B
	// CPU Power
		// CORE_VID0
		PAD_CFG_NF(GPP_B0, NONE, DEEP, NF1),
		// CORE_VID1
		PAD_CFG_NF(GPP_B1, NONE, DEEP, NF1),

	// System Power Management
		// VRALERT#
		PAD_CFG_NC(GPP_B2),

	// CPU Misc
		// NC
		PAD_CFG_NC(GPP_B3),
		// NC
		PAD_CFG_NC(GPP_B4),

	// Clock Signals
		// PCIECLKRQ0#
		PAD_CFG_NC(GPP_B5),
		// PCIECLKRQ1#
		PAD_CFG_NC(GPP_B6),
		// WLAN_CLKREQ#
		PAD_CFG_NF(GPP_B7, NONE, DEEP, NF1),
		// LAN_CLKREQ#
		PAD_CFG_NF(GPP_B8, NONE, DEEP, NF1),
		// TBT_CLKREQ#
		PAD_CFG_NF(GPP_B9, NONE, DEEP, NF1),
		// SSD_CLKREQ#
		PAD_CFG_NF(GPP_B10, NONE, DEEP, NF1),

	// System Power Management
		// NC
		PAD_CFG_NC(GPP_B11),
		// SLP_S0#
		PAD_CFG_NC(GPP_B12),
		// PLTRST#
		PAD_CFG_NF(GPP_B13, NONE, DEEP, NF1),

	// Audio - SPKR
		// PCH_SPKR
		PAD_CFG_NF(GPP_B14, DN_20K, DEEP, NF1),

	// LPSS
		// PCH_GPP_B15
		PAD_CFG_NC(GPP_B15),
		// PCH_GPP_B16
		PAD_CFG_NC(GPP_B16),
		// PCH_GPP_B17
		PAD_CFG_NC(GPP_B17),
		// GSPI0_BBS0 - No Reboot strap
		PAD_CFG_NC(GPP_B18),
		// PCH_GPP_B19
		PAD_CFG_NC(GPP_B19),
		// PCH_GPP_B20
		PAD_CFG_NC(GPP_B20),
		// PCH_GPP_B21
		PAD_CFG_NC(GPP_B21),
		// PCH_GPP_B22 - Boot BIOS strap
		PAD_CFG_NC(GPP_B22),

	// SMBUS
		// PCH_GPP_B23
		PAD_CFG_NC(GPP_B23),

// GPP_C
	// SMBUS
		// SMB_CLK
		PAD_CFG_NF(GPP_C0, NONE, DEEP, NF1),
		// SMB_DATA
		PAD_CFG_NF(GPP_C1, NONE, DEEP, NF1),
		// PCH_GPP_C2
		PAD_CFG_NC(GPP_C2),
		// SML0CLK
		PAD_CFG_NC(GPP_C3),
		// SML0DATA
		PAD_CFG_NC(GPP_C4),
		// PCH_GPP_C5
		PAD_CFG_NC(GPP_C5),
		// SML1CLK
		PAD_CFG_NC(GPP_C6),
		// SML1DATA
		PAD_CFG_NC(GPP_C7),

	// LPSS
		// NC
		PAD_CFG_NC(GPP_C8),
		// NC
		PAD_CFG_NC(GPP_C9),
		// NC
		PAD_CFG_NC(GPP_C10),
		// NC
		PAD_CFG_NC(GPP_C11),

	// ISH
		// TBTA_ACE_GPIO2
		PAD_CFG_NC(GPP_C12),
		// TBCIO_PLUG_EVENT
		_PAD_CFG_STRUCT(GPP_C13, 0x82880100, 0x0000),
		// TBTA_MRESET
		PAD_CFG_NC(GPP_C14),
		// TBTA_ACE_GPIO7
		PAD_CFG_NC(GPP_C15),

	// LPSS
		// T_SDA
		PAD_CFG_NC(GPP_C16),
		// T_SCL
		PAD_CFG_NC(GPP_C17),
		// NC
		PAD_CFG_NC(GPP_C18),
		// SWI#
		_PAD_CFG_STRUCT(GPP_C19, 0x40880100, 0x0000),
		// UART2_RXD
		PAD_CFG_NF(GPP_C20, NONE, DEEP, NF1),
		// UART2_TXD
		PAD_CFG_NF(GPP_C21, NONE, DEEP, NF1),
		// UEART2_RTS_N
		PAD_CFG_NF(GPP_C22, NONE, DEEP, NF1),
		// UART2_CTS_N
		PAD_CFG_NF(GPP_C23, NONE, DEEP, NF1),

// GPP_D
	// SPI - Touch
		// NC
		PAD_CFG_NC(GPP_D0),
		// NC
		PAD_CFG_NC(GPP_D1),
		// NC
		PAD_CFG_NC(GPP_D2),
		// NC
		PAD_CFG_NC(GPP_D3),

	// NC
	PAD_CFG_NC(GPP_D4),

	// ISH
		// NC
		PAD_CFG_NC(GPP_D5),
		// NC
		PAD_CFG_NC(GPP_D6),
		// NC
		PAD_CFG_NC(GPP_D7),
		// SB_BLON
		PAD_CFG_GPO(GPP_D8, 1, DEEP),
		// T_INT
		PAD_CFG_NC(GPP_D9),
		// EDP_DET
		PAD_CFG_NC(GPP_D10),
		// NC
		PAD_CFG_NC(GPP_D11),
		// NC
		PAD_CFG_NC(GPP_D12),
		// NC
		PAD_CFG_NC(GPP_D13),
		// NC
		PAD_CFG_NC(GPP_D14),
		// NC
		PAD_CFG_NC(GPP_D15),
		// NC
		PAD_CFG_NC(GPP_D16),

	// Audio - DMIC
		// NC
		PAD_CFG_NC(GPP_D17),
		// NC
		PAD_CFG_NC(GPP_D18),
		// NC
		PAD_CFG_NC(GPP_D19),
		// NC
		PAD_CFG_NC(GPP_D20),

	// SPI - Touch
		// TPM_DET#
		PAD_CFG_NC(GPP_D21),
		// NC
		PAD_CFG_NC(GPP_D22),

	// Audio - I2S
		// NC
		PAD_CFG_NC(GPP_D23),

// GPP_E
	// SATAXPCIE
		// PCH_GPP_E0
		PAD_CFG_NC(GPP_E0),
		// SATA_ODD_PRSNT#
		PAD_CFG_NF(GPP_E1, NONE, DEEP, NF1),
		// SATAGP2
		PAD_CFG_NF(GPP_E2, NONE, DEEP, NF1),

	// CPU Misc
		// NC
		PAD_CFG_NC(GPP_E3),

	// DEVSLP
		// DEVSLP0
		PAD_CFG_NC(GPP_E4),
		// DEVSLP1
		PAD_CFG_NC(GPP_E5),
		// DEVSLP2
		PAD_CFG_NF(GPP_E6, NONE, DEEP, NF1),

	// CPU Misc
		// NC
		PAD_CFG_NC(GPP_E7),

	// USB2
		// PCH_SATA_LED#
		PAD_CFG_NF(GPP_E8, NONE, DEEP, NF1),
		// USB_OC#12
		PAD_CFG_NC(GPP_E9),
		// USB_OC#34
		PAD_CFG_NC(GPP_E10),
		// USB_OC#56
		PAD_CFG_NC(GPP_E11),
		// USB_OC#78
		PAD_CFG_NC(GPP_E12),

	// Display Sidebands
		// MUX_HPD
		PAD_CFG_NF(GPP_E13, NONE, DEEP, NF1),
		// HDMI_HPD
		PAD_CFG_NF(GPP_E14, NONE, DEEP, NF1),
		// SMI#
		_PAD_CFG_STRUCT(GPP_E15, 0x42840100, 0x0),
		// SCI#
		PAD_CFG_GPI_SCI_LOW(GPP_E16, NONE, DEEP, LEVEL),
		// EDP_HPD
		PAD_CFG_NF(GPP_E17, NONE, DEEP, NF1),
		// MDP_CTRLCLK
		PAD_CFG_NF(GPP_E18, NONE, DEEP, NF1),
		// MDP_CTRLDATA
		PAD_CFG_NF(GPP_E19, DN_20K, DEEP, NF1),
		// HDMI_CTRLCLK
		PAD_CFG_NF(GPP_E20, NONE, DEEP, NF1),
		// HDMI_CTRLDATA
		PAD_CFG_NF(GPP_E21, DN_20K, DEEP, NF1),
		// NC
		PAD_CFG_NC(GPP_E22),
		// NC
		PAD_CFG_NC(GPP_E23),

// GPP_F
	// Audio - I2S
		// NC
		PAD_CFG_NC(GPP_F0),
		// NC
		PAD_CFG_NC(GPP_F1),
		// NC
		PAD_CFG_NC(GPP_F2),
		// NC
		PAD_CFG_NC(GPP_F3),

	// LPSS
		// NC
		PAD_CFG_NC(GPP_F4),
		// NC
		PAD_CFG_NC(GPP_F5),
		// NC
		PAD_CFG_NC(GPP_F6),
		// NC
		PAD_CFG_NC(GPP_F7),
		// NC
		PAD_CFG_NC(GPP_F8),
		// NC
		PAD_CFG_NC(GPP_F9),

	// ISH
		// NC
		PAD_CFG_NC(GPP_F10),
		// NC
		PAD_CFG_NC(GPP_F11),

	// EMMC
		// NC
		PAD_CFG_NC(GPP_F12),
		// NC
		PAD_CFG_NC(GPP_F13),
		// NC
		PAD_CFG_NC(GPP_F14),
		// NC
		PAD_CFG_NC(GPP_F15),
		// NC
		PAD_CFG_NC(GPP_F16),
		// NC
		PAD_CFG_NC(GPP_F17),
		// NC
		PAD_CFG_NC(GPP_F18),
		// NC
		PAD_CFG_NC(GPP_F19),
		// NC
		PAD_CFG_NC(GPP_F20),
		// NC
		PAD_CFG_NC(GPP_F21),
		// NC
		PAD_CFG_NC(GPP_F22),

	// SDIO/SDXC
		// LIGHT_KB_DET#
		PAD_CFG_NC(GPP_F23),

// GPP_G
	// SDIO/SDXC
		// NC
		PAD_CFG_NC(GPP_G0),
		// TBT Detect
		PAD_CFG_NC(GPP_G1),
		// NC
		PAD_CFG_NC(GPP_G2),
		// ASM1543_I_SEL0
		PAD_CFG_NC(GPP_G3),
		// ASM1543_I_SEL1
		PAD_CFG_NC(GPP_G4),
		// NC
		PAD_CFG_NC(GPP_G5),
		// NC
		PAD_CFG_NC(GPP_G6),
		// NC
		PAD_CFG_NC(GPP_G7),
};

// Early pad configuration in romstage
static const struct pad_config early_gpio_table[] = {
	// LPSS
		// UART2_RXD
		PAD_CFG_NF(GPP_C20, NONE, DEEP, NF1),
		// UART2_TXD
		PAD_CFG_NF(GPP_C21, NONE, DEEP, NF1),
};

#endif

#endif
