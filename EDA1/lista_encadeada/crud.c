#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    //struct com dois 
    int dado;
    struct no *prox;
}no;

no *cria_lista()
{
    //Cria o a lista e -> null
    no *p;
    p = NULL;
    
    return p;
}

void inserir_inicio(no **p, int dado)
{
    // cria um novo elemento da struct
    // Aloca o tamanho dinamicamente
    // Adciona o dado a struct
    // aponta para o que p(o elemento de criação) estava apontando
    // e p aponta para o novo elemento

    no *novo = malloc(sizeof(no));
    if(novo == NULL)
        exit(1); //caso o malloc dê erro ao alocar memoria
    novo->dado  = dado;
    novo->prox = *p;
    *p = novo;
}
int remover_inicio(no **p)
{
    int dado;
    no *lixo = *p;    // elemento que será removido

    *p = lixo->prox;  // p aponta para o próximo elemento ao removido

    dado  = lixo->dado; // guarda o valor do elemento

    free(lixo); // destrói o elemento
    
    return dado;
}
int buscar(no *p, int x)
{
    int contador= 0;
    for(no *ptr = p; ptr != NULL && ptr->dado != x; ptr= ptr->prox)
        contador++;
    return contador;
}
void buscar_inserir(no *p, int x,int n)
{
    no *atual, *ant;
    no *novo;
    atual =p;
    //Consertar
    // for(no *ptr = p; ptr != NULL && ptr->dado != x; ptr= ptr->prox){
    //     ant = ptr;
    //     atual = ptr->prox;
    // }
    while(atual != NULL && atual->dado != x)
    {
        ant = atual;
        atual = atual->prox;
    }
    novo = malloc(sizeof(no));
    novo->dado = n;
    if(atual != NULL){
        novo->prox = atual->prox;
        atual->prox = novo;
    }else
    {
        novo->prox = ant->prox;
        ant->prox = novo;       
    }
    
}

int remover(no *p, int x)
{
    no *lixo, *ant;
    int dado;
    lixo = p;
     while(lixo != NULL && lixo->dado != x)
    {
        ant = lixo;
        lixo = lixo->prox;
    }
    printf("lixo->dado %d\n", lixo->dado);
    printf("ant->dado %d\n", ant->dado);

    dado = lixo->dado;
    ant->prox = lixo->prox;
    free(lixo);

    return dado;

}
void imprimir(no *p)
{
    printf("p ->");
    for(no *ptr = p; ptr != NULL; ptr = ptr->prox)
        printf("%d -> ", ptr->dado);
    printf("NULL\n");
}
int main()
{
    int op = -1;
    int dado, busca;
    no *lista = cria_lista();

    printf("Bem vindo ao CRUD de lista encadeada!\n");
    
    while(op != 0)
    {
        printf("\nEscolha uma das opções abaixo\n");
        printf("[1] Inserir elemento na lista\n");
        printf("[2] Remover 1º elemento da lista\n");
        printf("[3] Imprimir lista na lista\n");
        printf("[4] Buscar elemento na lista\n");
        printf("[5] Inserir elemento após um elemento\n");
        printf("[6] Remover elemento da lista\n");
        printf("[0] Sair\n");

        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\nDigite o elemento a ser inserido: ");
            scanf("%d", &dado);
            inserir_inicio(&lista, dado);
            break;
        case 2:
            printf("\nElemento removido da lista: %d\n\n", remover_inicio(&lista));
            break;
        case 3:
            imprimir(lista);
            break;
        case 4:
            printf("\nDigite o elemento a ser buscado: ");
            scanf("%d", &dado);
            printf("\nO elemento (%d) está na posição %d\n\n", dado, buscar(lista, dado));
            break;
        case 5:
            printf("\nDigite o elemento a ser inserido: ");
            scanf("%d", &dado);
            printf("\nDigite após qual elemento %d sera inserido: ", dado);
            scanf("%d", &busca);
            buscar_inserir(lista, busca, dado);
            break;
        case 6:
            printf("\nDigite o elemento a ser removido: ");
            scanf("%d", &dado);
            printf("\nElemento removido da lista: %d\n\n", remover(lista, dado));
            break;
        default:
            break;
        }
    }
}