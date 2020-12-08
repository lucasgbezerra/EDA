#include <stdio.h>
#include <stdlib.h>

//Inserção e remoção feitas no inicio tem melhor complexidade

typedef struct celula {
   char dado;
   struct celula *prox;
} celula;

celula *cria_pilha(){
    celula *novo = malloc(sizeof(celula));
    novo->prox = NULL;
    return novo;
}

void empilha (celula *topo, char x){
    celula *novo = malloc(sizeof(celula));
    novo->prox = topo->prox;
    novo->dado = x;
    topo->prox = novo;
    
}
int desempilha (celula *topo){
    celula *lixo;
    if(topo->prox != NULL){
    lixo = topo->prox;
    topo->prox = lixo->prox;
    free(lixo);
    return 1;
    }else
        return 0;
}
int vazia(celula *topo){
    if(topo->prox == NULL)
        return 1;
    return 0;
}
int main(){
    celula *v[31];
    int tam, pares = 0;
    char l;
    //Criando as pilhas
    for (int i = 0; i < 31; i++)
        v[i] = cria_pilha();
    while (scanf("%d %c", &tam, &l) != EOF)
    {
        if(vazia(v[tam-30]) == 1)
            empilha(v[tam-30], l);
        else
        {
            if(v[tam-30]->prox->dado != l)
                pares += desempilha(v[tam-30]);
            else
                empilha(v[tam-30], l);
        }
    }
    printf("%d\n", pares);    
    return 0;    
}