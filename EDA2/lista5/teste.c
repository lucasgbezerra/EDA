#include <stdio.h>
#include <stdlib.h>

#define Key(A) (data[A].nota) 
#define less(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
#define cmpexch(A, B){if(less(B, A)) exch(A, B)}

typedef struct Item
{
    int nota;
}Item;
Item *data;
typedef struct pq_ist
{
    int N;
    int *pq; 
    int *qp; 
}pq_ist;
pq_ist *PQ;

void exch(int i, int j){
    int t;
    t = PQ->qp[i];
    PQ->qp[i] = PQ->qp[j];
    PQ->qp[j] = t;
    PQ->pq[PQ->qp[i]] = i;
    PQ->pq[PQ->qp[j]] = j;
   
}
void PQinit(int maxN){
    PQ->pq = malloc(sizeof(int) * (maxN+1));
    PQ->qp = malloc(sizeof(int) * (maxN+1));
    PQ->N = 0;
}

int PQempty(){
    return(PQ->N == 0);
}

void fixUp(int k){
    while (k > 1 && less(PQ->pq[k/2],PQ->pq[k]))
    {
        exch(PQ,PQ->pq[k], PQ->pq[k/2]);
        k = k/2;
    }
    
}

void fixDown(int k, int N){
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

void PQinsert(int k){
    PQ->qp[k]= ++PQ->N;
    PQ->pq[PQ->N]= k;
    fixUp(PQ, PQ->N);
}

Item PQDelMax(){
    exch(PQ,PQ->pq[1], PQ->pq[PQ->N]);
    fixDown(PQ, 1, PQ->N - 1);
    return PQ->pq[PQ->N--];
}
void PQchange(int k){
    fixUp(PQ, PQ->qp[k]);
    fixDown(PQ, PQ->qp[k], PQ->N);

}
Item PQespiamin(){
    return data[PQ->pq[1]].nota;
}
void imprimir(){
    for (int i = 1; i <= PQ->N; i++)
        printf("[%d-%s] ", data[PQ->pq[i]].prioridade, data[PQ->pq[i]].nome);
    printf("\n");
    
}


int main(){
    int n, k;
    int x, cont =0;

    data = malloc(sizeof(Item) * 100002);
    PQinit(100002);
    while (scanf("%d %d", &n, &k) && k != 0 && n != 0 )
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            if(i < k)
                data[cont++].nota = x;
                PQinsert(cont);
            }else{
                if(i%k == 0)
                    cont = 0;
                printf("%d ", PQespiamin());
                data[cont++].nota = x;
                PQchange(cont);
            }
        }
    }
    
    
    
}