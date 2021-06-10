#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>


static int *queue;
static int begin, end;

void QUEUEinit(int N){
    queue = malloc(N * sizeof(int));
    begin = 0;
    end = 0;
}

bool QUEUEempty(){
    return begin == end;
}

void QUEUEput(int v){
    queue[end++] = v;
}

int QUEUEget(){
    return queue[begin++];
}

void QUEUEfree(){
    free(queue);
}

typedef struct graph *Graph;
typedef struct node *link;
typedef struct {int v; int w;} Edge;
Edge EDGE(int v, int w){
    Edge tmp;
    tmp.v = v;
    tmp.w = w;
    return tmp;
}


typedef struct node{
    int w;
    int c;
    link next;
}node;

typedef struct graph {
    int V;
    int A;
    link *adj; 
}graph;

node * novoNo(int  w, int c, node * next ){
    link novo = malloc(sizeof(node));
    novo->w = w;
    novo->c = c;
    novo->next = next;
    return novo;
}

Graph GraphInit(int V){
    Graph G = malloc(sizeof *G);
    G->V = V;
    G->A = 0;
    G->adj = malloc(sizeof(link) * V);
    for(int i =0; i<V; i++)
        G->adj[i] = NULL;
    return G;
}

void GraphInsere(Graph G, Edge e, int c, int t){
    G->adj[e.v] = novoNo(e.w, c ,G->adj[e.v]);
    if(t == 0){
        G->adj[e.w] = novoNo(e.v, c ,G->adj[e.w]);
        G->A++;
    }

    G->A++;
}
int GraphArestas(Edge a[], Graph g){
    int v, E = 0;
    link t;
    for(v = 0; v < g->V; v++){
        for(t = g->adj[v]; t!= NULL; t = t->next ){
            if(v < t->w) 
                a[E++] = EDGE(v,t->w);
        }
    }
    return E; 
}

static int pre[5000], cnt;

void dfsR(Graph G, Edge e){
    int t, w = e.w, v = e.v;
    pre[v] = cnt++;
    for(link a = G->adj[v]; a!= NULL; a = a->next){
        w = a->w;
        if(pre[w] == -1)
            dfsR(G, EDGE(w,w));
    }
}

void GraphBusca(Graph G){
    int v, conexos = 0;
    cnt = 0;
    for(v=0; v < G->V; v++)
        pre[v] = -1;
    for(v=0; v < G->V; v++){
        if(pre[v] == -1)
            dfsR(G, EDGE(v,v));
            conexos++; 
    }

}


void imprimirGrafo(Graph G){
    for(int v =1; v <G->V; v++){
        printf("%d -> ", v);
        for(link a = G->adj[v]; a != NULL; a = a->next)
            printf("%d ", a->w);
        printf("\n");
    }
}

void dijkstra(Graph G, int s, int *pa, int *dist){
    int mature[2001];
    for(int v=0; v< G->V; v++){
        pa[v] = -1;
        mature[v] = 0; 
        dist[v] = INT_MAX;
    } 
    pa[s] = s;
    dist[s] = 0;

    while(1){
        int min = INT_MAX;
        int y;

        for(int z = 0; z < G->V; z++){
            if(mature[z] == 1) continue;
            if(dist[z] < min){
                min = dist[z];
                y = z;
            }
        }
        
        if(min == INT_MAX) break;

        for(link a = G->adj[y]; a!= NULL; a = a->next){
            if(mature[a->w] == 1) continue;
            if(dist[y] + a->c < dist[a->w]){
                dist[a->w] = dist[y] + a->c;
                pa[a->w] = y;
            }
        }
        mature[y] = 1;  
    }
}

bool BellmanFord(Graph G, int s, int *pa, int *dist){
    QUEUEinit(G->V * (G->V -1));
    int onqueue[2001];
    for(int i =0; i< G->V; i++){
        pa[i] = -1;
        dist[i] = INT_MAX;
        onqueue[i] = 0;
    }

    pa[s] = s;
    dist[s] = 0;
    QUEUEput(s);
    onqueue[s] = 1;

    int V = G->V;
    QUEUEput(V);
    int k =0; 

    while(1){
        int v = QUEUEget();
        if(v < V){
            for(link a = G->adj[v]; a!= NULL; a = a->next){
                if(dist[v] + a->c < dist[a->w]){
                    dist[a->w] = dist[v] + a->c;
                    pa[a->w] = v;
                    if(onqueue[a->w] == 0){
                        QUEUEput(a->w);
                        onqueue[a->w] = 1;
                    }
                }
            }
        }
        else {
            if(QUEUEempty())
                return true;
            if(++k >= G->V)
                return false;
            QUEUEput(V);
            for(int u=0; u<G->V; u++)
                onqueue[u] = 0;
        }
    }
}

int main(){
    int switches;
    scanf("%d", &switches);
    Graph grafoC = GraphInit(switches);
    Graph grafoS = GraphInit(switches);
    int v,w,c,t;
    while(1){
        scanf("%d %d %d %d", &v, &w, &c, &t);
        if(v == 0 && w == 0 && c == 0 && t == 0)
            break;
        if(t == 0)
            GraphInsere(grafoS, EDGE(v,w), c, t);
        GraphInsere(grafoC, EDGE(v,w), c, t);
    }
    
    int *distC = malloc(switches * sizeof(int));
    int *distS = malloc(switches * sizeof(int));
    int *pa = malloc(switches * sizeof(int));

    scanf("%d %d", &v, &w);
    int anterior = v;
    int cond = 0;
    if(!BellmanFord(grafoC, v, pa, distC)){
        printf("Impossibru\n");
        cond = 1;
    }
    else {
        dijkstra(grafoS, v, pa, distS);
        if(distC[w] == INT_MAX || distS[w] == INT_MAX)
            printf("Impossibru\n");
        else
            printf("%d %d\n", distS[w], distC[w]);
    }

    while(scanf("%d %d", &v, &w) != EOF){
        if(cond == 1){
            printf("Impossibru\n");
            continue;
        }
        if(v != anterior){
            dijkstra(grafoS, v, pa, distS);
            if(!BellmanFord(grafoC, v, pa, distC))
                printf("Impossibru\n");
            anterior = v;
        }
        if(distC[w] == INT_MAX || distS[w] == INT_MAX)
            printf("Impossibru\n");
        else
            printf("%d %d\n", distS[w], distC[w]);
    }
    return 0;
}