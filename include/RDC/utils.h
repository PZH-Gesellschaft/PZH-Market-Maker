//###############################
//### Autor: Reymon Dev       ###
//### Datum: 15. August. 2026 ###
//### Aktua: 15. August. 2026 ###
//### Lizenz: AGPL-3-or-later ###
//###############################

#if defined(__cplusplus)
extern "C" {
#endif // __cplusplus

#ifndef RDC_UTILS_H
#define RDC_UTILS_H

//##################
//### Structures ###
//##################

typedef struct RDCJson {

	char* file_name;

	yyjson_doc* document;
	yyjson_val* root;

	yyjson_read_err  err;
	yyjson_read_flag flg;

} RDCJson_t;

typedef struct RDCSetting {
	// Account values
	char* apikey;
	char* apisecret;

	// Symbol Settings
	char* symbol;

	// Avellaneda-Stoikov Settings
	double buy;
	double sell;

	double size;
	double inventory;

	double gamma;

	// Runtime Settings
	bool exit;

} RDCSetting_t;

//#################
//### Functions ###
//#################

extern void rdc_json_init(RDCJson_t*);
extern void rdc_setting_init(RDCSetting_t*);

#endif // RDC_COMMON_H

#if defined(__cplusplus)
}
#endif // __cplusplus