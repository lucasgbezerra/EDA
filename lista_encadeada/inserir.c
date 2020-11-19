#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void insere_inicio(celula *le, int x){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL)
        exit(1);
    novo->prox = le->prox;
    le->prox = novo;
    novo->dado = x;
}

void insere_antes (celula *le, int x, int y)
{
    celula *ant;
    celula *novo = malloc(sizeof(celula));
    
    while(le != NULL && le->dado != y)
    {
        ant = le;
        le = le->prox;
    }
    novo->dado = x;
    novo->prox = ant->prox;
    ant->prox = novo;

}