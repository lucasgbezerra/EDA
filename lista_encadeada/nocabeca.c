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
//não funciona quando a lista está vazia

//Inserir um elemento antes do elemento y, caso a lista não tenha y, insere no fim
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

//Impromir
void imprime(celula *le){
    for(celula *ptr = le->prox; ptr != NULL; ptr = ptr->prox){
        printf("%d -> ", ptr->dado);
    }
    printf("NULL\n");
}
// Imprimir recursivo
void imprime_rec(celula *le){
    celula *ptr = le->prox;
    if(ptr != NULL){
        printf("%d -> ", ptr->dado);
        imprime_rec(le->prox);
    }else
    {
        printf("NULL\n");
    }
}

//Busca
celula *busca (celula *le, int x){
    celula *ptr = le->prox;

    while (ptr != NULL && ptr->dado != x)
        ptr = ptr->prox;

    return ptr;
}

//Busca Recursiva
celula *busca_rec (celula *le, int x){
    if(le != NULL && le->dado != x){
        busca_rec(le->prox, x);
    }else{
        return le;
    }
}

//Desturição da lista recursiva
void destruir(celula *le){
   if(le != NULL){
       destruir(le->prox);
       free(le);
   }
}

//Remove depois do ponteiro p
int remove_depois (celula *p){
    celula *lixo;
    int dado;
    if(p->prox != NULL){
        lixo = p->prox;
        p->prox = lixo->prox;
        dado = lixo->dado;
        free(lixo);
        return dado;
    }else
        return -1;
}

//Remove o elemento x
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

void remove_todos_elementos (celula *le, int x){
    celula *lixo;
    while(le->prox != NULL)
    {
        if (le->prox->dado == x){
            lixo = le->prox;
            le->prox = lixo->prox;
            free(lixo);
        }else
        le = le->prox;
    }
    
}
//na main. Destruir(p->prox), free(p);
int main()
{

    int op = -1;
    int dado, buscado;
    celula *p;
    celula *lista = cria_lista();

    printf("Bem vindo ao CRUD de lista encadeada!\n");
    
    while(op != 0)
    {
        printf("\nEscolha uma das opções abaixo\n");
        printf("[1] Inserir elemento no inicio da lista\n");
        printf("[2] Imprimir lista\n");
        printf("[3] Imprimir lista recursivo\n");
        printf("[4] Buscar elemento na lista\n");
        printf("[5] Buscar elemento recursivo na lista\n");
        printf("[6] Inserir elemento antes de um elemento da lista\n");
        printf("[7] Remover elemento da lista\n");
        printf("[8] Remover todos elementos X's da lista\n");
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
            imprime(lista);
            break;
        case 3:
            imprime_rec(lista);
            break;
         case 4:
            printf("\nDigite o elemento a ser buscado: ");
            scanf("%d", &dado);
            p = busca (lista, dado);
            printf("\nO elemento (%d) está na posição\n\n", dado);
            break;
        case 5:
            printf("\nDigite o elemento a ser buscado: ");
            scanf("%d", &dado);
            p = busca (lista, dado);
            printf("\nO elemento (%d) está na posição\n\n", dado);
            break;
        case 6:
            printf("\nDigite o elemento a ser inserido: ");
            scanf("%d", &dado);
            printf("\nDigite após qual elemento %d sera inserido: ", dado);
            scanf("%d", &buscado);
            insere_antes(lista, dado, buscado);
            break;
        case 7:
            printf("\nDigite o elemento a ser removido: ");
            scanf("%d", &dado);
            remove_elemento(lista, dado);
            break;
        case 8:
            printf("\nDigite o elemento  x a ser removido: ");
            scanf("%d", &dado);
            remove_todos_elementos(lista, dado);
            break;
        default:
            break;
        }
    }
    destruir(lista);
    free(lista);
    return 0;
}