/*
 * Implementa��o de grafos n�o dirigidos utilizando uma
 * matriz de adjac�ncias (apenas o tri�ngulo inferior).
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct grafo {
  int n;      /* N�mero de n�s */
  int **mat;  /* Matriz (a ser alocada dinamicamente) */
} Grafo;

void cria_grafo(Grafo* g, int n)  { 
  int i;

  g->mat = calloc (n, sizeof(int*));
  g->mat[0] = NULL;
  for (i = 1; i < n; i++)
    g->mat = calloc (i, sizeof(int));
  g->n = n;
}

void destroi(Grafo *g) {
  int i;
  for (i = 1; i < g->n; i++)
    free(g->mat[i]);
  free(g->mat);
}

void adiciona_aresta(Grafo *g, int v1, int v2) {
  if (v1 > v2)
    g->mat[v1][v2] = 1;
  else
    g->mat[v2][v1] = 1;
}

int existe_aresta(Grafo *g, int v1, int v2) {
  return v1 > v2 ? g->mat[v1][v2] : g->mat[v2][v1];
}



void verifica(int *v, int M, int J,Grafo *G){
    int j;
    int resp;
    while (J--)
    {
        scanf("%d", &j);
            resp = existe_aresta(G, j, j);
        for(int i = 0; i < M && resp == 1; i++)
                resp = existe_aresta(G, v[i], j);
        
        if(resp == 1)
            printf("Eu vou estar la\n");
        else
            printf("Nao vou estar la\n");
    
    }
    
}

int main(){
    int N, M, J;
    int ni, ai;
    int *v;
    Grafo graph;

    scanf("%d %d %d", &N, &M, &J);
    v = malloc(sizeof(int) * M);

    cria_grafo(&graph,N);
    for(int i = 0; i < N; i++){
        scanf("%d", &ni);
        while (ni--)
        {
            scanf("%d", &ai);
            adiciona_aresta(&graph, i,ai);
        }
    }
    for(int i = 0; i < M; i++){
        scanf("%d", &v[i]);
        adiciona_aresta(&graph, v[i],v[i]);
    }
    
    
    verifica(v, M, J,&graph);

    return 0;
}

