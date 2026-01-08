#include "dhcpv4.h"
#include "usp_err_codes.h"

#include <uci.h>
#include <string.h>
#include <stdio.h>

int GetGateway(dm_req_t *req, char *buf, int len)
{
    struct uci_context *ctx = NULL;
    struct uci_ptr ptr;
    int ret = USP_ERR_OK;
    char *uci_path = "dhcpv4.lan.start";

    (void)req;

    if ((ctx = uci_alloc_context()) == NULL)
    {
        return USP_ERR_INTERNAL_ERROR;
    }

    memset(&ptr, 0, sizeof(ptr));

    if (uci_lookup_ptr(ctx, &ptr, uci_path, true) != UCI_OK ||
        ptr.o == NULL ||
        ptr.o->type != UCI_TYPE_STRING ||
        ptr.o->v.string == NULL ||
        strlen(ptr.o->v.string) == 0)
    {
        snprintf(buf, len, "192.168.0.1");
        goto exit;
    }

    snprintf(buf, len, "%s", ptr.o->v.string);

exit:
    uci_free_context(ctx);
    return ret;
}