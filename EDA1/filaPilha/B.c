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
    celula *lixo;
    int dado;
    celula *base;
    if(fila->prox != fila){
        lixo = fila->prox;
        base = lixo->prox;
        dado = lixo->dado;
        *y = base->dado;
        fila->prox = base->prox;
        free(lixo);
    return dado;
    }
}
int main(){
    int n ,y;
    celula *fila = cria_fila();
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        enfileira(&fila, i);
        printf("Cartas descartadas: ");
    for(int i = 1; i < n; i++){
        if(i+1 != n)
            printf(" %d,",desenfileira(fila, &y));
        else
            printf(" %d",desenfileira(fila, &y));
        enfileira(&fila, y);
    }
    printf("\nCarta restante: %d\n", fila->prox->dado);

    return 0;
}