#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#include "include/utils.h"

int init_socket(const char *interface_name)
{
    struct sockaddr_in svc = {
        .sin_family = PF_INET,
        .sin_port = htons(67),
        .sin_addr.s_addr = htonl(INADDR_BROADCAST),
    };
    socklen_t infoLen = sizeof(struct sockaddr);
    int broadcastEnable = 1;
    struct sockaddr_in sock_info;

    memset(&svc.sin_zero, 0, 8);
    int sock = socket(PF_INET, SOCK_DGRAM, 0);

    setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable));
    setsockopt(sock, SOL_SOCKET, SO_BINDTODEVICE, interface_name, strlen(interface_name));

    if (connect(sock, (struct sockaddr *)&svc, sizeof(svc)) < 0)
    {
        printf("erreur connect\n");
    }
    getsockname(sock, (struct sockaddr *)&sock_info, &infoLen);
    printf("Local IP: %s, port : %d\n", inet_ntoa(sock_info.sin_addr), ntohs(sock_info.sin_port));

    return sock;
}