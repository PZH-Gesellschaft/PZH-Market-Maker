//###############################
//### Autor: Reymon Dev       ###
//### Datum: 15. August. 2026 ###
//### Aktua: 15. August. 2026 ###
//### Lizenz: AGPL-3-or-later ###
//###############################

#if defined(__cplusplus)
extern "C" {
#endif // __cplusplus

#ifndef RDC_COMMON_H
#define RDC_COMMON_H

//################
//### Formulas ###
//################

#define NEXT_REQ_ID(id)   (id++)
#define NEXT_ORDER_ID(id) (id++) 

//#################
//### Constants ###
//#################

#define RDC_KRAKEN_MAX_CONNECTIONS  (200)
#define RDC_BINANCE_MAX_CONNECTIONS (300)

//##################
//### Data types ###
//##################

typedef size_t ReqID;
typedef size_t OrderID;

#endif // RDC_COMMON_H

#if defined(__cplusplus)
}
#endif // __cplusplus