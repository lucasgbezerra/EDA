// fila de prioridade com mais de um prioridade possivel
#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define Key(A) (A) 
#define less(A, B) (Key(A) < Key(B))
#define exch(A, B){Item t = A; A = B; B = t;}
#define cmpexch(A, B){if(less(B, A)) exch(A, B)}


typedef struct pq_st
{
    Item *pq;
    int N;
}pq_st;

void PQinit(int maxN, pq_st *PQ){
    PQ->pq = malloc(sizeof(Item) * (maxN+1));
    PQ->N = 0;
}

int PQempty(pq_st *PQ){
    return(PQ->N == 0);
}

void fixUp(Item *pq, int k){
    while (k > 1 && less(pq[k/2], pq[k]))
    {
        exch(pq[k], pq[k/2]);
        k = k/2;
    }
    
}

void fixDown(Item *pq, int k, int N){
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
Item PQDelMax(pq_st *PQ){
    exch(PQ->pq[1], PQ->pq[PQ->N]);
    fixDown(PQ->pq, 1, --PQ->N);
    return PQ->pq[PQ->N+1];
}


Item PQespiaMax(pq_st *PQ){
    return PQ->pq[1];
}
void PQworkaround(pq_st *PQ, int n){
    PQ->pq[1] = n;
    fixDown(PQ->pq, 1, PQ->N);
}
void imprimeHeap(pq_st *PQ){
    if(PQempty(PQ))
        return;
    int x = PQDelMax(PQ);
    imprimeHeap(PQ);
    printf("%d ", x);
    
}


int main(){
    pq_st *PQ = malloc(sizeof(pq_st));
    int n;

    PQinit(12, PQ);

    for(int i = 0; i < 10; i++){
        scanf("%d", &n);
        PQinsert(PQ, n);
    }

    while (scanf("%d", &n) != EOF)
    {
        if(n < PQespiaMax(PQ)){
            PQworkaround(PQ, n);
        }
    }    
    imprimeHeap(PQ);
    printf("\n");
    return 0;
}