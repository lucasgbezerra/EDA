// fila de prioridade com mais de um prioridade possivel
#include <stdio.h>
#include <stdlib.h>

typedef char Item;
typedef char* Bool;
#define true "Máximo"
#define false "Minimo"
#define Key(A) (A) 
#define less(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
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
    while (k > 1 && pq[k/2] < pq[k])
    {
        exch(pq[k], pq[k/2]);
        k = k/2;
    }
    
}

void fixDown(Item *pq, int k, int N){
   //k: elemento
    //N tamanho da fila
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
    fixDown(PQ->pq, 1, PQ->N - 1);
    return PQ->pq[PQ->N--];
}

Bool isMaxheap(pq_st *PQ){
    if(PQ->pq[PQ->N] > PQ->pq[1])
        return false;
    return true;
}
void imprimir(pq_st *PQ){
    for (int i = 1; i <= PQ->N; i++)
        printf("[%d]%c ", i,PQ->pq[i]);
    printf("\n");
    
}

int main(){
    pq_st *PQ = malloc(sizeof(pq_st));

    PQinit(15, PQ);

    // Inserindo, prioridade maior
    PQinsert(PQ,'E');
    PQinsert(PQ,'A');
    PQinsert(PQ,'S');
    PQinsert(PQ,'Y');
    //imprimir(PQ);
    PQinsert(PQ,'Q');
    PQinsert(PQ,'U');
    PQinsert(PQ,'E');
    imprimir(PQ);

    PQinsert(PQ,'S');
    PQinsert(PQ,'T');
    PQinsert(PQ,'I');

    PQinsert(PQ,'O');
    PQinsert(PQ,'N');
    printf("%s\n", isMaxheap(PQ));
    imprimir(PQ);
    return 0;
}