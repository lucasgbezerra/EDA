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
    Item *pqmin;
    int N;
}pq_st;

void PQinit(int maxN, pq_st *PQ){
    PQ->pq = malloc(sizeof(Item) * (maxN+1));
    PQ->pqmin = malloc(sizeof(Item) * (maxN+1));
    PQ->N = 0;
}

int PQempty(pq_st *PQ){
    return(PQ->N == 0);
}

void fixUp(pq_st *PQ, int k){
    int t = k;
    while (k > 1 && PQ->pq[k/2] < PQ->pq[k])
    {
        exch(PQ->pq[k], PQ->pq[k/2]);
        k = k/2;
    }
    while (t > 1 && PQ->pqmin[t/2] > PQ->pqmin[t])
    {
        printf(">%c\n", PQ->pqmin[t]);
        exch(PQ->pqmin[t], PQ->pqmin[t/2]);
        t = t/2;
    }
}

void fixDown(pq_st *PQ, int k, int N){
   //k: elemento
    //N tamanho da fila
    int m = k;
    int j;
    while (2*m <= N)
    {
        j = 2*m;
        if(!less(PQ->pqmin[j], PQ->pqmin[j+1]))
            j++;
        if(less(PQ->pqmin[m], PQ->pqmin[j]))
            break;    
        exch(PQ->pqmin[j], PQ->pq[m]);
        m = j;
    }
    while (2*k <= N)
    {
        j = 2*k;
        if(less(PQ->pq[j], PQ->pq[j+1]))
            j++;
        if(!less(PQ->pq[k], PQ->pq[j]))
            break;    
        exch(PQ->pq[j], PQ->pq[k]);
        k = j;
    }
    
}

void PQinsert(pq_st *PQ, int novo){
    PQ->pq[++PQ->N]= novo;
    PQ->pqmin[PQ->N]= novo;
    fixUp(PQ, PQ->N);
}

//Deleta o elemento de maior prioridade em uma fila decrescente
Item PQDelMax(pq_st *PQ){
    exch(PQ->pq[1], PQ->pq[PQ->N]);
    fixDown(PQ, 1, PQ->N - 1);
    return PQ->pq[PQ->N--];
}

Item PQDelMin(pq_st *PQ){
    exch(PQ->pqmin[1], PQ->pqmin[PQ->N]);
    fixDown(PQ, 1, PQ->N - 1);
    return PQ->pqmin[PQ->N--];
}
Bool isMaxheap(pq_st *PQ){
    if(PQ->pq[PQ->N] > PQ->pq[1])
        return false;
    return true;
}
void imprimir(pq_st *PQ){
    for (int i = 1; i <= PQ->N; i++)
        printf("[%d]%c ", i,PQ->pq[i]);
    printf("\nMIN:\n");
    for (int i = 1; i <= PQ->N; i++)
        printf("[%d]%c ", i,PQ->pqmin[i]);
    printf("\n");
    
}

int main(){
    pq_st *PQ = malloc(sizeof(pq_st));

    PQinit(15, PQ);

    // Inserindo, prioridade maior
    PQinsert(PQ,'A');
    PQinsert(PQ,'E');
  
    imprimir(PQ);
    return 0;
}