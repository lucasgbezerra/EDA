#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void imprime(celula *le){
    for(celula *ptr = le->prox; ptr != NULL; ptr = ptr->prox){
        printf("%d -> ", ptr->dado);
    }
    printf("NULL\n");
}
// Imprimir recursivo
void imprime_rec(celula *le){
    celula *ptr = le->prox;
    if(ptr != NULL){
        printf("%d -> ", ptr->dado);
        imprime_rec(le->prox);
    }else
    {
        printf("NULL\n");
    }
    
}