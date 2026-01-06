#ifndef DEVICEINFO_H
#define DEVICEINFO_H

#include "usp_api.h"

int GetManufacturer(dm_req_t *req, char *buf, int len);
int GetModelName(dm_req_t *req, char *buf, int len);
int GetProductClass(dm_req_t *req, char *buf, int len);

#endif
