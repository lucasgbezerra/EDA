// fila de prioridade com mais de um prioridade possivel
#include <stdio.h>
#include <stdlib.h>

#define Key(A) (A) 
#define less(A, B) (Key(A) < Key(B))
#define exch(A, B){int t = A; A = B; B = t;}
#define cmpexch(A, B){if(less(B, A)) exch(A, B)}


typedef struct pq_st
{
    int *pq;
    int N;
}pq_st;

void PQinit(int maxN, pq_st *PQ){
    PQ->pq = malloc(sizeof(int) * (maxN+1));
    PQ->N = 0;
}

int PQempty(pq_st *PQ){
    return(PQ->N == 0);
}

void fixUp(int *pq, int k){
    while (k > 1 && less(pq[k/2], pq[k]))
    {
        exch(pq[k], pq[k/2]);
        k = k/2;
    }
    
}

void fixDown(int *pq, int k, int N){
    int j;

    while (2*k <= N)
    {
        j = 2*k;
        if(j < N && less(pq[j], pq[j+1]))
            j++;
        if(!less(pq[k], pq[j]))
            break;    
        exch(pq[j], pq[k]);
        k = j;
    }
    
}

void PQinsert(pq_st *PQ, int novo){
    PQ->pq[++PQ->N]= novo;
    fixUp(PQ->pq, PQ->N);
}

//Deleta o elemento de maior prioridade em uma fila decrescente
int PQDelMax(pq_st *PQ){
    exch(PQ->pq[1], PQ->pq[PQ->N]);
    fixDown(PQ->pq, 1, --PQ->N);
    return PQ->pq[PQ->N+1];
}


int PQespiaMax(pq_st *PQ){
    return PQ->pq[1];
}
void PQworkaround(pq_st *PQ, int n){
    PQ->pq[1] = n;
    fixDown(PQ->pq, 1, PQ->N);
}

int partition(int *v, int l, int r){
	int pv = v[r];
	int j = l;
	int aux;

	for(int k = l; k < r; k++){
		if(less(v[k], pv)){
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
void imprimeHeap(int *pq, int n,int t){
    int *p = malloc(sizeof(int) *n+2);
    for (int i = 1; i <= n; i++)
        p[i] = pq[i];
    
    quickSortM3(p, 1, n);
    for (int i = 1; i <= t; i++){
        if(i != t)
            printf("%d ", p[i]);
        else
            printf("%d", p[i]);

    }
    printf("\n");
    free(p);
}


int main(){
    pq_st *PQ = malloc(sizeof(pq_st));
    int n;
    int p, t, cont = 0;

    PQinit(102, PQ);
    PQinit(102, PQ);

   while (scanf("%d %d", &p, &t) != EOF)
    {
        if(p == 1){
            if(cont <= 100){
                PQinsert(PQ, t);
                cont++;
            }else{
                if(p < PQespiaMax(PQ)){
                    PQworkaround(PQ, t);
                }
            }
        }else{
            imprimeHeap(PQ->pq, PQ->N,t);
        }
    }
    return 0;
}