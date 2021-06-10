#include <stdio.h>
#include <stdlib.h>

//typedef char Item;
int *vetor;

#define Key(A) (vetor[A]) 
#define less(A, B) (Key(A) > Key(B))

typedef struct pq_ist
{
    int N;
    int *pq; //fila de prioridades(armazena os indices de um Item)
    int *qp; //mantém a posição da heap para o elemento de índice k do conjunto de Item
             //Funciona como um "hash"
}pq_ist;

void exch(pq_ist *PQ, int i, int j){
    int t;
    t = PQ->qp[i];
    PQ->qp[i] = PQ->qp[j];
    PQ->qp[j] = t;
    PQ->pq[PQ->qp[i]] = i;
    PQ->pq[PQ->qp[j]] = j;
   
}
void PQinit(int maxN, pq_ist *PQ){
    
    PQ->N = 0;
}

int PQempty(pq_ist *PQ){
    return(PQ->N == 0);
}

void fixUp(pq_ist *PQ, int k){
    while (k > 1 && less(PQ->pq[k/2],PQ->pq[k]))
    {
        exch(PQ,PQ->pq[k], PQ->pq[k/2]);
        k = k/2;
    }
    
}

void fixDown(pq_ist *PQ, int k, int N){
    int j;

    while (2*k <= N)
    {
        j = 2*k;
        if(j < N && less(PQ->pq[j],PQ->pq[j+1]))
            j++;
        if(!less(PQ->pq[k],PQ->pq[j]))
            break;
        exch(PQ,PQ->pq[k], PQ->pq[j]);
        k = j;
    }
    
}

void PQinsert(pq_ist *PQ, int k){
    PQ->qp[k]= ++PQ->N;
    PQ->pq[PQ->N]= k;
    fixUp(PQ, PQ->N);
}

//Deleta o elemento de maior prioridade em uma fila decrescente
int PQDelMin(pq_ist *PQ){
    exch(PQ,PQ->pq[1], PQ->pq[PQ->N]);
    fixDown(PQ, 1, PQ->N - 1);
    return PQ->pq[PQ->N--];
}
//Troca de Prioridade
void PQchange(pq_ist *PQ, int k){
    fixUp(PQ, PQ->qp[k]);
    fixDown(PQ, PQ->qp[k], PQ->N);

}

int PQespiamin(pq_ist *PQ,int *v){
    return v[PQ->pq[1]];
}
//Para entender essa é mais simples

void resolve(pq_ist *PQ,int n, int k, int *v){
    PQinit(k+1, PQ);
    vetor = v;
    for (int i = 0; i < k; i++)
        PQinsert(PQ, i);
    printf("%d", PQespiamin(PQ, v));
    v[0] = 0;
    PQchange(PQ, 0);
    PQDelMin(PQ);
    int maisVelho = 1;
    int nexti = k;
    while (nexti < n)
    {
        PQinsert(PQ, nexti);
        nexti++;
        printf(" %d", PQespiamin(PQ, v));
        v[maisVelho] = 0;
        PQchange(PQ, maisVelho);
        PQDelMin(PQ);
        maisVelho++;

    }
    printf("\n");
}
int main(){
    pq_ist *PQ = malloc(sizeof(pq_ist));
    PQ->pq = malloc(sizeof(int) * (100002));
    PQ->qp = malloc(sizeof(int) * (100002));
    int v[100002];
    int n, k;

    scanf("%d %d", &n, &k);
    while(n != 0 && k != 0){
        for (int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        resolve(PQ, n, k, v);
        scanf("%d %d", &n, &k);
    
    }
    
    return 0;
}