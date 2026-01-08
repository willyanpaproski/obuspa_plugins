#ifndef DHCPV4_H
#define DHCPV4_H

#include "usp_api.h"

int GetGateway(dm_req_t *req, char *buf, int len);
int GetDhcpv4ServerPoolInstances(dm_req_t *req, int *instances, int max_instances)

#endif