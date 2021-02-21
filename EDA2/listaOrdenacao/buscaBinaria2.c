#include <stdio.h>
#include <stdlib.h>

typedef struct combo{
	int posInicial;
	int num;
}combo;


void merge(combo *v, int l, int m, int r){
	combo *vec = malloc((r-l) * sizeof(combo));
	int k = 0, i = l, j = m;

	while(i < m && j < r){
		if(v[i].num <= v[j].num)			
			vec[k++] = v[i++];
		else
			vec[k++] = v[j++];
	}
	
	while(i < m)
		vec[k++] = v[i++];	

	while(j < r)
		vec[k++] = v[j++];
	
	for(int c = l; c < r; c++)
		v[c] = vec[c - l];

	free(vec);
}

void mergeSort(combo *v, int l, int r){
	if(l < r -1){
		int m = (l + r)/2;
		mergeSort(v, l, m);
		mergeSort(v, m, r);
		merge(v, l, m, r);
	}
}

int buscaBinaria(combo *v, int l, int r, int x){
	int m = (r+l)/2;	

	if(l == r -1){
		if(v[l].num == x)
			return v[l].posInicial;
		if(v[r].num == x)
			return v[r].posInicial;
		else
			return -1;
	}
	
	if(x < v[m].num)
		return buscaBinaria(v, l, m, x);
	else
		return buscaBinaria(v, m, r, x);
}

int main(){
	int m, n, x, idx;
	combo *v;

	scanf("%d %d", &n, &m);
	v = malloc(n * sizeof(combo));

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i].num);
		v[i].posInicial = i;
	}
	
	mergeSort(v, 0, n);
	
	for(int i = 0; i < m; i++){
		scanf("%d", &x);
		idx = buscaBinaria(v, 0, n - 1, x);
		printf("%d\n", idx);
	}
	return 0;
}
