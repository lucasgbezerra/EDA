#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void empilha (celula *topo, int x){
    celula *novo = malloc(sizeof(celula));
    novo->prox = topo->prox;
    novo->dado = x;
    topo->prox = novo;
}
int desempilha (celula *topo, int *y){
    celula *lixo;
    if(topo->prox != NULL){
    lixo = topo->prox;
    *y = lixo->dado;
    topo->prox = lixo->prox;
    free(lixo);
    return 1;
    }else
        return 0;
}