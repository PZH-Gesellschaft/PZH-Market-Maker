// *********************************
// *** Author: PZH Geselleschaft ***
// *** Datum: 09 Mai 2026        ***
// *** Aktua: 14 Mai 2026        ***
// *** Lizenz: AGPL-3-or-later   ***
// *********************************

#ifdef __cplusplus
extern "C" {
#endif

#ifndef PZH_PZHMM_UTILS_COMMON_H
#define PZH_PZHMM_UTILS_COMMON_H

// *****************
// *** Libraries ***
// *****************

#include <stdint.h>
#include <stddef.h>

// **************
// *** Macros ***
// **************

#define PZH_FILE   (1 << 1)
#define PZH_STRING (1 << 2)

// ***************
// *** Aliases ***
// ***************

typedef size_t pzh_order_id;

// *****************
// *** FUnctions ***
// *****************

extern pzh_order_id pzh_next_id(pzh_order_id);
extern char*        pzh_order_id_to_string(pzh_order_id);
extern pzh_order_id pzh_string_to_order_id(char*);

#endif // PZH_PZHMM_UTILS_COMMON_H

#ifdef __cplusplus
}
#endif