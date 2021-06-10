#include <stdio.h>
#include <stdlib.h>

typedef struct semente {
  int codigo;
  int qualidade;
} semente;

typedef semente Item;
#define Key(A) (A.qualidade) 
#define KeyPrint(A) (A.codigo) 

#define less(A, B) (Key(A) < Key(B))
#define lessPrint(A, B) (KeyPrint(A) < KeyPrint(B))
#define lesseq(A, B) (Key(A) <= Key(B))

#define exch(A, B) { Item t = A; A = B; B = t; }

typedef struct pq_st {
  Item *pq;
  int N;
} pq_st;

void PQinit(int maxN, pq_st *PQ){
  PQ->pq = malloc(sizeof(Item) * (maxN + 1));
  PQ->N = 0;
}

int PQempty(pq_st *PQ){
  return PQ->N == 0;
}

// HEAP decrescente "estragada"
void fixUp(Item *v, int k){
  while(k > 1 && less(v[k/2], v[k])){
    exch(v[k], v[k/2]);
    k = k/2;
  }
}

// HEAP decrescente "estragada", conserta-de-cima-para-baixo
void fixDown(Item *v, int k, int N) {
  // N é o tamanho da HEAP para evitarmos acessar local da memória não alocado.
  int j;
  while(2*k <= N){
    j = 2*k;
    if(j < N && less(v[j], v[j+1]))
      j++;
    
    if(!less(v[k], v[j]))
      break;

    exch(v[k], v[j]);
    k = j;
  }
}

void fixDownPrint(Item *v, int k, int N) {
  // N é o tamanho da HEAP para evitarmos acessar local da memória não alocado.
  int j;
  while(2*k <= N){
    j = 2*k;
    if(j < N && lessPrint(v[j], v[j+1]))
      j++;
    
    if(!lessPrint(v[k], v[j]))
      break;

    exch(v[k], v[j]);
    k = j;
  }
}

void PQinsert(pq_st *PQ, Item novo){
  PQ->pq[++PQ->N] = novo;
  fixUp(PQ->pq, PQ->N);
}

void PQworkaroundMax(pq_st *PQ, Item x){
  PQ->pq[1] = x;
  fixDown(PQ->pq, 1, PQ->N);
}

Item PQdelMax(pq_st *PQ) {
  exch(PQ->pq[1], PQ->pq[PQ->N]);
  fixDown(PQ->pq, 1, PQ->N-1);
  return PQ->pq[PQ->N--];
}

Item PQespiaMax(pq_st *PQ){
  return PQ->pq[1];
}

void heapsort(Item *v, int l, int r){
	int k, N = r-l+1;

	Item *pq = v+l-1;

	for(k = N/2; k>=1;k--)
		fixDownPrint(pq,k,N);

	while(N>1)
	{
		exch(pq[1],pq[N]);
		fixDownPrint(pq,1,--N);
	}
}

int main(){

  pq_st listaPrioridade;

  int tamanho;
  scanf("%d", &tamanho);

  PQinit(tamanho + 1, &listaPrioridade);

  Item x;

  for(int i = 0; i < tamanho; i++){
      scanf("%d %d", &x.codigo, &x.qualidade);
      PQinsert(&listaPrioridade, x);
  }

  while(scanf("%d %d", &x.codigo, &x.qualidade) != EOF){
    if(x.qualidade == PQespiaMax(&listaPrioridade).qualidade){
      if(x.codigo < PQespiaMax(&listaPrioridade).codigo)
        PQworkaroundMax(&listaPrioridade, x);
    }
    
    else if(x.qualidade < PQespiaMax(&listaPrioridade).qualidade)
      PQworkaroundMax(&listaPrioridade, x);
  }

  printf("\n");
  //Imprimir
  heapsort(listaPrioridade.pq, 1, listaPrioridade.N);

  for(int i = 1; i <= listaPrioridade.N; i++)
    printf("%d %d\n", listaPrioridade.pq[i].codigo, listaPrioridade.pq[i].qualidade);
  
}