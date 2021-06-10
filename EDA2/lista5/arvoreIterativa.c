#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int dado;
  struct no *esq, *dir;
} no;

//Pilha
typedef struct pilha
{
  no *dado;
  struct pilha *prx;
}pilha;

pilha *criaPilha(){
  pilha *p = malloc(sizeof(pilha));
  p->prx = NULL;
  return p;
}

void empilha(pilha *topo, no *raiz){
  pilha *novo = malloc(sizeof(pilha));
  novo->prx = topo->prx;
  novo->dado= raiz;
  topo->prx = novo;
}

no *desempilha(pilha *topo){
  pilha *lixo;
  no *node = NULL;
  
  lixo = topo->prx;
  node = lixo->dado;
  topo->prx = lixo->prx;
  free(lixo);
  
  return node;

}

no *criaNo(int dado, no *esq, no *dir){
  no *novo = malloc(sizeof(no));
  novo->dado = dado;
  novo->esq = esq;
  novo->dir = dir;

  return novo;
}
no *criaArvore(int dado){
  no *raiz = malloc(sizeof(no));
  raiz->dado = dado;
  raiz->esq = raiz->dir = NULL;

  return raiz;
}

no *buscar(no *raiz, int k){
  no *esq;
  if(raiz == NULL || raiz->dado == k)
    return raiz;
  esq = buscar(raiz->esq, k);
  if(esq != NULL)
    return esq;
  return buscar(raiz->dir, k);
}

void *inserir(no *raiz, int k, int elem, char lado){
 //buscar o elem
 no *aux = buscar(raiz, elem);

 if(lado == 'E'){
  no *novo = criaNo(k, aux->esq, NULL);
  aux->esq = novo;
 }else{
  no *novo = criaNo(k, NULL,aux->dir);
  aux->dir = novo;
 }

}

void em_ordem(no *raiz){
  if (raiz != NULL) {
    pilha *p = criaPilha();
    no *aux = raiz;

    while (aux != NULL || p->prx != NULL)
    {
      if(aux != NULL){
        empilha(p, aux);
        aux = aux->esq;
      }else{
        aux = desempilha(p);
        printf("%d ", aux->dado);
        aux = aux->dir;
      }
    }
  }
}

void pre_ordem(no *raiz){
  if (raiz != NULL) {
    pilha *p = criaPilha();
    no *aux = raiz;

    while (aux != NULL || p->prx != NULL)
    {
      if(aux != NULL){
        if(aux->esq == NULL && aux->dir == NULL && p->prx == NULL)
          printf("%d", aux->dado);
        else
          printf("%d ", aux->dado);
        empilha(p, aux);
        aux = aux->esq;
      }else{
        aux = desempilha(p);
        aux = aux->dir;
      }
    }
  }
}

void pos_ordem(no *raiz){
  if (raiz != NULL) {
    pilha *p1 = criaPilha();
    pilha *p2 = criaPilha();
    no *aux = raiz;

    empilha(p1, raiz);
    while (p1->prx != NULL)
    {
      aux = desempilha(p1);
      empilha(p2, aux);
      if(aux->esq != NULL)
        empilha(p1, aux->esq);
      if(aux->dir != NULL)
        empilha(p1, aux->dir);
    }
    while (p2->prx != NULL)
    {
      aux = desempilha(p2);
      if(p2->prx == NULL)
        printf("%d", aux->dado);
      else
        printf("%d ", aux->dado);
    }
    
  }
}

int main(){
  int novo, elem;
  char lado;
  no *raiz = malloc(sizeof(no));
  scanf("%d", &novo);
  raiz = criaArvore(novo);
  while(scanf("%d %c %d", &novo, &lado, &elem) != EOF){
    inserir(raiz, novo, elem, lado);
  }
  printf("EM ORDEM:\n3 5 4 8 2 1 9 7 6\n");
  em_ordem(raiz);
  printf("\nPRE ORDEM:\n2 5 3 8 4 7 1 9 6\n");
  pre_ordem(raiz);
  printf("\nPOS ORDEM:\n3 4 8 5 9 1 6 7 2\n");
  pos_ordem(raiz);

  printf("\n");
  return 0;
}

