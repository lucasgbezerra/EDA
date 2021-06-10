//Grafo - Lista de adjacência
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int v;
    int w;
}Edge;

typedef struct node *link;
struct node{
    int v;
    link next;
};

struct graph
{
    int V;
    int E;
    link *adj;
};
typedef struct graph* Graph;

Edge EDGE(int x, int y){
    Edge e;

    e.v = x;
    e.w = y;

    return e;
}

link NEW(int v, link next){
    link x = malloc(sizeof(*x));

    if(x == NULL)
        return NULL;
    x->v = v;
    x->next = next;

    return x;
}
Graph GRAPHinit(int V){
    int v;
    Graph G = malloc(sizeof(*G));
    
    G->V = V;
    G->E = 0;
    G->adj = malloc(V * sizeof(link)); //Inicializa uma lista
    
    for(v = 0; v < V; v++)
        G->adj[v] = NULL;
    return G;
}

void GRAPHinsertE(Graph G, Edge e){
    int v = e.v;
    int w = e.w;

     G->adj[v] = NEW(w, G->adj[v]);
     G->adj[w] = NEW(v, G->adj[w]);
     G->E++;
}
// Retorna o conjunto de arestas
int GRAPHEdges(Edge *a, Graph G){
    //a: vetor alocado
    int v, E = 0;

    for (int v = 0; v < G->V; v++)
    {
        for (link t = G->adj[v]; t != NULL; t = t->next)
            if(v < t->v)
                a[E++] = EDGE(v, t->v);
    }
    return E; 
}
void GRAPHshow(Graph G){
    for (int v = 0; v < G->V; ++v){
        printf("%d -> ", v);
        for(link ptr = G->adj[v]; ptr != NULL; ptr = ptr->next)
            printf("%d ", ptr->v);
        printf("\n");
    }
}
static int cnt = 0, pre[2000];
//Busca em profundidade com lista de adjacências
void dfsR(Graph G, Edge e){
    int  t, w = e.w;
    link l;
    pre[w] = cnt ++;

    for(l = G->adj[w]; l != NULL; l = l->next)
    {
        t = l->v;
        if(pre[t] == -1)
            dfsR(G, EDGE(w, t));
    }
}
int GRAPHsearch(Graph G){
    int v;
    int conexos = 0;
    cnt = 0;

    for(v= 0; v < G->V; v++)
        pre[v] = -1;
    for(v = 1; v < G->V;v++){
        if(pre[v] == -1){
            dfsR(G, EDGE(v,v));
            conexos++;
        }
    
    }
    return conexos;
}
int main(){
    Graph g = GRAPHinit(5);

    GRAPHinsertE(g, EDGE(0,1));
    GRAPHinsertE(g, EDGE(0,4));
    GRAPHinsertE(g, EDGE(1,2));
    GRAPHinsertE(g, EDGE(1,4));
    GRAPHinsertE(g, EDGE(2,3));
    GRAPHinsertE(g, EDGE(3,4));

    GRAPHshow(g);
    return 0;
}