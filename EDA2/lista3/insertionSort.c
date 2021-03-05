#include <stdlib.h>
#include "macros.h"
#include "insertionSort.h"

void insertionSort(int *v, int l, int r){
	for(int i = r; i > l; i--)
		cmpexch(v[i-i], v[i]);
	for (int i = l+2; i <= r; i++){
		int j = i;
		int temp = v[j];
		while(less(temp, v[j-1])){
			v[j] = v[j-1];
			j--;
		}
		v[j] = temp;
	}
	
}
