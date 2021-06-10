//kk paginas
#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define Key(A) (A) 
#define less(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
#define exch(A, B){Item t = A; A = B; B = t;}
#define cmpexch(A, B){if(less(B, A)) exch(A, B)}


int partition(Item *v, int l, int r){
	Item pv = v[r];
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
void quickSortM3(Item *v, int l, int r){
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


void quickSelect(Item *v, int l, int r, int k){
	int m = (r+l)/2;
	int j;
	if(r <= l)
		return;
    j = partition(v, l, r);
	if(j > k)
		return quickSelect(v, l, j-1,k);
	else if(j < k)
		return quickSelect(v, j+1, r,k);
}

int main(){
    int N, P, X;
    int *v;
    int ini, fim;
    int k = 0;

    scanf("%d %d %d", &N, &P, &X);
    v = malloc(sizeof(int) * N);
    while (scanf("%d", &v[k]) != EOF)
        k++;

    
    ini = P*X;
    fim = P*X + X;

    quickSelect(v, 0, k-1, ini);
    if(fim > N){
        fim = N;
        quickSortM3(v, ini, fim-1);
    }else{
        quickSelect(v, ini+1, k-1, fim);
        quickSortM3(v, ini, fim-1);
    }
    for (int i = ini; i < fim; i++)
        printf("%d\n", v[i]);
    
    return 0;
}