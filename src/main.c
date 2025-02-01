#include "ntexport.h"
#include "tools.h"
#include <minwindef.h>
#include <winnt.h>
#include <winternl.h>



/*

SERVICES TO DISABLE

\\Registry\\Machine\\SYSTEM\ControlSet001\Services\ProfSvc
\\Registry\\Machine\\SYSTEM\ControlSet001\Services\ShellHWDetection
\\Registry\\Machine\\SYSTEM\ControlSet001\Services\DoSvc
\\Registry\\Machine\\SYSTEM\ControlSet001\Services\DsmSvc
\\Registry\\Machine\\SYSTEM\ControlSet001\Services\BITS
\\Registry\\Machine\\SYSTEM\ControlSet001\Services\iphlpsvc
\\Registry\\Machine\\SYSTEM\ControlSet001\Services\MDCoreSvc
\\Registry\\Machine\\SYSTEM\ControlSet001\Services\CryptSvc
FILES AND DIRECTORIES TO DELETE

\??\C:\Windows\System32\smartscreen.exe
\??\C:\ProgramData\Microsoft\Windows Defender\*.*
\??\C:\Program Files (x86)\Microsoft\Edge

*/


   // 

void NtEntry(){
    BOOLEAN enabled;
    RtlAdjustPrivilege(SE_DEBUG_PRIVILEGE, TRUE, FALSE, &enabled);
    RtlAdjustPrivilege(SE_TAKE_OWNERSHIP_PRIVILEGE, TRUE, FALSE, &enabled);
    RtlAdjustPrivilege(SE_BACKUP_PRIVILEGE, TRUE, FALSE, &enabled);
    BOOL result;
    BOOL IsSuccess = TRUE;
    RtlDrawBootText(L"Disabling iphlpsvc");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\iphlpsvc");
    if(!result) IsSuccess = FALSE;
    RtlSleep(5000);
    RtlDrawBootText(L"Disabling ShellHWDetection");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\ShellHWDetection");
    if(!result) IsSuccess = FALSE;
    RtlSleep(5000);
    RtlDrawBootText(L"Disabling DoSvc");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\DoSvc");
    if(!result) IsSuccess = FALSE;
    RtlSleep(5000);
    RtlDrawBootText(L"Disabling DsmSvc");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\DsmSvc");
    if(!result) IsSuccess = FALSE;
    RtlSleep(5000);
    RtlDrawBootText(L"Disabling BITS");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\BITS");
    if(!result) IsSuccess = FALSE;
    RtlSleep(5000);
    // RtlDrawBootText(L"Disabling MDCoreSvc");
    // result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\MDCoreSvc");
    // if(!result) IsSuccess = FALSE;
    // RtlSleep(5000);
    RtlDrawBootText(L"Disabling CryptSvc");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\CryptSvc");
    if(!result) IsSuccess = FALSE;
    RtlSleep(5000);
    NTSTATUS status = RtlDeleteFile(L"\\??\\C:\\Windows\\System32\\smartscreen.exe");
    if(!NT_SUCCESS(status)){
        WCHAR* buf = RtlAllocateVirtualMemory(512);
        RtlStatusToString(status, buf);
        RtlDrawBootText(buf);
        RtlSleep(10000);
        RtlFreeVirtualMemory(buf, 512);
        IsSuccess = FALSE;
        //return FALSE;
    }
    if(IsSuccess) RtlDrawBootText(L"Success! Your PC Has Been Purified!");
    else RtlDrawBootText(L"Some Errors Happened, But Its Done");
    RtlSleep(10000);
}

