#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

//Criação da lista
celula *cria_lista(){
    celula *le = malloc(sizeof(celula));
    if(le == NULL)
        exit(1);
    le->prox = NULL;
    return le;
}

//Inserir elemento no inicio
void insere_inicio(celula *le, int x){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL)
        exit(1);
    novo->prox = le->prox;
    le->prox = novo;
    novo->dado = x;
}

void imprime(celula *le){
    for(celula *ptr = le->prox; ptr != NULL; ptr = ptr->prox){
        printf("%d -> ", ptr->dado);
    }
    printf("NULL\n");
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

void destruir(celula *le){
   if(le != NULL){
       destruir(le->prox);
       free(le);
   }
}

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
int main()
{

    int op = -1;
    int dado, buscado;
    celula *lista = cria_lista();
    celula *l1 = cria_lista(), *l2 = cria_lista();
    printf("Bem vindo ao CRUD de lista encadeada!\n");
    
    while(op != 0)
    {
        printf("\nEscolha uma das opções abaixo\n");
        printf("[1] Inserir elemento no inicio da lista 1\n");
        printf("[2] Inserir elemento no inicio da lista 2\n");
        printf("[3] Dividir lista em l1(IMPAR) l2(PAR)\n");
        printf("[4] Mescla lista e l1 na  l2(PAR)\n");
        printf("[5] Imprimir lista\n");

        printf("[0] Sair\n");

        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\nDigite o elemento a ser inserido: ");
            scanf("%d", &dado);
            insere_inicio(lista, dado);
            break;
        case 2:
            printf("\nDigite o elemento a ser inserido: ");
            scanf("%d", &dado);
            insere_inicio(l1, dado);
            break;
        case 3:
            divide_lista(lista,l1,l2);
            break;
        case 4:
            mescla_listas(lista,l1,l2);
            break;
        case 5:
            imprime(lista);
            imprime(l1);
            imprime(l2);            
            break;
        default:
            break;
        }
    }
    destruir(lista);
    free(lista);
    destruir(l1);
    free(l1);
    destruir(l2);
    free(l2);
    return 0;
}