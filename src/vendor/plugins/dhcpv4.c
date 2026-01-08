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