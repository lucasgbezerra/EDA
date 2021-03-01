#include <stdio.h>
#include <stdlib.h>

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
	int n, i,k = 0, c;
	int *v, *vu;
	int nmru;

	scanf("%d", &n);
	
	v = malloc(((n+n/2)+1) * sizeof(int));
	vu = malloc(((n+n/2)+1) *sizeof(int));
	
	for(int i = 0 ; i < n; i++)
		scanf("%d", &v[i]);

	mergeSort(v, 0, n);
	
	for(int i = 0; i < n-1; i++){
		if(v[i] != v[i+1]){
			vu[k] = v[i];
			k++;
		}
	}
	vu[k++] = v[n-1];
	for(int i = 0; i < k; i++)
		v[i] = vu[i];
	

	if(k % 2 != 0)
		v[k++] = 1000000000;

	c = k;
	for(int i = 1; i < c; i+=2){	
		nmru = v[i] + v[i-1];
		if(buscaBinaria(v, 0, c, nmru) == -1)
			v[k++] = nmru;	
	}
	
	mergeSort(v, 0, k);

	for(int i = 0; i < k; i+=4)
		printf("%d\n", v[i]);
	printf("Elementos: %d\n", k);

	return 0;
}