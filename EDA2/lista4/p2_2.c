#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct ced
{
    int nota;//idx
    int cont;
}ced;

#define TAM 1001
typedef ced Item;
#define Key(A) (A.cont)
#define less(A, B) (Key(A) < Key(B))
#define eq(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
#define exch(A, B){Item t = A; A = B; B = t;}
#define cmpexch(A, B){if(less(B, A)) exch(A, B)}

void quickSelect(Item *v, int l, int r, int k){
	int m = (r+l)/2;
	int j;
	if(r <= l)
		return;
	// Mediana
    /*
    cmpexch(v[m], v[r]);
    cmpexch(v[l], v[m]);
    cmpexch(v[r], v[m]);
	*/
    j = partition(v, l, r, 0);
	
	if(j > k)
		return quickSelect(v, l, j-1,k);
	else if(j < k)
		return quickSelect(v, j+1, r,k);
}
int main(){
    ced *notas;
    int n;
    int x;

    notas = malloc(sizeof(ced) * TAM);
    memset(notas, 0, sizeof(ced) * TAM);

    scanf("%d", &n);
    while (n--){
        scanf("%d", &x);
        notas[x].nota = x;
        notas[x].cont++;
    }
    mergeSort(notas, 0, TAM-1);
    //quickSelect(notas, 0, TAM-1, TAM-1);
    //for(int i =0; i < TAM; i++)
        //if(notas[i].nota != 0)
            //printf("[%d] %d | %d\n", i,notas[i].nota, notas[i].cont);
	printf("%d\n", notas[0].nota);
    return 0;
}
