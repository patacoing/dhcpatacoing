#include "include/utils.h"
#include "include/messages.h"

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>

int send_dhcp_discover(int sd, uint8_t *mac_address)
{
    dhcp_message_t *message = malloc(sizeof(dhcp_message_t));

    memcpy((void *)message, (void *)&dhcp_discover, sizeof(dhcp_message_t));
    memcpy(message->chaddr, mac_address, 6);
    message->xid = rand();
    message = prepare_dhcp_message_for_network(message);

    return send(sd, message, sizeof(dhcp_message_t), 0);
}