#include "include/messages.h"

const dhcp_message_t dhcp_discover = {
    .op = DHCP_REQUEST,
    .htype = HARDWARE_TYPE_ETHERNET,
    .hlen = MAC_ADDRESS_LENGTH,
    .hops = 0,
    .secs = 0,
    .flags = 0xFFFF,
    .ciaddr = 0,
    .yiaddr = 0,
    .siaddr = 0,
    .giaddr = 0,
    .sname = {0},
    .file = {0},
    .magic_cookie = MAGIC_COOKIE,
    .options = {0x35, 0x01, 0x01, 0xFF}};

dhcp_message_t *prepare_dhcp_message_for_network(dhcp_message_t *message)
{
    message->flags = htons(message->flags);
    message->xid = htonl(message->xid);
    message->ciaddr = htonl(message->ciaddr);
    message->yiaddr = htonl(message->yiaddr);
    message->siaddr = htonl(message->siaddr);
    message->giaddr = htonl(message->giaddr);
    message->magic_cookie = htonl(message->magic_cookie);
    return message;
}