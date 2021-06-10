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

void pre_ordem(no *raiz){
  if (raiz != NULL) {
    pilha *p = criaPilha();
    no *aux = raiz;

    while (aux != NULL || p->prx != NULL)
    {
      if(aux != NULL){
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
