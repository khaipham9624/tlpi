#include "datagram_socket.h"


int main(int argc, char const *argv[]){
    int socketFd;
    socketFd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (socketFd < 1){
        return -1;
    }

    struct sockaddr_un sockServerAddr;
    memset(&sockServerAddr, 0, sizeof(sockServerAddr));
    sockServerAddr.sun_family = AF_UNIX;
    strncpy(sockServerAddr.sun_path, SV_SOCK_PATH, sizeof(sockServerAddr.sun_path) - 1);

    char buff[buffSize];

    if (argc > 1){
        sprintf(buff, "%s", argv[1]);
    } else {
        sprintf(buff, "quit");
    }
    sendto(socketFd, buff, buffSize, 0, (struct sockaddr*)&sockServerAddr, sizeof(sockServerAddr));
}
