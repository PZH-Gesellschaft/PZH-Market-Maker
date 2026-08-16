//###############################
//### Autor: Reymon Dev       ###
//### Datum: 15. August. 2026 ###
//### Aktua: 15. August. 2026 ###
//### Lizenz: AGPL-3-or-later ###
//###############################

#include <RDC.h>

void* RDConnection(void* instrument) {

	RDClient_t   client  = { 0 };
	RDCJson_t    json    = { 0 };
	RDCSetting_t setting = { 0 };

	json.file_name = (char*) instrument;

	rdc_json_init(&json);

}