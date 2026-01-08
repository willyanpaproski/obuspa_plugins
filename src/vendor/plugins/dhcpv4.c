#include "dhcpv4.h"
#include "usp_err_codes.h"
#include "uciHelper.h"

#include <string.h>
#include <stdio.h>

int GetGateway(dm_req_t *req, char *buf, int len)
{
    (void)req;

    return GetStringValue("dhcpv4.lan.router", buf, len);
}

int GetSubnetMask(dm_req_t *req, char *buf, int len)
{
    (void)req;

    return GetStringValue("dhcpv4.lan.netmask", buf, len);
}

int GetMinAddress(dm_req_t *req, char *buf, int len)
{
    (void)req;

    return GetStringValue("dhcpv4.lan.start", buf, len);
}

int GetMaxAddress(dm_req_t *req, char *buf, int len) 
{
    (void)req;

    return GetStringValue("dhcpv4.lan.limit", buf, len);
}

int GetLeaseTime(dm_req_t *req, char *buf, int len)
{
    (void)req;

    return GetStringValue("dhcpv4.lan.leasetime", buf, len);
}

int GetEnable(dm_req_t *req, char *buf, int len)
{
    (void)req;

    return GetStringValue("dhcpv4.lan.enable", buf, len);
}