#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

int remove_depois (celula *p){
    celula *lixo;
    int dado;
    if(p->prox != NULL){
        lixo = p->prox;
        p->prox = lixo->prox;
        dado = lixo->dado;
        free(lixo);
        return dado;
    }else
        return -1;
}

void remove_elemento (celula *le, int x){
    celula *lixo;
    
    while(le->prox != NULL && le->prox->dado != x)
    {
        le = le->prox;
    }
    if(le->prox != NULL){
        lixo = le->prox;
        le->prox = lixo->prox;
        free(lixo);
    }
}

void remove_todos_elementos (celula *le, int x){
    celula *lixo;
    while(le->prox != NULL)
    {
        if (le->prox->dado == x){
            lixo = le->prox;
            le->prox = lixo->prox;
            free(lixo);
        }else
        le = le->prox;
    }
    
}