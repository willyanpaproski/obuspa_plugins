#include "dhcpv4.h"
#include "usp_err_codes.h"

#include <uci.h>
#include <string.h>
#include <stdio.h>

int GetGateway(dm_req_t *req, char *buf, int len)
{
    struct uci_context *ctx;
    struct uci_ptr ptr;
    const char *uci_path = "dhcpv4.lan.router";

    (void)req;

    ctx = uci_alloc_context();
    if (ctx == NULL) {
        return USP_ERR_INTERNAL_ERROR;
    }

    memset(&ptr, 0, sizeof(ptr));

    if (uci_lookup_ptr(ctx, &ptr, uci_path, true) != UCI_OK ||
        ptr.o == NULL ||
        ptr.o->type != UCI_TYPE_OPTION ||
        ptr.o->v.string == NULL)
    {
        snprintf(buf, len, "0.0.0.0");
    }
    else
    {
        snprintf(buf, len, "%s", ptr.o->v.string);
    }

    uci_free_context(ctx);
    return USP_ERR_OK;
}