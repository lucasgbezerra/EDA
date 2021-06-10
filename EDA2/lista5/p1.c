// fila de prioridades baseada em indice
// a fila de prioridade irá armazenar os indices relacionados ao vetor de Item
#include <stdio.h>
#include <stdlib.h>

//typedef char Item;
#define Key(A) (placa[A]) 
#define less(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
#define exch2(A, B){int t = A; A = B; B = t;}
#define cmpexch(A, B){if(less(B, A)) exch2(A, B)}

int *placa;
int cnt = 0;
int teste = 1;
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
int PQespiamax(pq_ist *PQ){
    return PQ->pq[1];
}
void PQworkaround(pq_ist *PQ, int n){
    PQ->pq[1] = n;
    fixDown(PQ, 1, PQ->N);
}
int partition(int *v, int l, int r){
	int pv = v[r];
	int j = l;
	int aux;

	for(int k = l; k < r; k++){
		if(less(v[k], pv)){
			exch2(v[k], v[j]);
			j++;
		}
	}

	exch2(v[r], v[j]);	
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
            printf("%d ", placa[p[i]]);
        else
            printf("%d", placa[p[i]]);

    }
    printf("\n");
    free(p);
}


int main(){
    pq_ist *PQ = malloc(sizeof(pq_ist));
    placa = malloc(sizeof(int) * 101);
    int n;
    int p, t, cont = 0;
    pq_ist *PQmin;

    PQinit(102, PQ);

    while (scanf("%d %d", &p, &t) != EOF)
    {
        if(p == 1){
            if(cont < 100){
                placa[cont] = t;
                PQinsert(PQ, cont);
                cont++;
            }else{
                if(p < placa[PQespiamax(PQ)]){
                    placa[PQespiamax(PQ)] = t;
                    PQchange(PQ, PQespiamax(PQ));
                }
            }
        }else{
            PQmin = PQ;
            cnt = 0;
            teste = 1;
            imprimeHeap(PQ->pq, PQ->N, t);
        }
    }
    
    return 0;
}