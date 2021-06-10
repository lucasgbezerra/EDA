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

void GRAPHinsertE(Graph G, Edge e, int c, int t){
    int v = e.v;
    int w = e.w;

    G->adj[v] = NEW(w, G->adj[v], c);
    if(t == 0)
        G->adj[w] = NEW(v, G->adj[w], c);
    
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
//Algoritmo Bellman Ford (menor caminho)
// Custo não é bom
bool GRAPHcptBF(Graph G, int s, int *pa, int *dist){
    bool onqueue[2001];//Quantidade de vértices G->V
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
    int V;
    int v, w, c, t;
    int x, y;
    int paC[2001], distC[2001];
    int paS[2001], distS[2001];
    int custoComSC, custoSemSC;
    int antX = -1;
    bool bf = false;

    scanf("%d", &V);
    Graph semSC = GRAPHinit(V);
    Graph comSC = GRAPHinit(V);

    scanf("%d %d %d %d", &v, &w, &c, &t);
    while (!( c == 0 && v == c && w == v && t == w)){
        if(t != 1)
            GRAPHinsertE(semSC, EDGE(v,w), c, t);
        GRAPHinsertE(comSC, EDGE(v,w), c, t);
        scanf("%d %d %d %d", &v, &w, &c, &t);
    }
    GRAPHshow(semSC);
    while (scanf("%d %d", &x, &y) != EOF)
    {
        if(antX != x){
            if(GRAPHcptBF(comSC, x, paC, distC) && paC[y] != -1){
                custoComSC = distC[y];
                if(GRAPHcptBF(semSC, x, paS, distS)){
                        bf = true;
                        custoSemSC = distS[y];
                        printf("%d %d\n", custoSemSC, custoComSC);
                }else{
                    printf("Impossibru\n");
                    bf = false;
                }
            }else{
                printf("Impossibru\n");
                bf = false;
            }
        }else{
            if(bf == true && paC[y] != -1){
                custoComSC = distC[y];
                custoSemSC = distS[y];
                printf("%d %d\n", custoSemSC, custoComSC);
            }else
            {
                printf("Impossibru\n");
            }
            
        }
        antX = x;
    }
    
    return 0;
}