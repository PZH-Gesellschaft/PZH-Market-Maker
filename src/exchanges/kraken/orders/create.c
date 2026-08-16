// *******************************
// *** Autor: Reymon Dev       ***
// *** Datum: 14. Juni. 2026   ***
// *** Aktua: 14. Juni. 2026   ***
// *** Lizenz: AGPL-3-or-later ***
// *******************************

#include <pzh/pzhmm.h>
#include <pzh/pzhmm/exchange/exchange.h>
#include <pzh/pzhmm/exchange/kraken.h>

char* kraken_create_order(pzh_ort_t type, krak_order_t* order) {

	if (type == PZH_ORDER_BUY)
		return kraken_buy_order(order);

	else if (type == PZH_ORDER_SELL)
		return kraken_sell_order(order);

	else
		return NULL;
}