ramstage-$(CONFIG_SMMSTORE) += store.c
ramstage-$(CONFIG_SMMSTOREV2) += ramstage.c

smm-$(CONFIG_SMMSTORE) += store.c smi.c
