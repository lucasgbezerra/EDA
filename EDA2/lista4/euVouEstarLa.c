#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Item
{
    int *viz;
    int numV;
}Item;

#define Key(A) (A) 
#define less(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
#define exch(A, B){int t = A; A = B; B = t;}
#define cmpexch(A, B){if(less(B, A)) exch(A, B)}

int partition(int *v, int l, int r){
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

void quickSortM3(int *v, int l, int r){
	int j;
	int m = (r+l)/2;
	if(r <= l)
		return;
	cmpexch(v[m], v[r]);
	cmpexch(v[l], v[m]);
	cmpexch(v[r], v[m]);

	j = partition(v, l, r);
	quickSortM3(v, l, j-1);
	quickSortM3(v, j+1, r);
}

int buscaBinaria(int *v, int l, int r,int x){
	int m = (r+l)/2;	

	if(l == r -1){
		if(v[l] == x)
			return l;
		if(v[r] == x)
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
    int N, M , J;
    Item *locais;
    int *lProibidos;
    int local;
    int busca;

    scanf("%d %d %d", &N, &M, &J);
    locais = malloc(sizeof(Item) * N);
    for(int i = 0; i < N; i++){
        scanf("%d", &locais[i].numV);
        locais[i].viz = malloc(sizeof(int) * locais[i].numV);
        for(int c = 0; c < locais[i].numV; c++)
            scanf("%d", &locais[i].viz[c]);
    }
    lProibidos = malloc(sizeof(int) * (N));
    memset(lProibidos, 0, sizeof(int)*N);
    for (int i = 0; i < M; i++){
        scanf("%d", &local);
        lProibidos[local]++;
        for(int c = 0; c < locais[local].numV; c++)
            lProibidos[locais[local].viz[c]]++;
    }
    
    for (int i = 0; i < J; i++){
        scanf("%d", &busca);
        if(lProibidos[busca] != 0)
            printf("Eu vou estar la\n");
        else
            printf("Nao vou estar la\n");

    }

    return 0;
}
    
