#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;
void divide_lista (celula *l, celula *l1, celula *l2){
    celula *lptr = l->prox, *l1ptr = l1, *l2ptr = l2;
    while (lptr != NULL)
    {
    
        if(lptr->dado % 2 != 0){
            l1ptr->prox = lptr;
            l1ptr = l1ptr->prox;
            lptr = lptr->prox;
        }else
        {
            l2ptr->prox = lptr;
            l2ptr = l2ptr->prox;
            lptr = lptr->prox;
        }
        if(lptr == NULL){
            if(l1ptr->prox != NULL)
                l1ptr->prox = NULL;
            if (l2ptr->prox != NULL)
                l2ptr->prox = NULL;
            
        }
    }

}