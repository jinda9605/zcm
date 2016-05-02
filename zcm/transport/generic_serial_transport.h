#ifndef _ZCM_TRANS_TIVAUSB_H
#define _ZCM_TRANS_TIVAUSB_H

#ifdef __cplusplus
extern "C" {
#endif

#include "zcm/zcm.h"
#include "zcm/transport.h"

zcm_trans_t *zcm_trans_generic_serial_create(
        uint32_t (*get)(uint8_t* data, uint32_t nData),
        uint32_t (*put)(const uint8_t* data, uint32_t nData));

#ifdef __cplusplus
}
#endif

#endif /* _ZCM_TRANS_TIVAUSB_H */
