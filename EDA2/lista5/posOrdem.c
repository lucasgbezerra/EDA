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

