## features

- Attached thread detection
- Process module .text section integrity checks
- NMI stackwalking via isr iretq
- APC, DPC stackwalking
- Return address exception hooking detection
- Chained .data pointer detection (iffy)
- Handle stripping via obj callbacks
- Process handle table enumeration
- System module device object verification
- System module .text integrity checks
- Removal of threads cid table entry detection
- Driver dispatch routine validation
- Extraction of various hardware identifiers
- EPT hook detection
- Various image integrity checks both of driver + module
- Hypervisor detection
- HalDispatch and HalPrivateDispatch routine validation
- Dynamic import resolving & encryption
- Malicious PCI device detection via configuration space scanning
- Win32kBase_DxgInterface routine validation

# architecuture

- todo!

# how to configure kernel debugging output

The kernel driver is setup to log at 4 distinct levels:

```C
#define LOG_ERROR_LEVEL  
#define LOG_WARNING_LEVEL
#define LOG_INFO_LEVEL   
#define LOG_VERBOSE_LEVEL
```

As the names suggest, `ERROR_LEVEL` is for errors, `WARNING_LEVEL` is for warnings. `INFO_LEVEL` is for general information regarding what requests the driver is processing and `VERBOSE_LEVEL` contains very detailed information for each request.

## creating the registry key

If you are unfamiliar with the kernel debugging mask, you probably need to set one up. If you already have a debugging mask setup, you can skip to `setting the mask` below.

1. Open the Registry Editor
2. Copy and pase `Computer\HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager` into the bar at the top and press enter
3. On the left hand side, right click `Session Manager` and select `New -> Key`
4. Name the key `Debug Print Filter`
5. On the left hand side you should now see `Debug Print Filter`, right click and select `New -> DWORD (32 bit) Value`
6. Name the key `DEFAULT`


## setting the mask

1. Within the `Debug Print Filter` registry, double click the key named `DEFAULT`
2. Determine the level(s) of logging you would like to see. For most people interested I would set either `INFO_LEVEL` or `VERBOSE_LEVEL`. Remember that if you set `INFO_LEVEL`, you will see all `INFO_LEVEL`, `WARNING_LEVEL` and `ERROR_LEVEL` logs. Ie you see all logs above and including your set level.

```
ERROR_LEVEL    = 0x3
WARNING_LEVEL  = 0x7
INFO_LEVEL     = 0xf
VERBOSE_LEVEL  = 0x1f
```

3. Enter the value for the given logging level (seen above)
4. Click `Ok` and restart Windows.

## filtering debug output

If you choose to use `INFO_LEVEL` or `VERBOSE_LEVEL` there may be many logs from the kernel so we want to filter them out.
