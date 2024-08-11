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
    strncpy(addr.sun_path, "/tmp/socket2", sizeof(addr.sun_path) - 1);
    bind(socketFd, &addr, sizeof(addr));


    int ret = connect(socketFd, NULL, 0);

}