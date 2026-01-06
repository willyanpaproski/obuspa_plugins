#include "deviceInfo.h"
#include "usp_err_codes.h"
#include <string.h>

int GetManufacturer(dm_req_t *req, char *buf, int len)
{
    (void)req;

    strncpy(buf, "IXCSoft", len);
    return USP_ERR_OK;
}

int GetModelName(dm_req_t *req, char *buf, int len)
{
    (void)req;

    strncpy(buf, "IXC_CPE", len);
    return USP_ERR_OK;
}

int GetProductClass(dm_req_t *req, char *buf, int len)
{
    (void)req;

    strncpy(buf, "IXC_CPE", len);
    return USP_ERR_OK;
}
