//Grafo - Lista de adjacência
#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef int bool;
#define true 1
#define false 0

typedef struct {
    int v;
    int w;
}Edge;

typedef struct node *link;
struct node{
    int v;
    int c;
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

// ------------- Fila ------------------
typedef struct Queue *Fila;
 
typedef struct Node *celula;
struct Node { 
    Item item; 
    celula prox; 
};
struct Queue{
    celula ini;
    celula fim; 
}; 
 
celula NODEnew(Item item, celula prox) {
    celula x = (celula) malloc(sizeof *x);
    x->item = item; x->prox = prox; 
    return x; 
} 
 
Fila QUEUEinit(int maxE) { 
    Fila q = (Fila) malloc(sizeof *q); 
    q->ini = q->fim = NULL; 
    
    return q;
}
 
bool QUEUEempty(Fila f) {
    if(f->ini == NULL)
        return true;
    return false; 
}
 
void QUEUEput(Fila f, Item item){ 
    if (f->ini == NULL){ 
        f->fim = NODEnew(item, NULL);
        f->ini = f->fim; 
        return; 
    }
    f->fim->prox = NODEnew(item, NULL); 
    f->fim = f->fim->prox;
}
 
Item QUEUEget(Fila f){ 
    Item item = f->ini->item;
    celula t = f->ini->prox;
    free(f->ini); 
    f->ini = t;
    return item;
}
 
void QUEUEclean(Fila f){ 
    while (f->ini != NULL) { 
        celula t = f->ini->prox;
        free(f->ini);
        f->ini = t;
    }
    free(f);
}
// -------------------------------------


Edge EDGE(int x, int y){
    Edge e;

    e.v = x;
    e.w = y;

    return e;
}

link NEW(int v, link next, int c){
    link x = malloc(sizeof(*x));

    if(x == NULL)
        return NULL;
    x->v = v;
    x->next = next;
    x->c = c;

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

void GRAPHinsertE(Graph G, Edge e, int c){
    int v = e.v;
    int w = e.w;

    G->adj[v] = NEW(w, G->adj[v], c);
    G->adj[w] = NEW(v, G->adj[w], c);
    
    G->E++;
}

//Algoritmo Bellman Ford (menor caminho)
bool GRAPHcptBF(Graph G, int s, int *pa, int *dist){
    bool onqueue[1005];//Quantidade de vértices G->V
    Fila fila;
    for(int v = 0; v < G->V; v++){
        pa[v] = -1;
        dist[v] = __INT_MAX__;
        onqueue[v] = false;
    }

    //Sai do vertice pra ele mesmo
    pa[s] = s;
    dist[s] = 0;

    //Criar uma fila  das arestas
    fila = QUEUEinit(G->E);
    QUEUEput(fila, s);
    onqueue[s] = true;
    //Vertice que não existe, tamanho +1
    QUEUEput(fila ,G->V);
    //Evitar ciclos
    int k = 0;
    while(1){
        int v = QUEUEget(fila);
        if(v < G->V){
            for(link a = G->adj[v]; a != NULL; a = a->next)
            {
                if(dist[v] + a->c < dist[a->v]){
                    dist[a->v] = dist[v]+a->c;
                    pa[a->v] = v;
                    if(onqueue[a->v] == false)
                        QUEUEput(fila,a->v);
                        onqueue[a->v] = true;
                        // if(onqueue[end] == true)
                        //     return true;
                }
            }
        }else{
            if(QUEUEempty(fila))
                return true;
            if(++k > G->V)
                return false;
            QUEUEput(fila, G->V);
            for(int t = 0; t < G->V; t++)
                onqueue[t] = false;
        }
    }
}
int imprimir(int *pa, int *dist, int lim){
    for(int i = 0; i < lim; i++)
        printf("%d ", pa[i]);
    printf("\n");
    for(int i = 0; i < lim; i++)
        printf("%d ", dist[i]);
    printf("\n");
}
int main(){
    int N,M;
    int s, t, b;
    Graph g;
    int pa[1005], dist[1005];
    scanf("%d %d", &N, &M);
    
    g = GRAPHinit(N+2);

    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &s, &t, &b);
        GRAPHinsertE(g, EDGE(s, t), b);
    }

    if(GRAPHcptBF(g, 0, pa, dist))
        printf("%d\n", dist[N+1]);
    
    return 0;
}