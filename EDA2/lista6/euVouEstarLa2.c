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

void lugarProibido(Graph G, int *h ,int v){
    for(link ptr = G->adj[v]; ptr != NULL; ptr = ptr->next){
        h[ptr->v] = 1;
    }
}

void verifica(int *v, int J){
    int j;
    while (J--)
    {
        scanf("%d", &j);
        if(v[j] == 1)
            printf("Eu vou estar la\n");
        else
            printf("Nao vou estar la\n");
    
    }
    
}

int main(){
    int N, M, J;
    int ni, ai;
    int *h;
    int v;

    scanf("%d %d %d", &N, &M, &J);
    h = malloc(sizeof(int) * N);

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
        scanf("%d", &v);
        h[v] = 1;
        lugarProibido(graph, h, v);
    }

    verifica(h , J);

    return 0;
}
