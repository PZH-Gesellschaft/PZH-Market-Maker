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

typedef struct RDCAvellanedaStoikov {

	double best_bid;
	double best_ask;

	double quantity_bid;
	double quantity_ask;

	double kappa;
	double gamma;

	double current_inventory;
	double maximun_inventory;

} RDCAvellanedaStoikov_t;

//#################
//### Functions ###
//#################


#endif // RDC_COMMON_H

#if defined(__cplusplus)
}
#endif // __cplusplus