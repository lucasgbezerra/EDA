#include <stdio.h>
#include <stdlib.h>
//

void merge(int *v, int l, int m, int r){

	int *vec =  malloc((r-l) * sizeof(int));
	int i = l, j = m, k = 0;

	while(i < m && j < r){
		if(v[i] <= v[j])
			vec[k++] = v[i++];
		else
			vec[k++] = v[j++];
	}
	while(i <m)
		vec[k++] = v[i++];

	while(j < r)
		vec[k++] = v[j++];

	for(int i = l; i < r; i++)
		v[i] = vec[i - l];

	free(vec);
}
void mergeSort(int *v,  int l, int r){
	if(l < r - 1){
		int meio = (l + r)/2;
		mergeSort(v, l, meio);
		mergeSort(v, meio, r);
		merge(v, l, meio, r);
	}
		
}
int buscaBinaria(int *v, int l, int r, int x){
	int m = (l + r)/2;
	if(l  == r - 1){
		if(v[l] == x)
			return l;
		else if(v[r] == x)
			return r;
		else
			return -1;
	}
	if(x < v[m])
		return buscaBinaria(v, l, m, x);
	else
		return buscaBinaria(v, m, r, x);
}
int main(){
	int n, x;
	int *v;

	scanf("%d", &n);
	v = malloc(n * sizeof(int));

	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	
	mergeSort(v, 0, n);

	while(scanf("%d", &x) != EOF){
		if(buscaBinaria(v, 0, n, x) == -1)
			printf("nao\n");
		else
			printf("sim\n");
	}
}
