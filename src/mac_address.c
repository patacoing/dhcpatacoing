#include "include/utils.h"
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>
#include <string.h>

uint8_t *get_mac_address(const char *interface, int sd)
{
    struct ifreq ifr;
    uint8_t *mac;

    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, interface, IFNAMSIZ - 1);

    ioctl(sd, SIOCGIFHWADDR, &ifr);

    mac = (uint8_t *)ifr.ifr_hwaddr.sa_data;
    return mac;
}