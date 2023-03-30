#ifndef UTILS_H
#define UTILS_H

#include <sys/socket.h>
#include <net/if.h>
#include <netinet/in.h>
#include "messages.h"

/**
 * @brief Function to retrieve the MAC address of an interface
 * @param interface The interface to retrieve the MAC address from
 * @param sd The socket descriptor
 * @return  The MAC address of the interface
 */
uint8_t *get_mac_address(const char *interface_name, int sd);

/**
 * @brief Function to set up the sending socket
 * @param interface The interface to send the DHCP messages
 * @return The socket descriptor
 */
int init_socket(const char *interface);

/**
 * @brief Function to send the DHCP discover message
 * @param sd The socket descriptor
 * @param mac_address The MAC address of the interface
 * @return number of bytes sent on success, -1 on failure
 */
int send_dhcp_discover(int sd, uint8_t *mac_address);

/**
 * @brief Prepare the dhcp message to be sent to the network by converting values between host and network byte order
 * @param message The message to prepare
 * @return The prepared message
 */
dhcp_message_t *prepare_dhcp_message_for_network(dhcp_message_t *message);

#endif