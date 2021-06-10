#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	unsigned long int dado;
    unsigned long int ant;
	unsigned long int prx;
}no;

int buscaBinaria(no *v, int l, int r, unsigned long int x){
	int m = (r+l)/2;	

	if(l == r -1){
		if(v[l].dado == x)
			return l;
		if(v[r].dado == x)
			return r;
		else
			return -1;
	}
	
	if(x < v[m].dado)
		return buscaBinaria(v, l, m, x);
	else
		return buscaBinaria(v, m, r, x);
}

void merge(no *v, int l, int m, int r){
	no *p = malloc((r-l) * sizeof(no));
	int i = l, j = m, k = 0;

	while(i < m && j < r){
		if(v[i].dado <= v[j].dado)
			p[k++] = v[i++];
		else
			p[k++] = v[j++];
	
	}
	while(i < m)
		p[k++] = v[i++];
	while(j < r)
		p[k++] = v[j++];

	for(int c = l; c < (r); c++)
			v[c] = p[c - l];

	free(p);
}

void mergeSort(no *v, int l, int r){
	if(l < r-1){
		int m = (r+l)/2;
		mergeSort(v, l, m);
		mergeSort(v, m, r);
		merge(v, l, m, r);
	}
}

int main(){
	no v[250010], ptr1, ptr2, *ptr, *way;
	int i = 0, j1, j2, k = 0, idx, cont = 0;

	while(scanf("%lx %lx %lx", &v[i].dado, &v[i].ant, &v[i].prx) != EOF)
		i++;
	way = malloc(sizeof(no) * i);
	ptr1 = v[0];
	ptr2 = v[1];

	mergeSort(v, 0, i);
	j1 = buscaBinaria(v, 0, i - 1, ptr1.dado);
	j2 = buscaBinaria(v, 0, i - 1, ptr2.dado);
	

	/*
	printf("\nptr1: %d |ptr2: %d\n\n", j1, j2);
	
	for(int c = 0; c < i; c++)
		printf("[%d]:%lx %lx %lx\n", c,v[c].dado, v[c].ant, v[c].prx);
	printf("\n");
	*/
	idx = buscaBinaria(v, 0, j1 - 1, ptr1.ant);
	for(int c = 0; c < j1; c++){
		
		if(idx != -1){
			if(c == 0)
				v[idx].prx = ptr2.prx;
			way[k++] = v[idx];
			idx = buscaBinaria(v, 0, j1 - 1, v[idx].ant);
		}
		

		
	}
	
	idx = j2+1;
	for(int c = j2+1; c < i; c++){
		if(idx != -1){
			way[k++] = v[idx];
			idx = buscaBinaria(v, j2, i-1, v[idx].prx);
		}
		
	}
	mergeSort(way, 0, k);
	
	printf("k: %d\n", k);
	for(int c = 0; c < k; c++)
		printf("%lx %lx %lx\n",way[c].dado, way[c].ant, way[c].prx);
	printf("\n\n");

	
	for(int c = j1; c < i; c++)
		if(v[c].dado != way[cont].dado)
			printf("%lx\n", v[c].dado);
		else
			cont++;
	return 0;
}
