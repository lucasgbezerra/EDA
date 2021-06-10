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
static int cnt = 0, pre[5000];

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

void GRAPHshow(Graph G){
    for (int v = 0; v < G->V; ++v){
        printf("%d -> ", v);
        for(link ptr = G->adj[v]; ptr != NULL; ptr = ptr->next)
            printf("%d ", ptr->v);
        printf("\n");
    }
}
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
    for(v = 0; v < G->V;v++){
        if(pre[v] == -1){
            dfsR(G, EDGE(v,v));
            conexos++;
        }
    
    }
    return conexos;
}
int main(){
    int vert;
    int v, w;
    int c = 0;

    scanf("%d", &vert);
    Graph g = GRAPHinit(vert);

    while (scanf("%d %d", &v, &w) != EOF){
        GRAPHinsertE(g, EDGE(v,w));
        c++;
    }
    if(c == (vert*(vert-1))/2){
        printf("1\n");
    }else{
    if(c == 0)
        printf("%d\n",vert);
    else
        printf("%d\n",GRAPHsearch(g));
    }
    return 0;
}