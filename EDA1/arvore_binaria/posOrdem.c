#include <stdio.h>
#include <stdlib.h>

typedef struct no {
int dado;
struct no *esq, *dir;
} no;

typedef struct celula {
   no *dado;
   struct celula *prox;
} celula;

celula * cria_pilha(){
    celula *novo = malloc(sizeof(celula));
    novo->prox = NULL;
    return novo;
}

void empilha (celula *topo, no *x){
    celula *novo = malloc(sizeof(celula));
    novo->prox = topo->prox;
    novo->dado = x;
    topo->prox = novo;
}
no *desempilha (celula *topo){
    celula *lixo;
    no *y;
    if(topo->prox != NULL){
    lixo = topo->prox;
    y = lixo->dado;
    topo->prox = lixo->prox;
    free(lixo);
    return y;
    }else
        return y;
}

void pos_ordem (no *raiz){
  if(raiz != NULL){
    celula *p1 = cria_pilha();
    celula *p2 = cria_pilha();
    no *aux = raiz;
    empilha(p1, raiz);
    while (p1->prox != NULL)
    {
      aux = desempilha(p1);
      empilha(p2, aux); 
      if(aux->esq != NULL)
        empilha(p1, aux->esq);
      if(aux->dir != NULL)
        empilha(p1, aux->dir);
    }
    while (p2->prox != NULL)
    {
      aux = desempilha(p2);
      printf("%d ", aux->dado);
    } 
  }
}