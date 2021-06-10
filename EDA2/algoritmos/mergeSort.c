//MergeSort
//
#include <stdlib.h>
#include <stdio.h>

typedef int Item;
#define less(A, B) ((A) < (B))
#define lesseq(A, B) ((A) <= (B))
#define exch(A, B){Item t = A; A = B; B = t;}
#define cmpexch(A, B){if(less(B, A)) exch(A, B)}

void merge(Item *v, int l, int m, int r){

	Item *R =  malloc(sizeof(Item)*(r-l+1));
	int i = l, j = m + 1, k = 0;

	while(i <= m && j <= r){
		if(lesseq(v[i], v[j]))
			R[k++] = v[i++];
		else
			R[k++] = v[j++];
	}
	while(i <= m)
		R[k++] = v[i++];

	while(j <= r)
		R[k++] = v[j++];

    k = 0;
	for(int i = l; i <= r; i++)
		v[i] = R[k++];

	free(R);
}
void mergeSort(Item *v,  int l, int r){
	if(l >= r)
        return;

    int meio = (l + r)/2;
    mergeSort(v, l, meio);
    mergeSort(v, meio+1, r);
    merge(v, l, meio, r);
    
}
