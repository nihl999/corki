/* date = August 31st 2021 6:22 pm */
#ifndef UTILS_H
#define UTILS_H

#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <shlwapi.h>

char* CopyString(char* dest, char* src)
{
    if (dest == NULL) 
        return NULL;
    char *start = dest;
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return start;
}

int CompareString(char* left, char* right)
{
    while (*left)
    {
        if (*left != *right) {
            break;
        }
        
        left++;
        right++;
    }
    return *(unsigned char*)left - *(unsigned char*)right;
}

char* ConcatenateString(char* dest, char* src)
{
    int dest_start, src_start;
    
    for (dest_start = 0; dest[dest_start] != '\0'; dest_start++);
    
    for (src_start = 0; src[src_start] != '\0'; src_start++) {
        dest[dest_start + src_start] = src[src_start];
    }
    
    dest[dest_start + src_start] = '\0';
    return dest;
}

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
            if (CompareString(entry.szExeFile, process_name) == 0)
            {
                char path[512];
                CloseHandle(snapshot);
                HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);
                if(GetModuleFileNameExA(hProcess, NULL, path, sizeof(path) / sizeof(char)))
                {
                    if(PathRemoveFileSpecA(path))
                        CopyString(result, path);
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
