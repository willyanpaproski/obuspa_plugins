#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "usp_err_codes.h"
#include "vendor_defs.h"
#include "vendor_api.h"
#include "usp_api.h"
#include "plugins/deviceInfo.h"
#include "plugins/dhcpv4.h"

/*********************************************************************//**
**
** VENDOR_Init
**
**************************************************************************/
int VENDOR_Init(void)
{
    int err = USP_ERR_OK;

    // Registra apenas o Pool como multi-instance (os pais já existem no core)
    err |= USP_REGISTER_Object("Device.DHCPv4.Server.Pool.{i}.", NULL, NULL, NULL, NULL, NULL, NULL);

    // Parâmetro de teste
    err |= USP_REGISTER_VendorParam_ReadOnly("Device.DeviceInfo.X_IXC_Teste", GetTeste, DM_STRING);

    // Seu gateway (IPRouters é uma lista separada por vírgula, mas como é single pool, ok)
    err |= USP_REGISTER_VendorParam_ReadOnly("Device.DHCPv4.Server.Pool.{i}.IPRouters", GetGateway, DM_STRING);

    // Recomendado: registre outros parâmetros obrigatórios como constantes para evitar erros de schema
    // Exemplos mínimos para um Pool funcional (ajuste valores se necessário)
    err |= USP_REGISTER_Param_Constant("Device.DHCPv4.Server.Pool.{i}.Enable", "true", DM_BOOL);
    err |= USP_REGISTER_Param_Constant("Device.DHCPv4.Server.Pool.{i}.Status", "Enabled", DM_STRING);
    err |= USP_REGISTER_Param_Constant("Device.DHCPv4.Server.Pool.{i}.Alias", "cpe-lan", DM_STRING);
    err |= USP_REGISTER_Param_Constant("Device.DHCPv4.Server.Pool.{i}.MinAddress", "192.168.1.100", DM_STRING);
    err |= USP_REGISTER_Param_Constant("Device.DHCPv4.Server.Pool.{i}.MaxAddress", "192.168.1.200", DM_STRING);
    err |= USP_REGISTER_Param_Constant("Device.DHCPv4.Server.Pool.{i}.SubnetMask", "255.255.255.0", DM_STRING);

    if (err != USP_ERR_OK) {
        USP_LOG_Error("%s: Falha ao registrar objetos DHCPv4", __FUNCTION__);
    }

    return err;
}

/*********************************************************************//**
**
** VENDOR_Start
**
**************************************************************************/
int VENDOR_Start(void)
{
    // Cria a instância estática única do Pool
    USP_DM_InformInstance("Device.DHCPv4.Server.Pool.1.");

    return USP_ERR_OK;
}

/*********************************************************************//**
**
** VENDOR_Stop
**
**************************************************************************/
int VENDOR_Stop(void)
{
    return USP_ERR_OK;
}