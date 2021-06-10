// Grafo com matriz de adjacencia
#include <stdio.h>
#include <stdlib.h>

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
        m[i] = malloc(l * sizeof(int));
    
    for (int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
            m[i][j] = 0;
    }
    
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


int main(){
    Graph graph = GRAPHinit(5);
    GRAPHinsertE(graph, EDGE(0,1));
    GRAPHinsertE(graph, EDGE(0,4));
    GRAPHinsertE(graph, EDGE(1,2));
    GRAPHinsertE(graph, EDGE(1,4));
    GRAPHinsertE(graph, EDGE(2,3));
    GRAPHinsertE(graph, EDGE(3,4));

    GRAPHshow(graph);

    return 0;
}