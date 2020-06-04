// okay this is quite useless unless you know how to code in the slightest. If you want to use kdmapper and your driver is making you bsod. All you have
// to do is build it into this src

#include <ntddk.h>
#include "stdafx.h"

NTSTATUS DriverEntry(_In_  struct _DRIVER_OBJECT *DriverObject, _In_  PUNICODE_STRING RegistryPath)
{
    PEPROCESS Process;
    KIRQL Irql;
    PWSTR sIrql;

    UNREFERENCED_PARAMETER(DriverObject);
    UNREFERENCED_PARAMETER(RegistryPath);

    Irql = KeGetCurrentIrql();

    switch (Irql) {

    case PASSIVE_LEVEL:
        sIrql = L"PASSIVE_LEVEL";
        break;
    case APC_LEVEL:
        sIrql = L"APC_LEVEL";
        break;
    case DISPATCH_LEVEL:
        sIrql = L"DISPATCH_LEVEL";
        break;
    case CMCI_LEVEL:
        sIrql = L"CMCI_LEVEL";
        break;
    case CLOCK_LEVEL:
        sIrql = L"CLOCK_LEVEL";
        break;
    case IPI_LEVEL:
        sIrql = L"IPI_LEVEL";
        break;
    case HIGH_LEVEL:
        sIrql = L"HIGH_LEVEL";
        break;
    default:
        sIrql = L"Unknown Value";
        break;
    }
	return Main();
    return STATUS_SUCCESS;
}
