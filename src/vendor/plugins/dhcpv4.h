#ifndef DHCPV4_H
#define DHCPV4_H

#include "usp_api.h"

int GetGateway(dm_req_t *req, char *buf, int len);
int GetSubnetMask(dm_req_t *req, char *buf, int len);
int GetMinAddress(dm_req_t *req, char *buf, int len);
int GetMaxAddress(dm_req_t *req, char *buf, int len);
int GetLeaseTime(dm_req_t *req, char *buf, int len);
int GetEnable(dm_req_t *req, char *buf, int len)

#endif