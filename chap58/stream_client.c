#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "stream_socket.h"

int main(){
    int socketFd;
    socketFd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (socketFd < 1){
        return -1;
    }

    struct sockaddr_un addr;
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SV_SOCK_PATH, sizeof(addr.sun_path) - 1);


    int ret = connect(socketFd, (struct sockaddr*) &addr, sizeof(addr));
    if(ret < 0){
        return -1;
    }

    char buf[buffSize];

    // write "hello world" to socket
    memcpy(buf, "hello world", buffSize);
    buf[buffSize - 1] = '\0';
    ret = send(socketFd, buf, buffSize, 0);
    if(ret < 0){
        return -1;
    }

    return 0;
    

}