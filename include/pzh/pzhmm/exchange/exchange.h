// *********************************
// *** Author: PZH Geselleschaft ***
// *** Date: 9 Mai 2026          ***
// *** Update: 9 Mai 2026        ***
// *** License: AGPL-3-or-later  ***
// *********************************

#if defined(__cplusplus)
extern "C" {
#endif

#ifndef PZH_PZHMM_EXCHANGE_EXCHANGE_H
#define PZH_PZHMM_EXCHANGE_EXCHANGE_H

// *****************
// *** Libraries ***
// *****************

#include <stdint.h>
#include <yyjson.h>
#include <libwebsockets.h>

// **************
// *** Macros ***
// **************

#define PZHMM_BUFFER_SIZE 0x1000

#define PZH_CALLBACK_CLIENT_CONTINUE 0
#define PZH_CALLBACK_CLIENT_EXIT     -1

// ******************
// *** Structures ***
// ******************

typedef struct {

	char symbol[64];

	size_t bid;
	size_t ask;
	double size;
	size_t limit;

	double gamma;

	char apikey[128];
	char apisecret[128];

} pzh_exchange_settings;

typedef enum PZH_ORDER_TYPE {

	PZH_ORDER_BUY   = (uint64_t) 1 << 1,
	PZH_ORDER_SELL  = (uint64_t) 1 << 2,
	PZH_ORDER_ERROR = (uint64_t) 1 << 63

} pzh_ort_t;

// *****************
// *** Functions ***
// *****************

extern int binance_callback(struct lws*, enum lws_callback_reasons,  void*, void*, size_t);
extern int kraken_callback(struct lws*, enum lws_callback_reasons,  void*, void*, size_t);

#endif // PZH_PZHMM_EXCHANGE_EXCHANGE_H

#if defined(__cplusplus)
}
#endif