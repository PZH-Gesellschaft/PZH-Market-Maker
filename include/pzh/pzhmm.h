// *********************************
// *** Author: PZH Geselleschaft ***
// *** Datum: 09 Mai 2026        ***
// *** Aktua: 14 Mai 2026        ***
// *** Lizenz: AGPL-3-or-later   ***
// *********************************

#ifndef PZH_PZHMM_H
#define PZH_PZHMM_H
#ifdef __cplusplus
extern "C" {
#endif

// ********************
// *** Bibliotheken ***
// ********************

#include <stdint.h>
#include <stddef.h>
#include <yyjson.h>
#include <libwebsockets.h>

#include "pzhmm/utils/common.h"
#include "pzhmm/utils/json.h"
#include "pzhmm/utils/string.h"
#include "pzhmm/utils/security.h"

#include "pzhmm/risk/inventory.h"
#include "pzhmm/risk/market.h"
#include "pzhmm/risk/price.h"

#include "pzhmm/exchange/exchange.h"

// ******************
// *** Funktionen ***
// ******************

extern void* binance_connect(void*);
extern void* kraken_connect(void*);

#ifdef __cplusplus
}
#endif
#endif // PZH_PZHMM_H