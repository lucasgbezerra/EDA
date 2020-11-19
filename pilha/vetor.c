#include <stdio.h>
#include <stdlib.h>
typedef struct {
   int *v;    // Vetor que contem os elementos da pilha
   int N;     // Tamanho de v
   int topo;  // Indicador do topo
} pilha;
pilha * cria_pilha(int tam){
    pilha *p = malloc(sizeof(pilha));
    p->N = tam;
    p->topo = 0;
    p->v = malloc(p->N * sizeof(int));
    return p;
}
void empilha (pilha *p, int x){
    if(p->topo == p->N){
        p->v = realloc(p->v,2*p->N*sizeof(int));
        p->N*=2;
    }
    p->v[p->topo] = x;
    p->topo ++;
    
}
int desempilha (pilha *p, int *y){
    if(p->topo > 0){
        p->topo--;
        *y = p->v[p->topo];
        return 1;
    }else
    {
        return 0;
    }
    
}
void imprimir(pilha *p){
    for(int i = p->topo-1; i >= 0 ; i--)
        printf("%d\n", p->v[i]);
    if(p->topo == 0)
        printf("Pilha Vazia\n");
    printf("N: %d\n", p->N);
    printf("TOPO: %d\n", p->topo);

}
int main (){
    char op;
    int dado;
    int y =0;
    pilha *pi = cria_pilha(4);
    printf ("O que voce deseja fazer? (E)pilhar, (D)esenpilhar, im(P)rimir, (S)air: ");
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