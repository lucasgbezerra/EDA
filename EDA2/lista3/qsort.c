#include <stdio.h>
#include <stdlib.h>
#include "quickSort.c"

int main(){
	int n;
	int *v;	
	scanf("%d", &n);
	v = malloc(n * sizeof(int));

	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	quickSortM3(v, 0, n-1); //inetvalo fechado [l,r]	


	for(int i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
	return 0;
}
