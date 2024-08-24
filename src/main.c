#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>

#include "include/utils.h"

int main(int argc, char **argv)
{
    srand(time(NULL));
    char *interface_name;
    if (argc > 1)
        interface_name = argv[1];
    else
        interface_name = "eth0";

    int sock = init_socket(interface_name);
    uint8_t *mac_address = get_mac_address(interface_name, sock);

    sleep(2);
    printf("%d\n", send_dhcp_discover(sock, mac_address));

    char buffer[sizeof(dhcp_message_t)];
    dhcp_message_t *message = (dhcp_message_t *)buffer;
    ssize_t bytesRead = read(sock, buffer, sizeof(buffer));
    if (bytesRead == -1)
    {
        perror("Erreur lors de la lecture des données");
        exit(EXIT_FAILURE);
    }
    memcpy(message, buffer, sizeof(dhcp_message_t));
    printf("op : %d\n", message->op);
    printf("htype : %d\n", message->htype);
    printf("hlen : %d\n", message->hlen);
    printf("hops : %d\n", message->hops);
    printf("xid : %d\n", message->xid);
    printf("secs : %d\n", message->secs);
    printf("flags : %d\n", message->flags);
    printf("ciaddr : %d\n", message->ciaddr);
    sleep(10);
    close(sock);
    return 0;
}