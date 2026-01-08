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

    (void)req;

    if ((ctx = uci_alloc_context()) == NULL)
    {
        return USP_ERR_INTERNAL_ERROR;
    }

    memset(&ptr, 0, sizeof(ptr));

    // Busca network.lan.ipaddr (o IP da interface LAN, que é o gateway padrão)
    if (uci_lookup_ptr(ctx, &ptr, "network.lan.ipaddr", true) != UCI_OK ||
        ptr.o == NULL ||
        ptr.o->v.string == NULL ||
        strlen(ptr.o->v.string) == 0)
    {
        ret = USP_ERR_INTERNAL_ERROR;
        goto exit;
    }

    snprintf(buf, len, "%s", ptr.o->v.string);

exit:
    uci_free_context(ctx);
    return ret;
}