#include "usp_api.h"
#include "usp_err_codes.h"
#include <string.h>

int GetManufacturer(char *buf, int len)
{
    strncpy(buf, "IXCSoft", len);
    return USP_ERR_OK;
}

int GetModelName(char *buf, int len) 
{
    strncpy(buf, "IXC_CPE", len);
    return USP_ERR_OK;
}

int GetProductClass(char *buf, int len)
{
    strncpy(buf, "IXC_CPE", len);
    return USP_ERR_OK;
}