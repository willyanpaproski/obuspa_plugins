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

    //Inicia parâmetros do servidor dhcp
    err |= USP_REGISTER_Object("Device.DHCPv4.Server.Pool.{i}.", NULL, NULL, NULL, NULL, NULL, NULL);
    err |= USP_REGISTER_VendorParam_ReadOnly("Device.DHCPv4.Server.Pool.{i}.IPRouters", GetGateway, DM_STRING);
    err |= USP_REGISTER_VendorParam_ReadOnly("Device.DHCPv4.Server.Pool.{i}.SubnetMask", GetSubnetMask, DM_STRING);
    err |= USP_REGISTER_VendorParam_ReadOnly("Device.DHCPv4.Server.Pool.{i}.MinAddress", GetMinAddress, DM_STRING);
    err |= USP_REGISTER_VendorParam_ReadOnly("Device.DHCPv4.Server.Pool.{i}.MaxAddress", GetMaxAddress, DM_STRING);
    err |= USP_REGISTER_VendorParam_ReadOnly("Device.DHCPv4.Server.Pool.{i}.LeaseTime", GetLeaseTime, DM_INT);
    err |= USP_REGISTER_VendorParam_ReadOnly("Device.DHCPv4.Server.Pool.{i}.Enable", GetEnable, DM_BOOL);
    err |= USP_REGISTER_Param_Constant("Device.DHCPv4.Server.Pool.{i}.Status", "Enabled", DM_STRING);
    err |= USP_REGISTER_Param_Constant("Device.DHCPv4.Server.Pool.{i}.Alias", "cpe-dhcpv4serverpool", DM_STRING);

    err |= USP_REGISTER_VendorParam_ReadOnly("Device.DeviceInfo.X_IXC_Teste", GetTeste, DM_STRING);


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