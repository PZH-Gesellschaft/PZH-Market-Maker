// *********************************
// *** Author: PZH Geselleschaft ***
// *** Date: 9 Mai 2026          ***
// *** Update: 9 Mai 2026        ***
// *** License: AGPL-3-or-later  ***
// *********************************

#if defined(__cplusplus)
extern "C" {
#endif

#ifndef PZH_PZHMM_EXCHANGE_KRAKEN_H
#define PZH_PZHMM_EXCHANGE_KRAKEN_H

// *****************
// *** Libraries ***
// *****************

#include "exchange.h"

// **************
// *** Macros ***
// **************

#define KRAKEN_TOKEN_SIZE     0x2C
#define KRAKEN_SYMBOL_SIZE    0x40
#define KRAKEN_APIKEY_SIZE    0x39
#define KRAKEN_APISECRET_SIZE 0x59

#define KRAKEN_JSON_SIZE 0x1000

#if defined(PZH_DEBUG)

#define BASE_REST_URL "Not Found"
#define BASE_WS_URL   "Not Found"

#define PZHMM_WS_STREAM_ADDRESS "Not Found"
#define PZHMM_WS_STREAM_PATH    "Not Found"
#define PZHMM_WS_STREAM_PORT	0

#define PZHMM_WS_ORDER_ADDRESS "Not Found"
#define PZHMM_WS_ORDER_PATH    "Not Found"
#define PZHMM_WS_ORDER_PORT	   0

#define PZHMM_WS_PROTOCOL "kraken"
#define PZHMM_WS_USER     "Reymon Kraken"

#elif defined(PZH_RELEASE)

#define BASE_REST_URL "https://api.kraken.com/0/private"
#define BASE_WS_URL   "wss://ws-auth.kraken.com/v2"

#define PZHMM_WS_STREAM_ADDRESS "ws-auth.kraken.com/v2"
#define PZHMM_WS_STREAM_PATH    "/ws/"
#define PZHMM_WS_STREAM_PORT	9443

#define PZHMM_WS_ORDER_ADDRESS "ws-auth.kraken.com/v2"
#define PZHMM_WS_ORDER_PATH    "/ws-api/v3"
#define PZHMM_WS_ORDER_PORT	   443

#define PZHMM_WS_PROTOCOL "Kraken"
#define PZHMM_WS_USER     "Reymon Kraken"

#endif

// ***************
// *** Aliases ***
// ***************

typedef long long krak_ms;

// ******************
// *** Enumerates ***
// ******************

typedef enum KRAKEN_STATE_CONNECTION {

	KRAKEN_STATE_CONNECT_SUCCESS,
	KRAKEN_STATE_CONNECT_FAILURE

} krak_st_connection;

// ******************
// *** Structures ***
// ******************

typedef struct KRAKEN_WEBSOCKET_CONNECT {

	struct lws* wsi;
	struct lws_context* context;
	
	struct lws_client_connect_info   client_info;
	struct lws_context_creation_info context_creation;

	bool exit;

} krak_ws_connection;

typedef struct KRAKEN_ORDER {

	yyjson_mut_doc* doc;
	yyjson_mut_val* root;
	yyjson_mut_val* params;

	double limit_price;
	size_t order_userref;
	double order_qty;
	char   symbol[KRAKEN_SYMBOL_SIZE];
	char   token[KRAKEN_TOKEN_SIZE];
	size_t req_id;

	char apikey[KRAKEN_APIKEY_SIZE];
	char signature[KRAKEN_APISECRET_SIZE];

	char json[KRAKEN_JSON_SIZE];

} krak_order_t;

// *****************
// *** Functions ***
// *****************

extern char* kraken_payload(krak_order_t*, krak_ms);

extern char* kraken_buy_order(krak_order_t*);
extern char* kraken_sell_order(krak_order_t*);
extern char* kraken_create_order(pzh_ort_t, krak_order_t*);

extern char* kraken_subscribe(char*, char*);

#endif // PZH_PZHMM_EXCHANGE_KRAKEN_H

#if defined(__cplusplus)
}
#endif