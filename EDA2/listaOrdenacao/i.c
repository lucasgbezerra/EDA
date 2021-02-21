#include <stdio.h>
#include <stdlib.h>

int verifica (int *v, int n){
	int cont = 1;

	for(int i = n - 1; i > 0; i--){
		if(v[i] != v[i-1])
			cont++;
	}


	return cont;
}

int *merge(int *v, int l, int m, int r){
	int *vec = malloc((r-l) * sizeof(int));
	
	int k = 0, i = l, j = m;

	while(i < m && j < r){
		if(v[i] <= v[j])
			vec[k++] = v[i++];
		else
			vec[k++] = v[j++];
	}

	while(i < m)
		vec[k++] = v[i++];
	while(j < r)
		vec[k++] = v[j++];
	
	return vec;

}

void mergeSort(int *v, int l, int r){
	if(l < r - 1){
		int m = (l+r)/2;
		mergeSort(v, l, m);
		mergeSort(v, m, r);
		int *c = merge(v, l, m, r);

		for(int i = l; i < r; i++)
			v[i] = c[i - l];

		free(c);
	}
}

int main(){
	int *v;
	int n, x, cont = 0;
	
	scanf("%d",&n);
	v = malloc(n * sizeof(int));

	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	mergeSort(v, 0, n);
	cont = verifica(v, n);

	printf("%d\n", cont);
	return 0;
}
