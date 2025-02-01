@echo off



cl /c src/*.c
link *.obj ntdll.lib /SUBSYSTEM:NATIVE /ENTRY:NtEntry /OUT:shell.exe
del *.obj