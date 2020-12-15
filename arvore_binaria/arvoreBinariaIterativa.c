#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int dado;
  struct no *esq, *dir;
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
no *criar_arvore(int x, no *l, no *r){
  no *raiz = malloc(sizeof(no));
  raiz->dado = x;
  raiz->esq  = l;
  raiz->dir  = r;

  return raiz;
}

no *procurar(no *raiz, int x){
  no *esq;
  if(raiz == NULL || raiz->dado == x)
    return raiz;
  esq = procurar(raiz->esq, x);
  if(esq != NULL)
    return esq;
  return procurar(raiz->dir, x);
}
void inserir(no *raiz, int novo_elem, int elem, char lado){
  no *procurado = procurar(raiz, elem);
  if(lado == 'L'){
    no *novo = criar_arvore(novo_elem, procurado->esq, NULL);
    procurado->esq = novo;
  }else
  {
    no *novo = criar_arvore(novo_elem, NULL, procurado->dir);
    procurado->dir = novo;
    
  }
}

//imprimir Em ordem

void em_ordem (no *raiz){
  if(raiz != NULL){
    celula *pi = cria_pilha();
    no *aux = raiz;
    while (aux != NULL || pi->prox != NULL)
    {
      if(aux != NULL){
        empilha(pi, aux);
        aux = aux->esq;
      }else
      {
        aux = desempilha(pi);
        printf("%d ", aux->dado);
        aux = aux->dir;
      }
      
    } 
  }
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
        aux = aux->esq;
      }else
      {
        aux = desempilha(pi);
        aux = aux->dir;
      }
      
    } 
  }
}
void imprimir(celula *topo){
    celula *ptr = topo->prox;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->dado->dado);
        ptr = ptr->prox;
    }
    printf("NULL\n");
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

int main(){
  int novo, elem;
  char lado;
  no *raiz = malloc(sizeof(no));
  scanf("%d", &novo);
  raiz = criar_arvore(novo, NULL, NULL);
  while(scanf("%d %c %d", &novo, &lado, &elem) != EOF){
    inserir(raiz, novo, elem, lado);
  }
  // printf("EM ORDEM:\n3 5 4 8 2 1 9 7 6\n");
  // em_ordem(raiz);
  // printf("\nPRE ORDEM:\n2 5 3 8 4 7 1 9 6\n");
  // pre_ordem(raiz);
  printf("\nPOS ORDEM:\n3 4 8 5 9 1 6 7 2\n");
  pos_ordem(raiz);

  printf("\n");
  return 0;
}
