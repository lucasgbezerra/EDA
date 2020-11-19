#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *v;           // Vetor que representa a fila
  int N;            // Tamanho da fila
  int inicio, fim;  // Indicadores de inicio e final da fila
} fila;

fila *cria_fila(int tam){
    fila *f = malloc(sizeof(fila));
    f->N = tam;
    f->fim = f->inicio =0;
    f->v = malloc((f->N+1) * sizeof(int));
    return f;
}

int enfileira (fila *f, int x){
    if((f->inicio == 0) && (f->fim+1 == f->N) )
        return 0;
    f->v[f->fim] = x;
    f->fim=(f->fim+1) % f->N;
    printf("f->fim: %d\n", f->fim);
    return 1;
}
int desenfileira (fila *f, int *y){
    if(f->inicio == f->fim)
        return 0;    
    *y = f->v[f->inicio];
    f->inicio=(f->inicio+1) % f->N;
    return 1;
    
}

void imprimir(fila *f){

    for (int i = 0; i < f->N; i++)
        printf("%d-> ", f->v[i]);
    printf("\n");
}

int main()
{
    char op;
    int dado;
    int y;
    fila *fi = cria_fila(3);

    printf ("O que voce deseja fazer? (e)nfileirar, (d)esenfileirar, im(p)rimir, (s)air: ");
    scanf(" %c", &op);
    while(op != 's')
    {
        switch (op)
        {
        case 'e':
            printf("\nDigite o elemento a ser inserido: ");
            scanf("%d", &dado);
            y = enfileira(fi, dado);
            if(y == 1){
                printf("Enfileirado com SUCESSO\n");
            }else{
                printf("Fila CHEIA\n");
            }
            break;
        case 'd':
            if(desenfileira(fi, &y) == 1){
                printf("\nElemento removido da lista: %d\n\n", y);
            }else{
                printf("Fila VAZIA\n");
            }
            break;
        case 'p':
            imprimir(fi);
            break;
        default:
            printf ("Escolha uma opcao valida.\n");
            break;
        }
        printf ("O que voce deseja fazer? (e)nfileirar, (d)esenfileirar, im(p)rimir, (s)air: ");
        scanf (" %c", &op);
    }
}