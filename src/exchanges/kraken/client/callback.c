// *******************************
// *** Autor: Reymon Dev       ***
// *** Datum: 12. Juni. 2026   ***
// *** Aktua: 12. Juni. 2026   ***
// *** Lizenz: AGPL-3-or-later ***
// *******************************

#include <stdint.h>
#include <libwebsockets.h>
#include <pzh/pzhmm.h>
#include <pzh/pzhmm/exchange/binance.h>

// ************************
// *** Static Variables ***
// ************************

static pzh_json json;

static char* pc_symbol       = NULL;
static bool  stream_suscribe = false;

static pzh_exchange_settings settings;

// **************************
// *** External Variables ***
// **************************

extern bool keep_orders;
extern binance_ws_connect stream;
extern binance_ws_connect orders;
extern binance_ws_connect websocket;

// ****************
// *** Callback ***
// ****************

int kraken_callback(struct lws* wsi, enum lws_callback_reasons reason,  void* user, void* in, size_t length) {

	// *****************************************
	// *** Global Variables por the callback ***
	// *****************************************

	int i_reason = reason;

	switch (reason) {

		// **************************************************
		// *** Execute when the Connection is Established ***
		// **************************************************

		case LWS_CALLBACK_CLIENT_ESTABLISHED: {

			websocket.exit  = false;
			stream_suscribe = false;

			pzh_init_json(&json);

			// ****************************************
			// *** Get Information from kraken.json ***
			// ****************************************

			pzh_read_json(&json, PZH_FILE, "config/kraken.json");

			if (json.doc == NULL) {

				puts("Not found config/binance.json");
			
				return PZH_CALLBACK_CLIENT_EXIT;
			
			}

			// ********************
			// *** Set settings ***
			// ********************

			char* symbol = (char*) yyjson_get_str(yyjson_obj_get(json.root, "symbol"));

			if (symbol == NULL) {

				puts("Enter the symbol");

				return PZH_CALLBACK_CLIENT_EXIT;
			}

			char* apikey = (char*) yyjson_get_str(yyjson_obj_get(json.root, "apikey"));

			if (apikey == NULL) {

				puts("Enter the symbol");

				return PZH_CALLBACK_CLIENT_EXIT;
			}
			
			char* apisecret = (char*) yyjson_get_str(yyjson_obj_get(json.root, "apisecret"));

			if (apisecret == NULL) {

				puts("Enter the symbol");

				return PZH_CALLBACK_CLIENT_EXIT;
			}

			
			settings.bid   = yyjson_get_uint(yyjson_obj_get(json.root, "bid"));
			settings.ask   = yyjson_get_uint(yyjson_obj_get(json.root, "ask"));
			settings.size  = yyjson_get_num(yyjson_obj_get(json.root, "size"));
			settings.limit = yyjson_get_uint(yyjson_obj_get(json.root, "limit"));

			settings.gamma = yyjson_get_num(yyjson_obj_get(json.root, "gamma"));

			snprintf(settings.symbol, sizeof(settings.symbol), "%s", symbol);
			snprintf(settings.apikey, sizeof(settings.apikey), "%s", apikey);
			snprintf(settings.apisecret, sizeof(settings.apisecret), "%s", apisecret);

			return PZH_CALLBACK_CLIENT_CONTINUE;
		}

		// ****************
		// *** Response ***
		// ****************

		case LWS_CALLBACK_CLIENT_WRITEABLE: {

			return PZH_CALLBACK_CLIENT_CONTINUE;
		}

		// *********************************
		// *** Aktualisieren Information ***
		// *********************************

		case LWS_CALLBACK_CLIENT_RECEIVE: {

		}

		// *********************
		// *** Error Manager ***
		// *********************

		case LWS_CALLBACK_CLIENT_CONNECTION_ERROR: {

			return PZH_CALLBACK_CLIENT_CONTINUE;
		}

		// **********************
		// *** Close Callback ***
		// **********************

		case LWS_CALLBACK_CLOSED: {

			websocket.exit = true;

			return PZH_CALLBACK_CLIENT_CONTINUE;
		}

		// ****************************************
		// *** Managing connections I don't use ***
		// ****************************************

		default: {
			return lws_callback_http_dummy(wsi, reason, user, in, length);
		}

	}
	
}