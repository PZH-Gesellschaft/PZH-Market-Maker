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

double pzh_imbalance(double Qb, double Qa) {

	/** Formel
	 * Qb is Quantity bid
	 * Qa is Quantity ask
	 * Imbalance is I
	 * 
	 * I = Qb / (Qb + Qa)
	 * */

	return  Qb / (Qb + Qa);
}