// **************************
// *** Author: Reymon Dev ***
// *** Date: 1 Mai 2026   ***
// *** Update: 1 Mai 2026 ***
// *** License: MIT       ***
// **************************

#ifndef REYMON_REYMM_UTILITIES_TYPES_H
#define REYMON_REYMM_UTILITIES_TYPES_H
#if defined(__cplusplus)
extern "C" {
#endif

// ************************
// *** Libraries Config ***
// ************************

// *****************
// *** Libraries ***
// *****************

// **************
// *** Macros ***
// **************

// ***************
// *** Aliases ***
// ***************

// *****************
// *** Enumerate ***
// *****************

typedef enum {

	REYMM_TYPE_IO_OPEN  = (1 << 0) ^ 0,
	REYMM_TYPE_IO_CLOSE = (1 << 1) ^ 0,
	REYMM_TYPE_IO_GET_CONTENT = (1 << 2) ^ 0

} reymm_type;

// ******************
// *** Structures ***
// ******************

// *****************
// *** Functions ***
// *****************

#if defined(__cplusplus)
}
#endif
#endif // REYMON_REYMM_UTILITIES_TYPES_H