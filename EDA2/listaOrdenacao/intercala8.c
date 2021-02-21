#include <stdio.h>
#include <stdlib.h>

void intercala(int *r, int l1, int r1, int *n, int l2, int r2){
	int *v = malloc(r1 * sizeof(int));
	
	for(int i = 0; i < r1; i++)
		v[i] = r[l1+i];

	int i = 0, j = 0, k = 0;

	while(i < r1 && j < r2){
		if(v[i] <= n[j])
			r[k++] = v[i++];
		else
			r[k++] = n[j++];
	}
	while(i < r1)
		r[k++] = v[i++];
	while(j < r2)
		r[k++] = n[j++];
	
}


int main(){
	int s, n[100000], r[1000000], sumS = 0;

	scanf("%d", &s);
	sumS +=s;
	for(int c = 0; c < s; c++)
		scanf("%d", &r[c]);
	

	for(int i = 1; i < 8; i++){
		scanf("%d", &s);
		for(int c = 0; c < s; c++)
			scanf("%d", &n[c]);
		intercala(r, 0, sumS, n, 0, s);
		sumS+=s;
	}
	for(int i = 0; i < sumS; i++)
		printf("%d ", r[i]);
	printf("\n");


	return 0;
}
