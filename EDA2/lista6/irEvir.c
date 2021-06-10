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

static int cnt = 0, pre[2000];


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
    
    for(v = 1; v < V; v++)
        G->adj[v] = NULL;
    return G;
}

void GRAPHinsertE(Graph G, Edge e, int p){
    int v = e.v;
    int w = e.w;

    if(p == 1){
        G->adj[v] = NEW(w, G->adj[v]);
    }else{
        G->adj[v] = NEW(w, G->adj[v]);
        G->adj[w] = NEW(v, G->adj[w]);
    }
    G->E++;
}
// Retorna o conjunto de arestas
int GRAPHEdges(Edge *a, Graph G){
    //a: vetor alocado
    int v, E = 0;
    link t;
    for (v = 1; v < G->V; v++)
    {
        for (t = G->adj[v]; t != NULL; t = t->next)
            if(v < t->v)
                a[E++] = EDGE(v, t->v);
    }
    return E; 
}
void GRAPHshow(Graph G){
    int v;
    link ptr;
    for (v = 1; v < G->V; ++v){
        printf("%d -> ", v);
        for(ptr = G->adj[v]; ptr != NULL; ptr = ptr->next)
            printf("%d ", ptr->v);
        printf("\n");
    }
}

//Busca em profundidade com lista de adjacências
void dfsR(Graph G, Edge e){
    int  t, w = e.w;
    link l;
    pre[w] = cnt ++;
    //printf(">%d:%d\n", e.v, e.w);
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

void clean(link l){
    if(l != NULL){
        clean(l->next);
        free(l);
    }
}
void GRAPHdestroy(Graph G){
    int i;
    for(i = 1; i < G->V; i++)
        clean(G->adj[i]);
    free(G->adj);
}

void verifica(Graph G){
    int g = 1;
    int i ,v;
    for(i = 1; i < G->V && g == 1; i++){
        for(v= 0; v < G->V; v++)
            pre[v] = -1;
        cnt = 1;
        dfsR(G, EDGE(i,i));
        if(cnt != G->V)
            g = 0;
    }
    if(g == 1)
        printf("1\n");
    else
        printf("0\n");

}

int main(){
    int N, M;
    int v, w, p;
    int i;
    scanf("%d %d", &N, &M);  

    while (N != 0)
    {
        Graph graph = GRAPHinit(N+1);
        for(i = 0; i < M; i++){
            scanf("%d %d %d", &v, &w, &p);
            GRAPHinsertE(graph, EDGE(v,w), p);
            
        }
        //GRAPHshow(graph);
        verifica(graph);
        GRAPHdestroy(graph);
        scanf("%d %d", &N, &M); 
    }
    return 0;
}
