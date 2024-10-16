#ifndef MODULES_H
#define MODULES_H

#include <ntifs.h>
#include <intrin.h>

#include "common.h"

typedef struct _APC_OPERATION_ID {
    int operation_id;

} APC_OPERATION_ID, *PAPC_OPERATION_ID;

/* system modules information */

typedef struct _SYSTEM_MODULES {
    PVOID address;
    INT module_count;

} SYSTEM_MODULES, *PSYSTEM_MODULES;

#define APC_CONTEXT_ID_STACKWALK 0x1
#define APC_CONTEXT_ID_STARTADDRESS 0x2

typedef struct _APC_CONTEXT_HEADER {
    LONG     context_id;
    volatile INT count;
    volatile INT allocation_in_progress;

} APC_CONTEXT_HEADER, *PAPC_CONTEXT_HEADER;

