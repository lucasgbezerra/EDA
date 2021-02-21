#include <stdio.h>
#include <stdlib.h>

int *merge(int *v, int l, int m, int r){

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

	return vec;
	
}
void mergeSort(int *v,  int l, int r){
	if(l < r - 1){
		int meio = (l + r)/2;
		mergeSort(v, l, meio);
		mergeSort(v, meio, r);
		int *vec = merge(v, l, meio, r);

		for(int i = l; i < r; i++)
			v[i] = vec[i - l];

		free(vec);
	}
		
}

int main(){
	int v[100000];
	int i = 0;
	while(scanf("%d", &v[i]) != EOF)
		i++;

	mergeSort(v, 0, i);

	for(int c = 0; c < i; c++)
		if( c+1 == i)
			printf("%d", v[c]);
		else 
			printf("%d ", v[c]);
	printf("\n");
}
