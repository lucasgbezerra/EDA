#include <stdlib.h>
#include "macros.h"

void quickSelect(Item *v, int l, int r, int k){
	int m = (r+l)/2;
	int j;
	if(r <= l)
		return;
	// Mediana
    /*
    cmpexch(v[m], v[r]);
    cmpexch(v[l], v[m]);
    cmpexch(v[r], v[m]);
	*/
    j = partition(v, l, r, 0);
	
	if(j > k)
		return quickSelect(v, l, j-1,k);
	else if(j < k)
		return quickSelect(v, j+1, r,k);
}