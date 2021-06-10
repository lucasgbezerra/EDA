#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "macros.h"


int buscaBinaria(int *v, int l, int r,int x){
	int m = (r+l)/2;	

	if(l == r -1){
		if(v[l] == x)
			return l;
		if(v[r] == x)
			return r;
		else
			return -1;
	}
	
	if(x < v[m])
		return buscaBinaria(v, l, m, x);
	else
		return buscaBinaria(v, m, r, x);
}