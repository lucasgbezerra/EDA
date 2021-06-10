// Grafo com matriz de adjacencia
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define True 1
#define False 0

typedef struct {
    int v;
    int w;
}Edge;

struct graph
{
    int V;
    int E;
    int **adj;
};
typedef struct graph* Graph;

Edge EDGE(int x, int y){
    Edge e;

    e.v = x;
    e.w = y;

    return e;
}
//Aloca uma matriz [r-1, c-1]
static int **MATRIXInit(int l, int c, int x){
    int **m = malloc(c *sizeof(int*));

    for (int i = 0; i < c; i++)
        m[i] = calloc (i, sizeof(int));
        
    return m;
}

//Constrói um grafo com vértices 0 1 ... V-1
Graph GRAPHinit(int V){
    Graph G = malloc(sizeof(*G));
    
    G->V = V;
    G->E = 0;
    G->adj = MATRIXInit(V, V,0); //Inicializa um mattiz VxV zerada
    
    return G;
}


//Adicionar uma nova aresta
void GRAPHinsertE(Graph G, Edge e){
    //Graph G -> ponteiro pra um grafo
    int v = e.v;
    int w = e.w;

    //Se não existe uma aresta entre V e W
    if(G->adj[v][w] == 0){
        G->E++;
        G->adj[v][w] = 1;
        G->adj[w][v] = 1;
    }
}
/*
//Remover uma aresta do grafo
void GRAPHRemoveE(Graph G, Edge e){
    //Graph G -> ponteiro pra um grafo
    int v = e.v;
    int w = e.w;

    if(G->adj[v][w] == 1){
        G->E--;
        G->adj[v][w] = 0;
        G->adj[w][v] = 0;
    }
}

void GRAPHshow(Graph G){
    for (int v = 0; v < G->V; ++v){
        printf("%2d: ", v);
        for(int w = 0; w < G->V; ++w)
            if(G->adj[v][w] == 1)
                printf(" %2d", w);
        printf("\n");
    }
}
*/
bool verificaVizinho(Graph G, int v, int w){
    return G->adj[v][w];
}

void verifica(int *v, int M, int J,Graph G){
    int j;
    bool resp;
    while (J--)
    {
        resp = False;
        scanf("%d", &j);
            resp = verificaVizinho(G, j, j);
        for(int i = 0; i < M && !resp; i++)
                resp = verificaVizinho(G, v[i], j);
        
        if(resp)
            printf("Eu vou estar la\n");
        else
            printf("Nao vou estar la\n");
    
    }
    
}

int main(){
    int N, M, J;
    int ni, ai;
    int *v;
    
    scanf("%d %d %d", &N, &M, &J);
    v = malloc(sizeof(int) * M);

    Graph graph = GRAPHinit(N);
    for(int i = 0; i < N; i++){
        scanf("%d", &ni);
        while (ni--)
        {
            scanf("%d", &ai);
            GRAPHinsertE(graph, EDGE(i,ai));
        }
    }
    for(int i = 0; i < M; i++){
        scanf("%d", &v[i]);
        GRAPHinsertE(graph, EDGE(v[i],v[i]));
    }
    
    
    verifica(v, M, J,graph);

    return 0;
}