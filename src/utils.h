/* date = August 31st 2021 6:22 pm */
#ifndef UTILS_H
#define UTILS_H

#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <shlwapi.h>

// TODO(nihilo): Stop using stricmp, strcpy 
int Win32GetProcessDir(char* process_name, char* result)
{
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);
    
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    
    if (Process32First(snapshot, &entry) == TRUE)
    {
        while (Process32Next(snapshot, &entry) == TRUE)
        {
            if (stricmp(entry.szExeFile, process_name) == 0)
            {
                char path[512];
                CloseHandle(snapshot);
                HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);
                if(GetModuleFileNameExA(hProcess, NULL, path, sizeof(path) / sizeof(char)))
                {
                    if(PathRemoveFileSpecA(path))
                        strcpy(result, path);
                    CloseHandle(hProcess);
                    return 1;
                }
            }
        }
    }
    CloseHandle(snapshot);
    return 0;
}

#endif //UTILS_H
