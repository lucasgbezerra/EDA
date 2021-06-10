// fila de prioridades baseada em indice
// a fila de prioridade irá armazenar os indices relacionados ao vetor de Item
#include <stdio.h>
#include <stdlib.h>

//typedef char Item;
#define Key(A) (data[A].prioridade) 
#define less(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
#define cmpexch(A, B){if(less(B, A)) exch(A, B)}

typedef struct Item
{
    char *nome;
    int prioridade;
}Item;
Item *data;

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
    PQ->pq = malloc(sizeof(int) * (maxN+1));
    PQ->qp = malloc(sizeof(int) * (maxN+1));
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
int PQDelMax(pq_ist *PQ){
    exch(PQ,PQ->pq[1], PQ->pq[PQ->N]);
    fixDown(PQ, 1, PQ->N - 1);
    return PQ->pq[PQ->N--];
}
//Troca de Prioridade
void PQchange(pq_ist *PQ, int k){
    fixUp(PQ, PQ->qp[k]);
    fixDown(PQ, PQ->qp[k], PQ->N);

}
void imprimir(pq_ist *PQ, Item *data){
    for (int i = 1; i <= PQ->N; i++)
        printf("[%d-%s] ", data[PQ->pq[i]].prioridade, data[PQ->pq[i]].nome);
    printf("\n");
    
}

int main(){
    pq_ist *PQ = malloc(sizeof(pq_ist));
    //Gerado fora da fila de prioridade e possui os elementos manipulados
    //Possui as definições da função less que sabem compor os elementos do
    //tipo Item

    data = malloc(sizeof(Item)*10);
    data[0].nome = "Iuri";
    data[0].prioridade = 74;
    data[1].nome = "Eliseu";
    data[1].prioridade = 93;
    data[2].nome = "Bruno";
    data[2].prioridade = 100;
    PQinit(15, PQ);
    PQinsert(PQ,0);
    imprimir(PQ, data);
    PQinsert(PQ,1);
    imprimir(PQ, data);
    PQinsert(PQ,2);
    imprimir(PQ, data);
    data[2].prioridade = 90;
    PQchange(PQ, 2);
    imprimir(PQ, data);
    data[0].prioridade = 95;
    PQchange(PQ, 0);
    imprimir(PQ, data);
    PQDelMax(PQ);
    imprimir(PQ, data);
    PQinsert(PQ,0);
    imprimir(PQ, data);
    return 0;
}