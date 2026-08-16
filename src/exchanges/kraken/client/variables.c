// *******************************
// *** Autor: Reymon Dev       ***
// *** Datum: 12. Juni. 2026   ***
// *** Aktua: 13. Juni. 2026   ***
// *** Lizenz: AGPL-3-or-later ***
// *******************************

// *****************
// *** Libraries ***
// *****************

#include <pzh/pzhmm/exchange/kraken.h>

// ***************************
// *** Primitive Variables *** 
// ***************************

bool keep_orders;

// ***************************
// *** Websocket Variables ***
// *** ***********************

krak_ws_connection stream;
krak_ws_connection orders;
krak_ws_connection websocket;