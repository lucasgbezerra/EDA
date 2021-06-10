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
static int cnt = 0, pre[2001];
static int percurso = 0;

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

void GRAPHinsertE(Graph G, Edge e, int d){
    int v = e.v;
    int w = e.w;

     G->adj[v] = NEW(w, G->adj[v]);
     if(d == 2)
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

//Busca em profundidade com lista de adjacências
void dfsR(Graph G, Edge e, int end){
    int  t, w = e.w;
    link l;
    pre[w] = cnt++;
    for(l = G->adj[w]; l != NULL; l = l->next)
    {
        t = l->v;
        if(t == end)
            percurso = 1;
        if(percurso == 1)
            return;
        if(pre[t] == -1)
            dfsR(G, EDGE(w, t), end);
    }
}

int GRAPHsearch(Graph G, Edge e){
    int v;
    percurso = 0;
    cnt = 0;

    for(v= 0; v < G->V; v++)
        pre[v] = -1;
    dfsR(G, EDGE(e.v, e.v), e.w);
    
    
    return percurso;
}
int main(){
    int V;
    int v, w, d;
    int t, x;
    int ida , volta, resp;

    scanf("%d", &V);
    Graph g = GRAPHinit(V);

    scanf("%d %d %d", &v, &w, &d);
    while (!( d == 0 && v == d && w == v)){
        GRAPHinsertE(g, EDGE(v,w), d);
        scanf("%d %d %d", &v, &w, &d);
    }
    while (scanf("%d %d", &t, &x) != EOF)
    {
        
        ida = GRAPHsearch(g, EDGE(t, x));
        volta = GRAPHsearch(g, EDGE(x, t)) + 1;

        resp = ida + volta;
        switch (resp)
        {
        case 0:
            printf("Impossibru\n");
            break;
        case 1:
            printf("Apenas Ida\n");
            break;
        case 2:
            printf("Apenas Volta\n");
            break;
        case 3:
            printf("Ida e Volta\n");
            break;
        default:
            break;
        }
    }
    
    return 0;
}