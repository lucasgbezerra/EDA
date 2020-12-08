#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Inserção e remoção feitas no inicio tem melhor complexidade

typedef struct celula {
   int dado;
   int menor;
   struct celula *prox;
} celula;

celula *cria_pilha(){
    celula *novo = malloc(sizeof(celula));
    novo->prox = NULL;
    return novo;
}

void empilha (celula *topo, int x){
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = topo->prox;
    topo->prox = novo;
    if(topo->prox->prox != NULL && novo->prox->menor < novo->dado)
            novo->menor =  novo->prox->menor;
    else
        novo->menor = novo->dado;
}
void desempilha (celula *topo){
    celula *lixo;
    if(topo->prox != NULL){
    lixo = topo->prox;
    topo->prox = lixo->prox;
    free(lixo);
    }
}

int vazia(celula *topo){
    if(topo->prox == NULL)
        return 1;
    return 0;
}
int main(){
    celula *pilha = cria_pilha();
    int n, dado;
    char op[5];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", op);
        switch (op[1])
        {
        case 'U':
            scanf("%d", &dado);
            empilha(pilha, dado);
            break;
        case 'O':
            if(vazia(pilha) == 1)
                printf("EMPTY\n");
            else
                desempilha(pilha);
            break;
        case 'I':
            if(vazia(pilha) == 1)
                printf("EMPTY\n");
            else
                printf("%d\n", pilha->prox->menor);
            break;
        default:
            break;
        }
        
    }
    return 0;    
}