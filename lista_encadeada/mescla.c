#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void mescla_listas (celula *l1, celula *l2, celula *l3){
    celula *l1ptr = l1->prox, *l2ptr = l2->prox, *l3ptr = l3;
    while (l1ptr != NULL && l2ptr != NULL)
    {
        if(l1ptr->dado < l2ptr->dado){
            l3ptr->prox = l1ptr;
            l3ptr = l3ptr->prox;
            l1ptr = l1ptr->prox;
        }else
        {
            l3ptr->prox = l2ptr;
            l3ptr = l3ptr->prox;
            l2ptr = l2ptr->prox;
        }
        
    }
    if(l1ptr != NULL)
            l3ptr->prox = l1ptr;
    if (l2ptr != NULL)
    {
        l3ptr->prox = l2ptr;
    } 

}