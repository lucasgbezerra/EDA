// Fila de prioridades simples
#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define Key(A) (A) 
#define less(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
#define exch(A, B){Item t = A; A = B; B = t;}
#define cmpexch(A, B){if(less(B, A)) exch(A, B)}

static Item *pq;
static int N;

void PQInit(int maxN){
    pq = malloc(sizeof(Item) * (maxN+1));
    N = 0;
}

int PQEmpty(){
    return (N == 0);
}
void fixUp(Item *v, int k){
        while (k > 1 && less(v[k/2], v[k]))
        {
            exch(v[k], v[k/2]);
            k = k/2;
        }
        
}
void fixDown(Item *v, int k, int N){
    //k: elemento
    //N tamanho da fila
    int j;

    while (2*k <= N)
    {
        j = 2*k;
        if(less(v[j], v[j+1]))
            j++;
        if(!less(v[k], v[j]))
            break;    
        exch(v[j], v[k]);
        k = j;
    }
    
}
void PQInsert(Item novo){
    pq[++N] = novo;
    fixUp(pq, N);
}
void imprimir(){
    for(int i = 1; i <= N; i++)
        printf("[%d]%d ", i,pq[i]);
    printf("\n");
}
int main(){
    PQInit(10);
    // Inserindo, prioridade maior
    PQInsert(1);
    PQInsert(2);
    PQInsert(3);
    PQInsert(4);
    PQInsert(5);
   
    imprimir();

    return 0;
}