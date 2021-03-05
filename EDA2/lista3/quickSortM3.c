#include <stdio.h>
#include <stdlib.h>

// Quicksort com mediana de 3
#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))
#define lesseq(A,B) (Key(A) <= Key(B))
#define exch(A, B) {int t = A; A = B; B = t;}
#define cmpexch(A, B) {if less (B,A) exch (A,B);}

int separa(int *v, int l, int r){
	int pv = v[r];
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
void quickSort(int *v, int l, int r){
	int j;
	int m = (r+l)/2;
	if(r <= l)
		return;
	cmpexch(v[m], v[r]);
	cmpexch(v[l], v[m]);
	cmpexch(v[r], v[m]);

	j = separa(v, l, r);
	quickSort(v, l, j-1);
	quickSort(v, j+1, r);
}

int main(){
	int n;
	int *v;	
	scanf("%d", &n);
	v = malloc(n * sizeof(int));

	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	quickSort(v, 0, n-1); //inetvalo fechado [l,r]	


	for(int i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
	free(v);
	return 0;
}
