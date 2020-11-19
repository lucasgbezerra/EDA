#include <stdio.h>
#include <stdlib.h>
//Fila - FiFo
typedef struct celula {
  int dado;
  struct celula *prox;
} celula;
// Criar Fila
// O nó cabeça inicia apontadondo para si mesmo
celula *cria_fila(){
    celula *novo = malloc(sizeof(celula));
    novo->prox = novo;
    return novo;
}

//Enfileirar
//No processo de enfileirar o nó cabeça anda na lista
//Pois a forma mais barata de se inserir um elemento é no inicio

void enfileira (celula **fila, int x){
    celula *novo = malloc(sizeof(celula));
    novo->prox = (*fila)->prox;
    (*fila)->prox = novo;
    (*fila)->dado = x;
    (*fila) = novo;
}
//Desinfileirar
int desenfileira (celula *fila, int *y){
    if(fila->prox == fila)
        return 0;
    celula *lixo;
    lixo = fila->prox;
    *y = lixo->dado;
    fila->prox = lixo->prox;
    free(lixo);
    return 1;

}
void imprimir(celula *fila){

    for (celula *ptr = fila->prox; ptr != fila; ptr = ptr->prox)
        printf("%d-> ", ptr->dado);
    printf("\n");
}

int main()
{
    char op;
    int dado;
    int y;
    celula *fila = cria_fila();

    printf ("O que voce deseja fazer? (e)nfileirar, (d)esenfileirar, im(p)rimir, (s)air: ");
    scanf(" %c", &op);
    while(op != 's')
    {
        switch (op)
        {
        case 'e':
            printf("\nDigite o elemento a ser inserido: ");
            scanf("%d", &dado);
            enfileira(&fila, dado);
            break;
        case 'd':
            if(desenfileira(fila, &y) == 1){
                printf("\nElemento removido da lista: %d\n\n", y);
            }else{
                printf("Fila VAZIA\n");
            }
            break;
        case 'p':
            imprimir(fila);
            break;
        default:
            printf ("Escolha uma opcao valida.\n");
            break;
        }
        printf ("O que voce deseja fazer? (e)nfileirar, (d)esenfileirar, im(p)rimir, (s)air: ");
        scanf (" %c", &op);
    }
}