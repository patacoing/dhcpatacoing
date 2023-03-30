#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <time.h>
#include <sys/socket.h>

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

    send_dhcp_discover(sock, mac_address);

    close(sock);
    return 0;
}