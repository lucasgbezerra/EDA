#include <stdio.h>
#include <stdlib.h>

//Inserção e remoção feitas no inicio tem melhor complexidade

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

celula * cria_pilha(){
    celula *novo = malloc(sizeof(celula));
    novo->prox = NULL;
    return novo;
}

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

void imprimir(celula *topo){
    celula *ptr = topo->prox;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->dado);
        ptr = ptr->prox;
    }
    printf("NULL\n");
}
int main (){
    char op;
    int dado;
    int y =0;
    celula *pi = cria_pilha();
    printf ("O que voce deseja fazer? (E)mpilhar, (D)esenpilhar, im(P)rimir, (S)air: ");
    scanf(" %c", &op);
    while(op != 's')
    {
        switch (op)
        {
        case 'e':
            printf("\nDigite o elemento a ser inserido: ");
            scanf("%d", &dado);
            empilha(pi, dado);
            break;
        case 'd':
            if(desempilha(pi, &y) == 1){
                printf("\nElemento removido da lista: %d\n\n", y);
            }else
            {
                printf("\nPilha Vazia\n\n");
                
            }
            break;
        case 'p':
            imprimir(pi);
            break;
        default:
            printf ("Escolha uma opcao valida.\n");
            break;
        }
        printf ("O que voce deseja fazer? (E)pilhar, (D)esenpilhar, im(P)rimir, (S)air: ");
        scanf (" %c", &op);
    }
}