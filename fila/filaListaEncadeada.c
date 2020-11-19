#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void enfileira (celula **f, int x){
    celula *novo = malloc(sizeof(celula));
    novo->prox = (*f)->prox;
    (*f)->prox = novo;
    (*f)->dado = x;
    (*f) = novo;
}

int desenfileira (celula *f, int *y){
    if(f->prox == f)
        return 0;
    celula *lixo;
    lixo = f->prox;
    *y = lixo->dado;
    f->prox = lixo->prox;
    free(lixo);
    return 1;

}