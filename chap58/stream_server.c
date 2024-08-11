#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <string.h>
#include "stream_socket.h"

int main(){
    int socketFd;
    socketFd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(socketFd < 0){
        return -1;
    }
    struct sockaddr_un addr;
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, "/tmp/socket1", sizeof(addr.sun_path) - 1);

    int ret = bind(socketFd, NULL, 0);
    if(ret < 0){
        return -1;
    }

    ret = listen(socketFd, 0);

    if(ret < 0){
        return -1;
    }

    int clientFd;
    clientFd = accept(socketFd, NULL, 0);
    if(clientFd < 0){
        return -1;
    }

    size_t numRead;
    static char buf[buffSize]; 
    while (numRead = recv(clientFd, buf, buffSize, 0) > 0){
        numRead = recv(clientFd, buf, buffSize, 0);
        printf("read %zu bytes: %s\n", numRead, buf);
    }

    return 0;
}