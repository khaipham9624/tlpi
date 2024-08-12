#include "datagram_socket.h"



int main(int argc, char const *argv[])
{
    int sockFd = socket(AF_UNIX, SOCK_DGRAM, 0);
    char buf[buffSize];
    int numRead;

    if(sockFd < 0){
        return -1;
    }
    if (remove(SV_SOCK_PATH) < 0 && errno != ENOENT){
        return -1;
    }
    struct sockaddr_un addr;
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SV_SOCK_PATH, sizeof(addr.sun_path) - 1);

    bind(sockFd, (struct sockaddr*)&addr, sizeof(addr));

    struct sockaddr clientSockAddr;
    memset(&clientSockAddr, 0, sizeof(clientSockAddr));

    for (;;){
        recvfrom(sockFd, buf, buffSize, 0, (struct sockaddr*)&clientSockAddr, sizeof(struct sockaddr_un));
        if (strcmp(buf, "quit") == 0){
            break;
        }
        printf("read %zu bytes: %s\n", numRead, buf);
    }

    return 0;
}
