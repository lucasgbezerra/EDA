#include <stdlib.h>
#include <stdio.h>

//typedef char Item;
#define Key(A) (data[A].nota) 
#define less(A, B) (Key(A) < Key(B))
#define eq(A, B) (Key(A) == Key(B))

#define lesscod(A, B) (data[A].cod < data[B].cod)
#define exch2(A, B){int t = A; A = B; B = t;}
#define cmpexch(A, B){if(lesscod(B, A)) exch2(A, B)}

typedef struct Item
{
    int cod;
    int nota;
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
    if(k > 1 && eq(PQ->pq[k/2],PQ->pq[k])){
        printf(">\n");
        if(lesscod(PQ->pq[k/2],PQ->pq[k])){
            exch(PQ,PQ->pq[k], PQ->pq[k/2]);
            k = k/2;
        }
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
int PQespiamaxNota(pq_ist *PQ){
    return data[PQ->pq[1]].nota;
}
int PQespiamaxCod(pq_ist *PQ){
    return data[PQ->pq[1]].cod;
}
int partition(int *v, int l, int r){
	int pv = v[r];
	int j = l;
	int aux;

	for(int k = l; k < r; k++){
		if(lesscod(v[k], pv)){
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

void imprimir(pq_ist *PQ){
    quickSortM3(PQ->pq, 1, PQ->N);
    for (int i = 1; i <= PQ->N; i++)
        printf("%d %d\n", data[PQ->pq[i]].cod, data[PQ->pq[i]].nota);
    
}

int main(){
    pq_ist *PQ = malloc(sizeof(pq_ist));
    int n, cont = 0;
    int x, y;
    data = malloc(sizeof(Item) * 10000);
    scanf("%d", &n);
    PQinit(n+2,PQ);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        data[cont].cod = x;
        data[cont].nota = y;
        PQinsert(PQ, cont);
        cont++;
    }
    
    while (scanf("%d %d", &x, &y) != EOF){
        printf(">%d\n", x);
        if(y < PQespiamaxNota(PQ)){
            data[cont].cod = x;
            data[cont].nota = y;
            PQDelMax(PQ);
            PQinsert(PQ,cont);
            cont++;
        }
        if(y == PQespiamaxNota(PQ) && x < PQespiamaxCod(PQ)){
            data[cont].cod = x;
            data[cont].nota = y;
            PQDelMax(PQ);
            PQinsert(PQ,cont);
            cont++;
        }
        

    }

    imprimir(PQ);

    return 0;
}