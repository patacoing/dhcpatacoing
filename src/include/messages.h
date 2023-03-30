#ifndef MESSAGES_H
#define MESSAGES_H

#include <netinet/in.h>

#define DHCP_REQUEST 1
#define DHCP_REPLY 2

#define HARDWARE_TYPE_ETHERNET 1
#define MAC_ADDRESS_LENGTH 6
#define HARDWARE_ADDRESS_LENGTH MAC_ADDRESS_LENGTH

#define MAGIC_COOKIE 0x63825363

typedef struct
{
    uint8_t op;
    uint8_t htype;
    uint8_t hlen;
    uint8_t hops;
    uint32_t xid;
    uint16_t secs;
    uint16_t flags;
    uint32_t ciaddr;
    uint32_t yiaddr;
    uint32_t siaddr;
    uint32_t giaddr;
    uint8_t chaddr[16];
    uint8_t sname[64];
    uint8_t file[128];
    uint32_t magic_cookie;
    uint8_t options[4];

} dhcp_message_t;

extern const dhcp_message_t dhcp_discover;

#endif