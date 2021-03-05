#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
	unsigned long int dado;
      	unsigned long int ant;
	unsigned long int prx;
}cel;

int buscaBinaria(cel *v, int l, int r, cel x){
	int m = (r+l)/2;	

	if(l == r -1){
		if(v[l].dado == x.dado)
			return l;
		if(v[r].dado == x.dado)
			return r;
		else
			return -1;
	}
	
	if(x.dado < v[m].ant)
		return buscaBinaria(v, l, m, x);
	else
		return buscaBinaria(v, m, r, x);
}

void merge(cel *v, int l, int m, int r){
	cel *p = malloc((r-l) * sizeof(cel));
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

void mergeSort(cel *v, int l, int r){
	if(l < r-1){
		int m = (r+l)/2;
		mergeSort(v, l, m);
		mergeSort(v, m, r);
		merge(v, l, m, r);
	}
}

int main(){
	cel v[250000], ptr1, ptr2;
	int i = 0, j1, j2;

	while(scanf(" %lx %lx %lx", &v[i].dado, &v[i].ant, &v[i].prx) != EOF)
		i++;
	
	ptr1 = v[0];
	ptr2 = v[1];

	for(int c = 0; c < i; c++)
		printf("%lx %lx %lx\n", v[c].dado, v[c].ant, v[c].prx);
	printf("\n");
	
	mergeSort(v, 0, i);
	j1 = buscaBinaria(v, 0, i - 1, ptr1);
	j2 = buscaBinaria(v, 0, i - 1, ptr2);
	
	printf("\n%d -  %d\n\n", j1, j2);
	
	for(int c = 0; c < i; c++)
		printf("%lx %lx %lx\n", v[c].dado, v[c].ant, v[c].prx);
	printf("\n");
	for(int c = j2 + 1; c < i; c++)
		printf("%lx %lx %lx\n", v[c].dado, v[c].ant, v[c].prx);
	printf("\n");
	
	for(int c = j1; c < j2 + 1; c++)
		printf("%lx\n", v[c].dado);

	return 0;
}
