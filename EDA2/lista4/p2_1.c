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
int quickSelect(Item *v, int l, int r, int k){
	int j;
	if(r <= l)
		return l;

    j = partition(v, l, r);
	
	if(j > k)
		return quickSelect(v, l, j-1, k);
	else if(j < k)
		return quickSelect(v, j+1, r, k);
}


int main(){
    int n, p, x;
    int *ids;
    int ini, fim;

    scanf("%d %d %d", &n, &p, &x);
    ids = malloc(sizeof(int)* n);

    for(int i =0; i < n; i++)
        scanf("%d", &ids[i]);

    ini = quickSelect(ids, 0, n-1, p*x);
    if(p*x + x >= n)
	    fim = n;
	else
        fim = quickSelect(ids, ini, n-1,(p*x + x));
    quickSortM3(ids, ini, fim-1);
    

    for(int i = ini;i < n && i < fim; i++)
        printf("%d\n", ids[i]);
    return 0;
}