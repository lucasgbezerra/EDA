#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define nless(A, B) ((A.nota) < (B.nota))
#define cless(A, B) ((A.cod) < (B.cod))
#define lesseq(A, B) ((A) <= (B))
#define eq(A, B) ((A) == (B))
#define exch(A, B){semente t = A; A = B; B = t;}
#define ncmpexch(A, B){if(nless(B, A)) exch(A, B)}
#define ccmpexch(A, B){if(cless(B, A)) exch(A, B)}

typedef struct semente{
    long int cod;
    int nota;
}semente;

int partition(semente *v, int l, int r, int ord){
	semente pv = v[r];
	int j = l;
    if(ord == 0){
        for(int k = l; k < r; k++){
            if(nless(v[k], pv)){
                exch(v[k], v[j]);
                j++;
            }else if(eq(v[k].nota, pv.nota)){
                if(cless(v[k], pv)){
                    exch(v[k], v[j]);
                    j++;
                }  
                
            }
        }
    }else{
        for(int k = l; k < r; k++){
            if(cless(v[k], pv)){
                exch(v[k], v[j]);
                j++;
            }
        }
    }

	exch(v[r], v[j]);	
	return j;
}

void quickSortM3(semente *v, int l, int r, int ord){
	int j;
	int m = (r+l)/2;
	if(r <= l)
		return;
    
    ccmpexch(v[m], v[r]);
    ccmpexch(v[l], v[m]);
    ccmpexch(v[r], v[m]);

	j = partition(v, l, r, ord);
	quickSortM3(v, l, j-1, ord);
	quickSortM3(v, j+1, r, ord);
}	

int quickSelect(semente *v, int l, int r, int pos){
	int j = partition(v, l, r, 0);
	if(r == l)
		return j;
	if(j > pos)
		return quickSelect(v, l, j-1,pos);
	else if(j < pos)
		return quickSelect(v, j+1, r,pos);
	else
		return j;
}

int main(){
    int n, i = 0, k =0;
    semente *list;
    list = malloc(10000005 * sizeof(semente));
    int fim;
    scanf("%d", &n);

    while (scanf("%ld %d", &list[i].cod, &list[i].nota) != EOF){
        i++;
    }
    fim = quickSelect(list, 0, i-1, n);
    //printf("%d\n", fim);
    quickSortM3(list, 0, fim-1, 1);

    for(int j = 0; j < n; j++){
        printf("%ld %d\n", list[j].cod, list[j].nota);
    }

    return 0;
}