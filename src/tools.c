#include "tools.h"
#include "ntexport.h"
#include <winnt.h>
#include <winternl.h>





NTSTATUS RtlSleep(int milliseconds) {
    LARGE_INTEGER delay;
    delay.QuadPart = -((LONGLONG)milliseconds * 10000);
    return NtDelayExecution(FALSE, &delay);
}

void RtlDrawBootText(PCWSTR string){
    UNICODE_STRING ustring;
    RtlInitUnicodeString(&ustring, string);
    NtDrawText(&ustring);
}


NTSTATUS RtlDeleteFile(PCWSTR string){
    UNICODE_STRING ustring;
    RtlInitUnicodeString(&ustring, string);
    OBJECT_ATTRIBUTES oAttributes;
    InitializeObjectAttributes(&oAttributes, &ustring, OBJ_CASE_INSENSITIVE, NULL, NULL);
    return NtDeleteFile(&oAttributes);
}


HANDLE RtlOpenRegistryKey(PCWSTR key, NTSTATUS* status){
    UNICODE_STRING ustring;
    RtlInitUnicodeString(&ustring, key);
    OBJECT_ATTRIBUTES oAttributes;
    InitializeObjectAttributes(&oAttributes, &ustring, OBJ_CASE_INSENSITIVE, NULL, NULL);
    HANDLE hKey;
    *status = NtOpenKey(&hKey, GENERIC_READ | GENERIC_WRITE, &oAttributes);
    return hKey;
}



NTSTATUS RtlSetRegistryValue(HANDLE keyHandle, PCWSTR ValueName, ULONG type, PVOID data, ULONG datasize){
    UNICODE_STRING ustring;
    RtlInitUnicodeString(&ustring, ValueName);
    return NtSetValueKey(keyHandle, &ustring, 0, type, data, datasize);
}

NTSTATUS RtlCreateRegistryValue(PCWSTR key){
    HANDLE hKey;
    UNICODE_STRING ustring;
    RtlInitUnicodeString(&ustring, key);
    OBJECT_ATTRIBUTES oAttributes;
    InitializeObjectAttributes(&oAttributes, &ustring, OBJ_CASE_INSENSITIVE, NULL, NULL);
    ULONG disp;
    NTSTATUS status = NtCreateKey(hKey, KEY_SET_VALUE | KEY_CREATE_LINK, &oAttributes, 0, NULL, REG_OPTION_NON_VOLATILE, &disp);
    NtClose(hKey);
    return status;
}

BOOL RtlDisableServicesViaTheRegistry(PCWSTR key){
    NTSTATUS status;
    HANDLE hKey = RtlOpenRegistryKey(key, &status);
    if(!NT_SUCCESS(status)){
        RtlDrawBootText(L"Failed to Open Key, Continuing");
        RtlSleep(10000);
        return FALSE;
    }
    DWORD num = 4;
    status = RtlSetRegistryValue(hKey, L"Start", REG_DWORD, &num, sizeof(DWORD));
    if(!NT_SUCCESS(status)){
        WCHAR* buf = RtlAllocateVirtualMemory(512);
        RtlStatusToString(status, buf);
        RtlDrawBootText(buf);
        RtlSleep(10000);
        NtClose(hKey);
        RtlFreeVirtualMemory(buf, 512);
        return FALSE;
    }
    NtClose(hKey);
    return TRUE;
}

//autocheck autochk *

WCHAR* RtlStatusToString(NTSTATUS status, WCHAR* str) {
    const int HEX_BASE = 16;
    const WCHAR* HEX_DIGITS = L"0123456789ABCDEF";
    int i = 0;
    str[i++] = L'0';
    str[i++] = L'x';
    for (int shift = 28; shift >= 0; shift -= 4) {
        int nibble = (status >> shift) & 0xF; 
        str[i++] = HEX_DIGITS[nibble];
    }
    str[i] = L'\0';
    return str;
}


void* RtlAllocateVirtualMemory(size_t size) {
    void* baseAddress = NULL;
    NTSTATUS status = NtAllocateVirtualMemory(
        NtCurrentProcess(),  
        &baseAddress,        
        0,                   
        &size,         
        MEM_RESERVE | MEM_COMMIT, 
        PAGE_READWRITE 
    );
    if (!NT_SUCCESS(status)) {
        return NULL;
    }
    return baseAddress;
}

BOOL RtlFreeVirtualMemory(void* address, size_t size) {
    NTSTATUS status = NtFreeVirtualMemory(
        NtCurrentProcess(), 
        &address, 
        &size, 
        MEM_RELEASE
    );
    if (!NT_SUCCESS(status)) {
        return FALSE;
    }
    return TRUE;
}

NTSTATUS RtlLoadKey(PCWSTR TargetKey, PCWSTR file){
    UNICODE_STRING TargetKeyUnicodeString;
    RtlInitUnicodeString(&TargetKeyUnicodeString, TargetKey);
    OBJECT_ATTRIBUTES TargetKeyObject;
    InitializeObjectAttributes(&TargetKeyObject, &TargetKeyUnicodeString, OBJ_CASE_INSENSITIVE, NULL, NULL);
    UNICODE_STRING FileKeyUnicodeString;
    RtlInitUnicodeString(&FileKeyUnicodeString, file);
    OBJECT_ATTRIBUTES FileKeyObject;
    InitializeObjectAttributes(&FileKeyObject, &FileKeyUnicodeString, OBJ_CASE_INSENSITIVE, NULL, NULL);
    return NtLoadKey(&TargetKeyObject, &FileKeyObject);
}


NTSTATUS RtlUnloadKey(PCWSTR TargetKey){
    UNICODE_STRING TargetKeyUnicodeString;
    RtlInitUnicodeString(&TargetKeyUnicodeString, TargetKey);
    OBJECT_ATTRIBUTES TargetKeyObject;
    InitializeObjectAttributes(&TargetKeyObject, &TargetKeyUnicodeString, OBJ_CASE_INSENSITIVE, NULL, NULL);
    return NtUnloadKey(&TargetKeyObject);
}