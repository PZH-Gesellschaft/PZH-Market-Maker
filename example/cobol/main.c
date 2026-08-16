#include <stdio.h>
#include <libcob.h>

extern void pzh_mid_price(double*, double*, double*);

int main(int argc, char** argv) {
	
	cob_init(argc, argv);
	
	double bid = 1.0000;
	double ask = 0.9999;
	double mid = 0;
	
	pzh_mid_price(&bid, &ask, &mid);

	printf("Mid-Price: %.15f\n", mid);
	
	return 0;
}