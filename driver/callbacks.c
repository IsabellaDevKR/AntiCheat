#include "callbacks.h"

#include "containers/map.h"
#include "containers/tree.h"
#include "crypt.h"
#include "driver.h"
#include "imports.h"
#include "lib/stdlib.h"
#include "modules.h"
#include "pool.h"
#include "session.h"
#include "thread.h"
#include "util.h"

#define PROCESS_HASHMAP_BUCKET_COUNT 101

STATIC
BOOLEAN
EnumHandleCallback(
    _In_ PHANDLE_TABLE HandleTable,
    _In_ PHANDLE_TABLE_ENTRY Entry,
    _In_ HANDLE Handle,
    _In_ PVOID Context);

#ifdef ALLOC_PRAGMA
#    pragma alloc_text(PAGE, ObPostOpCallbackRoutine)
#    pragma alloc_text(PAGE, ObPreOpCallbackRoutine)
#    pragma alloc_text(PAGE, EnumHandleCallback)
#    pragma alloc_text(PAGE, EnumerateProcessHandles)
#    pragma alloc_text(PAGE, InitialiseThreadList)
#    pragma alloc_text(PAGE, ExUnlockHandleTableEntry)
#endif

VOID
CleanupThreadListFreeCallback(_In_ PTHREAD_LIST_ENTRY ThreadListEntry)
{
    ImpObDereferenceObject(ThreadListEntry->thread);
    ImpObDereferenceObject(ThreadListEntry->owning_process);
}

