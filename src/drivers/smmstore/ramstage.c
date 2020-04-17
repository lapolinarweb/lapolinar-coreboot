/* SPDX-License-Identifier: GPL-2.0-only */
/* This file is part of the coreboot project. */

#include <bootstate.h>
#include <cpu/x86/smm.h>
#include <commonlib/helpers.h>
#include <commonlib/region.h>
#include <console/console.h>
#include <smmstore.h>
#include <types.h>
#include <cbmem.h>

static struct smmstore_params_info info;

void lb_smmstorev2(struct lb_header *header)
{
	struct lb_record *rec;
	struct lb_smmstorev2 *store;

	if (!info.com_buffer)
		return;

	rec = lb_new_record(header);
	store = (struct lb_smmstorev2 *)rec;

	store->tag = LB_TAG_SMMSTOREV2;
	store->size = sizeof(*store);
	store->com_buffer = info.com_buffer;
	store->com_buffer_size = info.com_buffer_size;
	store->mmap_addr = info.mmap_addr;
	store->num_blocks = info.num_blocks;
	store->block_size = info.block_size;
	store->apm_cmd = APM_CNT_SMMSTORE;
}

static void init_store(void *unused)
{
	struct smmstore_params_init args;
	uint32_t eax = ~0;
	uint32_t ebx;

	printk(BIOS_INFO, "SMMSTORE: Initializing\n");

	if (smmstore_get_info(&info) < 0)
		return;

	void *ptr = cbmem_add(CBMEM_ID_SMM_COMBUFFER, SMM_BLOCK_SIZE);
	if (!ptr) {
		printk(BIOS_ERR, "SMMSTORE: Failed to add com buffer\n");
		return;
	}

	args.com_buffer = (uintptr_t)ptr;
	args.com_buffer_size = SMM_BLOCK_SIZE;
	ebx = (uintptr_t)&args;

	/* Call into SMM to update the com buffer and to lock the SMMSTORE */
	__asm__ __volatile__ (
		"outb %b0, $0xb2"
		: "=a" (eax)
		: "a" ((SMMSTORE_CMD_INIT << 8) | APM_CNT_SMMSTORE), "b" (ebx)
		: "memory");
	if (eax != SMMSTORE_RET_SUCCESS) {
		printk(BIOS_ERR, "SMMSTORE: Failed to install com buffer\n");
		return;
	}

	/* Fill in the com buffer send to SMM */
	info.com_buffer_size = args.com_buffer_size;
	info.com_buffer = args.com_buffer;
}

BOOT_STATE_INIT_ENTRY(BS_DEV_INIT, BS_ON_ENTRY, init_store, NULL);
