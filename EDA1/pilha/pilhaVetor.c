#include <stdio.h>
#include <stdlib.h>
typedef struct {
   int *v;    // Vetor que contem os elementos da pilha
   int N;     // Tamanho de v
   int topo;  // Indicador do topo
} pilha;

void empilha (pilha *p, int x){
    if(p->topo == p->N){
        p->v = realloc(p->v,2*p->N*sizeof(int));
        p->N=p->N*2;
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