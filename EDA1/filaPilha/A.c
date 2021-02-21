#include <stdio.h>
#include <stdlib.h>

//Inserção e remoção feitas no inicio tem melhor complexidade

typedef struct celula {
   char dado;
   struct celula *prox;
} celula;

celula * cria_pilha(){
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

int desempilha (celula *topo, char y){
    if(topo->prox != NULL){
        if(topo->prox->dado == y){
            celula *lixo = topo->prox;
            topo->prox = lixo->prox;
            free(lixo);
        }
    }
    return 1;
}

int vazia(celula *topo){
    if(topo->prox == NULL)
        return 1;
    return 0;
}

int main(){
    char str[502];
    celula *pilha = cria_pilha();
    int cont = 0;

    scanf("%s", str);
    for(int i = 0;str[i] != '\0'; i++){
        if(str[i] == '{' || str[i] == '[' || str[i] == '('){
            empilha(pilha, str[i]);
            cont--;
        }
        switch (str[i])
        {
        case '}':
            cont+=desempilha(pilha, '{');
            break;
        case ']':
            cont+=desempilha(pilha, '[');
            break;
        case ')':
            cont+=desempilha(pilha, '(');
            break;
        default:
            break;
        }
    }
    if(cont == 0 && vazia(pilha) == 1)
        printf("sim\n");
    else
        printf("nao\n");
    return 0;
}