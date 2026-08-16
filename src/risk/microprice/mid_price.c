// ********************************
// *** Author: Reymon Dev ***
// *** Datum: 14. Mai. 2026     ***
// *** Aktua: 19. Mai. 2026     ***
// *** Lizenz: AGPL-3-or-later  ***
// ********************************

// ********************
// *** Bibliotheken ***
// ********************

#include <pzh/pzhmm/risk/market.h>

double pzhmm_mid_price(double Pb, double Pa) {

	/** Formel
	 * 
	 * Pb is best bid price
	 * Pa is best ask price
	 * S  is spread
	 * 
	 * S = (Pb + Pa) / 2
	 * */

	return (Pb + Pa) / 2;
}