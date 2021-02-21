#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int dado;
  struct no *l, *r;
}no;

no *criar_arvore(int x, no *l, no *r){
  no *raiz = malloc(sizeof(no));
  raiz->dado = x;
  raiz->l  = l;
  raiz->r  = r;

  return raiz;
}

no *procurar(no *raiz, int x){
  no *esq;
  if(raiz == NULL || raiz->dado == x)
    return raiz;
  esq = procurar(raiz->l, x);
  if(esq != NULL)
    return esq;
  return procurar(raiz->r, x);
}
void inserir(no *raiz, int novo_elem, int elem, char lado){
  no *procurado = procurar(raiz, elem);
  if(lado == 'L'){
    no *novo = criar_arvore(novo_elem, procurado->l, NULL);
    procurado->l = novo;
  }else
  {
    no *novo = criar_arvore(novo_elem, NULL, procurado->r);
    procurado->r = novo;
    
  }
}

//imprimir Em ordem
void em_ordem_rec (no *raiz) {
  if (raiz != NULL) {
    em_ordem_rec (raiz->l);
    printf ("%d ", raiz->dado);
    em_ordem_rec (raiz->r); 
  }
}
void pre_ordem_rec (no *raiz){
  if (raiz != NULL) {
    printf ("%d ", raiz->dado);
    pre_ordem_rec (raiz->l);
    pre_ordem_rec (raiz->r); 
  }
}
void pos_ordem_rec (no *raiz){
  if (raiz != NULL) {
    pos_ordem_rec (raiz->l);
    pos_ordem_rec (raiz->r);
    printf ("%d ", raiz->dado);

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
  printf("EM ORDEM:\n3 5 4 8 2 1 9 7 6\n");
  em_ordem_rec(raiz);
  printf("\nPRE ORDEM:\n2 5 3 8 4 7 1 9 6\n");
  pre_ordem_rec(raiz);
  printf("\nPOS ORDEM:\n3 4 8 5 9 1 6 7 2\n");
  pos_ordem_rec(raiz);

  printf("\n");
  return 0;
}