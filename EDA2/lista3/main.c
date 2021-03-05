#include <stdio.h>
#include <stdlib.h>
#include "quickSort.c"

int main(){
	int n, p, x;
	int *ids;

	scanf("%d %d %d", &n, &p, &x);
	ids = malloc(n * sizeof(int));

	for(int i = 0; i < n; i++)
		scanf("%d", &ids[i]);

	quickSortM3(ids, 0, n-1);

	
	for(int i = p*x; i < n && i < (p*x + x); i++)
		printf("%d\n", ids[i]);
	return 0;
}
