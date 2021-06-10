// Quicksort
// O quicksort adota a estratégia de divisão e conquista.


#include "quickSort.h"
#include "insertionSort.c"
#include "macros.h"
#include <stdlib.h>

int partition(Item *v, int l, int r){
	Item pv = v[r];
	int j = l;
	int aux;

	for(int k = l; k < r; k++){
		if(lesseq(v[k], pv)){
			exch(v[k], v[j]);
			j++;
		}
	}

	exch(v[r], v[j]);	
	return j;
}

void quickSort(Item *v, int l, int r){
	int j;

	if(r <= l)
		return;
	
	j = partition(v, l, r);
	quickSort(v, l, j-1);
	quickSort(v, j+1, r);
}

void quickSortM3(Item *v, int l, int r){
	int j;
	int m = (r+l)/2;
	if(r <= l)
		return;
	cmpexch(v[m], v[r]);
	cmpexch(v[l], v[m]);
	cmpexch(v[r], v[m]);

	j = partition(v, l, r);
	quickSortM3(v, l, j-1);
	quickSortM3(v, j+1, r);
}
void quickSortM3Opt(Item *v,int l, int r){
	int j;
	if (r-l <= 15) 
		return;
	exch(v[(l+r)/2], v[r-1]);
	cmpexch(v[l], v[r-1]);
	cmpexch(v[l], v[r]);
	cmpexch(v[r-1], v[r]);
	
	j = partition(v, l+1, r-1);
	quickSortM3Opt(v, j+1, r);
	quickSortM3Opt(v, l, j-1);
}

void quicksortM3insertion(int *v,int l,int r){
	quicksortM3Opt(v,l,r);
	insertionSort(v,l,r);
}
