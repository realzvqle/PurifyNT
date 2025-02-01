#ifndef NTEXPORT_H_INCLUDED
#define NTEXPORT_H_INCLUDED





#define _AMD64_
#include <minwindef.h>
#include <winternl.h>


#define SE_CREATE_TOKEN_PRIVILEGE       (2L)
#define SE_ASSIGNPRIMARYTOKEN_PRIVILEGE (3L)
#define SE_LOCK_MEMORY_PRIVILEGE        (4L)
#define SE_INCREASE_QUOTA_PRIVILEGE     (5L)
#define SE_UNSOLICITED_INPUT_PRIVILEGE  (6L)
#define SE_MACHINE_ACCOUNT_PRIVILEGE    (7L)
#define SE_TCB_PRIVILEGE                (8L)
#define SE_SECURITY_PRIVILEGE           (9L)
#define SE_TAKE_OWNERSHIP_PRIVILEGE     (10L)
#define SE_LOAD_DRIVER_PRIVILEGE        (10L)
#define SE_SYSTEM_PROFILE_PRIVILEGE     (11L)
#define SE_SYSTEMTIME_PRIVILEGE         (12L)
#define SE_PROF_SINGLE_PROCESS_PRIVILEGE (13L)
#define SE_INC_BASE_PRIORITY_PRIVILEGE  (14L)
#define SE_CREATE_PAGEFILE_PRIVILEGE    (15L)
#define SE_CREATE_PERMANENT_PRIVILEGE   (16L)
#define SE_BACKUP_PRIVILEGE             (17L)
#define SE_RESTORE_PRIVILEGE            (18L)
#define SE_SHUTDOWN_PRIVILEGE           (19L)
#define SE_DEBUG_PRIVILEGE              (20L)
#define SE_AUDIT_PRIVILEGE              (21L)
#define SE_SYSTEM_ENVIRONMENT_PRIVILEGE (22L)
#define SE_CHANGE_NOTIFY_PRIVILEGE      (23L)
#define SE_REMOTE_SHUTDOWN_PRIVILEGE    (24L)

extern NTSYSCALLAPI
NTSTATUS
NTAPI
NtDrawText(
    _In_ PUNICODE_STRING Text
);

extern NTSYSCALLAPI
NTSTATUS
NTAPI
NtDeleteFile(
    _In_ POBJECT_ATTRIBUTES ObjectAttributes
);

extern NTSYSCALLAPI
NTSTATUS
NTAPI
NtDelayExecution(
    _In_ BOOLEAN Alertable,
    _In_ PLARGE_INTEGER DelayInterval
);

extern NTSYSCALLAPI
NTSTATUS
NTAPI
NtOpenKey(
    _Out_ PHANDLE KeyHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes
);

extern NTSYSCALLAPI
NTSTATUS
NTAPI
NtSetValueKey(
    _In_ HANDLE KeyHandle,
    _In_ PUNICODE_STRING ValueName,
    _In_opt_ ULONG TitleIndex,
    _In_ ULONG Type,
    _In_reads_bytes_opt_(DataSize) PVOID Data,
    _In_ ULONG DataSize
);

extern NTSYSCALLAPI
NTSTATUS
NTAPI
NtCreateKey(
    _Out_ PHANDLE KeyHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes,
    _Reserved_ ULONG TitleIndex,
    _In_opt_ PUNICODE_STRING Class,
    _In_ ULONG CreateOptions,
    _Out_opt_ PULONG Disposition
);

extern NTSYSAPI
NTSTATUS
NTAPI
RtlAdjustPrivilege(
    _In_ ULONG Privilege,
    _In_ BOOLEAN Enable,
    _In_ BOOLEAN Client,
    _Out_ PBOOLEAN WasEnabled
);

extern NTSYSCALLAPI
NTSTATUS
NTAPI
NtAllocateVirtualMemory(
    _In_ HANDLE ProcessHandle,
    _Inout_ _At_(*BaseAddress, _Readable_bytes_(*RegionSize) _Writable_bytes_(*RegionSize) _Post_readable_byte_size_(*RegionSize)) PVOID *BaseAddress,
    _In_ ULONG_PTR ZeroBits,
    _Inout_ PSIZE_T RegionSize,
    _In_ ULONG AllocationType,
    _In_ ULONG PageProtection
);

extern NTSYSCALLAPI
NTSTATUS
NTAPI
NtFreeVirtualMemory(
    _In_ HANDLE ProcessHandle,
    _Inout_ PVOID *BaseAddress,
    _Inout_ PSIZE_T RegionSize,
    _In_ ULONG FreeType
);


extern NTSYSCALLAPI
NTSTATUS
NTAPI
NtLoadKey(
    _In_ POBJECT_ATTRIBUTES TargetKey,
    _In_ POBJECT_ATTRIBUTES SourceFile
);

extern NTSYSCALLAPI
NTSTATUS
NTAPI
NtUnloadKey(
    _In_ POBJECT_ATTRIBUTES TargetKey
);

typedef enum _SHUTDOWN_ACTION
{
    ShutdownNoReboot,
    ShutdownReboot,
    ShutdownPowerOff,
    ShutdownRebootForRecovery 
} SHUTDOWN_ACTION;

extern NTSYSCALLAPI
NTSTATUS
NTAPI
NtShutdownSystem(
    _In_ SHUTDOWN_ACTION Action
);
#define NtCurrentProcess() ((HANDLE)(LONG_PTR)-1)



#endif