// ********************************
// *** Author: Reymon Dev ***
// *** Datum: 19. Mai. 2026     ***
// *** Aktua: 19. Mai. 2026     ***
// *** Lizenz: AGPL-3-or-later  ***
// ********************************

// ********************
// *** Bibliotheken ***
// ********************

#include <pzh/pzhmm/risk/market.h>

double pzhmm_weighted_mid_price(double Pb, double Pa, double I) {

	/** Formel
	 * 
	 * Pb is best bid price
	 * Pa is best ask price
	 * I  is imbalance
	 * M is weigthed mid-price
	 * 
	 * M = Pb(1 - I) + PaI
	 * 
	 * */

	return Pb * (1 - I) + (Pa * I);
}