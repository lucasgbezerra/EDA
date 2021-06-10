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

struct conexo{
    int numV;
    int menorV;
};

static int cnt = 0, pre[5000];
static int cont = 0;

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
    
    cont++;
    pre[w] = cnt;
    for(l = G->adj[w]; l != NULL; l = l->next)
    {
        t = l->v;
        if(pre[t] == -1)
            dfsR(G, EDGE(w, t));
    }
}
void decisao(Graph g, struct conexo c, int J){
    if(pre[J] == pre[c.menorV])
        printf("Bora pra estrada\n");
    else if(pre[J] != pre[c.menorV])
        printf("Vamos para %d\n", c.menorV);
}

void GRAPHsearch(Graph G, int J){
    int v;
    struct conexo c;
    int numJ = 0;
    int maiorConexo = 0;
    cnt = 0;

    for(v= 0; v < G->V; v++)
        pre[v] = -1;

    dfsR(G, EDGE(J,J));
    numJ = cont;
    cnt++;
    c.numV = numJ;
    c.menorV = J;
    for(v = 0; v < G->V;v++){
        cont = 0;
        if(pre[v] == -1){
            dfsR(G, EDGE(v,v));
            cnt++;
            if(cont > c.numV){
                c.numV = cont;
                c.menorV = v;
            }
            
            if(cont == c.numV){
                if(v < c.menorV && c.numV > numJ){
                    c.numV = cont;
                    c.menorV = v;
                }
            }
        }
    }
    
    decisao(G, c, J);
}

int main(){
    int V, J;
    int v, w;
    int c = 0;

    scanf("%d %d", &V, &J);
    Graph g = GRAPHinit(V);

    while (scanf("%d %d", &v, &w) != EOF){
        GRAPHinsertE(g, EDGE(v,w));
        c++;
    }
    if(c == 0)
        printf("Fique em casa\n");
    else
        GRAPHsearch(g, J);

    return 0;
}