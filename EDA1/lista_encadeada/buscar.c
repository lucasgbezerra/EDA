#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

celula *busca (celula *le, int x){
    celula *ptr = le->prox;

    while (ptr != NULL && ptr->dado != x)
        ptr = ptr->prox;

    return ptr;
}

//Busca Recursiva
celula *busca_rec (celula *le, int x){
    if(le != NULL && le->dado != x){
        busca_rec(le->prox, x);
    }else{
        return le;
    }
}
