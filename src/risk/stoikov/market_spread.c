// ********************************
// *** Author: Reymon Dev ***
// *** Datum: 14. Mai. 2026     ***
// *** Aktua: 14. Mai. 2026     ***
// *** Lizenz: AGPL-3-or-later  ***
// ********************************

// ********************
// *** Bibliotheken ***
// ********************

#include <pzh/pzhmm/risk/market.h>

double pzhmm_market_spread(double Pb, double Pa) {

	/** Formel
	 * Pb is best price bid
	 * Pa is best price ask
	 * Spread is S
	 * 
	 * S = (Pa - Pb)
	 * */

	return Pa - Pb;
}