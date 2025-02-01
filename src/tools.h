#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED





#include "ntexport.h"



NTSTATUS RtlSleep(int milliseconds);
void RtlDrawBootText(PCWSTR string);
NTSTATUS RtlDeleteFile(PCWSTR string);
HANDLE RtlOpenRegistryKey(PCWSTR key, NTSTATUS* status);
NTSTATUS RtlSetRegistryValue(HANDLE keyHandle, PCWSTR ValueName, ULONG type, PVOID data, ULONG datasize);
BOOL RtlDisableServicesViaTheRegistry(PCWSTR key);
NTSTATUS RtlCreateRegistryValue(PCWSTR key);
WCHAR* RtlStatusToString(NTSTATUS status, WCHAR* str);
void* RtlAllocateVirtualMemory(size_t size);
BOOL RtlFreeVirtualMemory(void* address, size_t size);
NTSTATUS RtlLoadKey(PCWSTR TargetKey, PCWSTR file);
NTSTATUS RtlUnloadKey(PCWSTR TargetKey);
#endif