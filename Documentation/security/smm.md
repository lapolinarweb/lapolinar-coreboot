# x86 System Managment Mode

## Introduction

The System Managment Mode (SMM) provides firmware provided runtime services
to applications running in [ring0]. It has a higher privilegde level than
[ring0] and resides in the SMRAM region which cannot be access from [ring0].

The SMM can be entered by issueing System Managment Interupts (SMIs).

## Secure data exchange

In order to not leak SMM internals or accidently overwrite parts of the SMM,
[ring0] provided data (pointers, offsets, sizes, ...) must be checked  before
using them in SMM.

There exists two methods to verify data:

```C
/* Returns true if the region overlaps with the SMM */
bool smm_region_overlaps_handler(struct region *r);
```

```C
/* Returns true if the pointer points to the SMM handler. */
bool smm_validate_pointer(void *ptr);
```

[ring0]: https://en.wikipedia.org/wiki/Protection_ring
