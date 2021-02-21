#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int dado;
  struct no *l, *r;
}no;

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

void pre_ordem (no *raiz){
  if(raiz != NULL){
  celula *pi = cria_pilha();
      no *aux = raiz;
    while (aux != NULL || pi->prox != NULL)
    {
      if(aux != NULL){
        printf("%d ", aux->dado);
        empilha(pi, aux);
        aux = aux->l;
      }else
      {
        aux = desempilha(pi);
        aux = aux->r;
      }
      
    } 
  }
}