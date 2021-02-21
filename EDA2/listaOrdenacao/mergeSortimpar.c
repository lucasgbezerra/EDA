#include <stdio.h>
#include <stdlib.h>



void merge(int *v, int l, int m, int r){

	int *vec =  malloc((r-l) * sizeof(int));
	int i = l, j = m, k = 0;

	while(i < m && j < r){
		//printf("Enum - v[i]: %d | v[j}: %d\n", v[i], v[j]);
		if((v[i] % 2 == 0 && v[j] % 2 == 0) || (v[i] % 2 != 0 && v[j] % 2 != 0)){
			//printf("1 - v[i]: %d | v[j}: %d\n\n", v[i], v[j]);	
			if(v[i] < v[j])
				vec[k++] = v[i++];
			else
				vec[k++] = v[j++];
		}else if(v[i] % 2 == 0){
			//printf("2 - v[i]: %d | v[j}: %d\n\n", v[i], v[j]);
				vec[k++] = v[i++];
		}else{
			//printf("3 - v[i]: %d | v[j}: %d\n\n", v[i], v[j]);
			vec[k++] = v[j++];
		}
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
		//for(int c = l; c < meio; c++)
		//	printf("%d ", v[c]);
		//printf("<= MERGE\n");
		mergeSort(v, l, meio);
		mergeSort(v, meio, r);
		merge(v, l, meio, r);
	}
		
}

int main(){
	int *v;
	int tam;

	scanf("%d", &tam);
	v = malloc(tam * sizeof(int));

	for( int i = 0; i < tam; i++)
		scanf("%d", &v[i]);
	
	mergeSort(v, 0, tam);

	for( int i = 0; i < tam; i++){
		if(i + 1 == tam)
			printf("%d", v[i]);
		else
			printf("%d ", v[i]);

	}
	printf("\n");
	return 0;
}
