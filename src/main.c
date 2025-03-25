#include "ntexport.h"
#include "tools.h"
#include <minwindef.h>
#include <winnt.h>
#include <winternl.h>



/*

    SERVICES TO DISABLE

    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\ProfSvc - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\ShellHWDetection - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\DoSvc - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\DsmSvc - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\BITS - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\iphlpsvc - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\MDCoreSvc - NOT DONE (STATUS_ACCESS_DENIED)
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\CryptSvc - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\PushToInstall - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\DiagTrack - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\WinDefend - NOT DONE (STATUS_ACCESS_DENIED)
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\lfsvc - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\TokenBroker - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\UsoSvc - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\wlidsvc - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\WaaSMedicSvc - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\wuauserv - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\wisvc - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\DPS - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\mpssvc - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\diagnosticshub.standardcollector.service - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\diagsvc - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\LicenseManager - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\WdiServiceHost - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\WdiSystemHost - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\ClipSVC - DONE
    \\Registry\\Machine\\SYSTEM\ControlSet001\Services\SecurityHealthService - DONE
    FILES AND DIRECTORIES TO DELETE

    \??\C:\Windows\System32\smartscreen.exe - NOT DONE (STATUS_ACCESS_DENIED)
    \??\C:\ProgramData\Microsoft\Windows Defender\*.* - NOT DONE
    \??\C:\Program Files (x86)\Microsoft\Edge - NOT DONE

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
    RtlSleep(2000);
    RtlDrawBootText(L"Disabling ShellHWDetection");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\ShellHWDetection");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    RtlDrawBootText(L"Disabling DoSvc");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\DoSvc");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    RtlDrawBootText(L"Disabling DsmSvc");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\DsmSvc");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    RtlDrawBootText(L"Disabling BITS");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\BITS");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    RtlDrawBootText(L"Disabling DiagTrack");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\DiagTrack");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    // RtlDrawBootText(L"Disabling WinDefend");
    // result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\WinDefend");
    // if(!result) IsSuccess = FALSE;
    // RtlSleep(2000);
    RtlDrawBootText(L"Disabling lfsvc");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\lfsvc");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    RtlDrawBootText(L"Disabling TokenBroker");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\TokenBroker");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    RtlDrawBootText(L"Disabling UsoSvc");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\UsoSvc");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    RtlDrawBootText(L"Disabling wlidsvc");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\wlidsvc");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    RtlDrawBootText(L"Disabling WaaSMedicSvc");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\WaaSMedicSvc");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    RtlDrawBootText(L"Disabling wuauserv");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\wuauserv");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    RtlDrawBootText(L"Disabling wisvc");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\wisvc");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    RtlDrawBootText(L"Disabling DPS");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\DPS");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    RtlDrawBootText(L"Disabling mpssvc");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\mpssvc");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    RtlDrawBootText(L"Disabling diagnosticshub.standardcollector.service");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\diagnosticshub.standardcollector.service");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    RtlDrawBootText(L"Disabling diagsvc");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\diagsvc");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    RtlDrawBootText(L"Disabling LicenseManager");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\LicenseManager");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    RtlDrawBootText(L"Disabling WdiServiceHost");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\WdiServiceHost");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    RtlDrawBootText(L"Disabling WdiSystemHost");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\WdiSystemHost");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    // RtlDrawBootText(L"Disabling MDCoreSvc");
    // result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\MDCoreSvc");
    // if(!result) IsSuccess = FALSE;
    // RtlSleep(2000);
    RtlDrawBootText(L"Disabling PushToInstall");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\PushToInstall");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    RtlDrawBootText(L"Disabling CryptSvc");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\CryptSvc");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    RtlDrawBootText(L"Disabling ClipSVC");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\ClipSVC");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    RtlDrawBootText(L"Disabling SecurityHealthService");
    result = RtlDisableServicesViaTheRegistry(L"\\Registry\\Machine\\SYSTEM\\ControlSet001\\Services\\SecurityHealthService");
    if(!result) IsSuccess = FALSE;
    RtlSleep(2000);
    // RtlDrawBootText(L"Deleting SmartScreen");
    // NTSTATUS status = RtlDeleteFile(L"\\??\\C:\\Windows\\System32\\smartscreen.exe");
    // if(!NT_SUCCESS(status)){
    //     WCHAR* buf = RtlAllocateVirtualMemory(512);
    //     RtlStatusToString(status, buf);
    //     RtlDrawBootText(buf);
    //     RtlSleep(10000);
    //     RtlFreeVirtualMemory(buf, 512);
    //     IsSuccess = FALSE;
    //     //return FALSE;
    // }
    //RtlSleep(2000);
    if(IsSuccess) RtlDrawBootText(L"Success! Your PC Has Been Purified!");
    else RtlDrawBootText(L"Some Errors Happened, But Its Done");
    RtlSleep(10000);
}

