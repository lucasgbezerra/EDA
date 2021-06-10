#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int v;
    int w;
}Edge;

//inicializa aresta
Edge EDGE(int x, int y);

typedef struct graph* Graph;

//Inicializa o grafo, x é a quantidade de vértices
Graph GRAPHinit(int x);

//Inserir novo vértice no grafo
void GRAPHinsertE(Graph g, Edge e);

//Remover um vertice do grafo
void GRAPHRemoveE(Graph g, Edge e);

//Contador de arestas
int GRAPHEdges(Edge[], Graph g);

//Retorna um grafo, duplica e retorna um grafo
Graph GRAPHCopy(Graph);

//Destroi Grafo
void GRAPHDdestroy(Graph);


struct graph
{
    int V;
    int E;
    int **adj;
};
//Inicializa o grafo, v é a quantidade de vértices
Graph GRAPHinit(int v){
    Graph G = malloc(sizeof(*G));
    
    G->V = v;
    G->E = 0;
    G->adj = MATRIXInit(v,v,0); //Inicializa um mattiz VxV zerada
    
    return G;
}

// Alocação dinâmica de Matriz
int **MATRIXInit(int l, int c, int x){
    int **m;
    m =  malloc(c *sizeof(int*));
    for (int i = 0; i < c; i++)
        m[i] = malloc(l * sizeof(int));
    
    return m;
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

//Remover uma aresta do grafo, custo O(1)
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

//Contador de arestas
//Custo muito alto em um grafo dirigido O(n^2)
//Em um grafo não dirigido só é preciso olhar metade ta tabela, caso abaixo
int GRAPHEdges(Edge *a, Graph G){
    //a: vetor alocado

    int v, w, E = 0;

    for (int v = 0; v < G->V; v++)
    {
        for (int w = v+1; w < G->E; w++)
            if(G->adj[v][w] == 1)
                a[E++] = EDGE(v,w);
    }
    return E; 
}
//  Lista de adjacência
//Alerações nas structs
typedef struct node *link;
struct node{
    int v;
    link *next;
};
struct graph
{
    int V;
    int E;
    link *adj;
};

//Alocação de um novo nó
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
    G->adj = malloc(V * sizeof(link)); //Inicializa um mattiz VxV zerada
    
    for(v = 0; v < V; v++)
        G->adj[v] = NULL;
    return G;
}

void GRAPHInsert(Graph G, Edge e){
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
int pre[V]; //tamanho de vertices PREENCHER DE -1
void dsfR(Graph G, Edge e){
    int t, w = e.w;
    //vetor global
    pre[w] = count++;
    
    for(t = 0; t < G->V, t++)
        if(G->adj[w][t] != 0)
            if(pre[t] == -1)
                dsfR(G, EDGE(w,t));
}

static int cnt = 0, pre[maxV];

void GRAPHsearch(Graph G){
    int v;
    int conexos = 0;
    cnt = 0;

    for(v=0; v < G->V; v++)
        pre[v] = -1;
    for(v = 0; v < G->V;v++){
        if(pre[v] == -1){
            dsfR(G, EDGE(v,v));
            conexos++;
        }
    }
}


static int cnt = 0, pre[maxV];
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

// Busca em Largura Usando fila encadeadas
void bfs(Graph G, Edge e){
	int v,w;
    int t;
    //Cria fila
    QUEUEput(e);
    pre[e.w] = cnt++;

    while(!QUEUEempty()){
        Edge v = QUEUEget();
        w = v.w;
        for(link l = G->adj[w]; l != NULL; l = l->next){
            t = l->v;
            if(pre[t] == -1){
                QUEUEput(EDGE(w, t));
                pre[t] = cnt++;
            }
        }
    }
}
// Inverter arestas de um grafo dirigido
// Lista encadeada
Graph GRAPHreverse(Graph G){
    int v;
    link t;

    Graph R = GRAPHinit(G->V);
    for(v = 0; v < G->V; v++){
        for(t = G->adj[v]; t != NULL; t = t->next)
            GRAPHinsert(R, EDGE(t->v, v));
    }
    return R;
}

// Floyd Warshall, O(V^3)
void GRAPHtc(Graph G){
    int i, s, t;

    //ADD ** tc na struct do grafo
    G->tc = MATRIXint(G->V, G->V, 0);

    //Copia da matriz de adjacencia
    for(s = 0; s < G->V; s++){
        for(t = 0; t < G->V; t++)
            G->tc[s][t] = G->adj[s][t];
        
    }
    //Diagonas de tc = 1
    for(s = 0; s < G->V; s++)
        G->tc[s][s] = 1;
    for(i = 0; i < G->V; i++){
        for(s = 0; s < G->V; s++){
            if(g->tc[s][i] == 1){
                for(t = 0; t < G->V; t++)
                    if(G->tc[i][t] == 1)
                        G->tc[s][t] = 1;
            }
        }
    }
}

//Chamada GRAPHtc
int GRAPHreach(Graph G, int s, int t){
    //Qual a alcançabilidade de G partindo de s e indo pra t
    return G->tc[s][t];
}
//Vale a pena usar a matriz de adjacencias é mais barato

//Algoritmo Bellmon Ford (menor caminho)
// Custo não é bom
bool GRAPHcptBF(Graph G, int s, int *pa, int *dist){
    bool onqueue[1000];//Quantidade de vértices G->V
    for(int v = 0; v < G->V; v++){
        pa[v] = -1;
        dist[v] = __INT_MAX__;
        onqueue[v] = false;
    }

    //Sai do vertice pra ele mesmo
    pa[s] = s;
    dist[s] = 0;

    //Criar uma fila  das arestas
    QUEUEinit(G->E);
    QUEUEput(s);
    onqueue[s] = true;
    //Vertice que não existe, tamanho +1
    QUEUEput(G->V);
    //Evitar ciclos
    int k = 0;
    while(1){
        int v = QUEUEget();
        if(v < G->V){
            for(link a = G->adj[v]; a != NULL; a = a->next)
            {
                if(dist[v] + a->c < dist[a->v]){
                    dist[a->v] = dist[v]+a->c;
                    pa[a->v] = v;
                    if(onqueue[a->v] == false)
                        QUEUEput(a->v);
                        onqueue[a->v] = true;
                }
            }
        }else{
            if(QUEUEempty())
                return true;
            if(++k > G->V)
                return false;
            QUEUEput(V);
            for(int t = 0; t < G->V; t++)
                onqueue[t] = false;
        }
    }
}

//Dijkstra
void GRAPHcptD1(Graph G, int s, int *pa, int *dist){
    bool mature[1000]; //Quantidade de vértices G->V

    for(int v = 0; v < G->V; v++){
        pa[v] = 1;
        mature[v] = false;
        dist[v] = __INT_MAX__;
    }
    pa[s] = s;
    dist[s] = 0;

    while (1)
    {
        int min = __INT_MAX__;
        int y;
        for(int z = 0; z < G->V; z++){
            if(mature[z])
                continue;
            if(dist[z] < min){
                min = dist[z];
                y = z;
            }
        }
        if(min == __INT_MAX__)
            break;
        for(link a = G->adj[y]; a != NULL; a= a->next){
            if(mature[a->v])
                continue;
            if(dist[y] + a->c < dist[a->v]){
                dist[a->v] = dist[y] + a->c;
                pa[a->v] = y; 
            }     
        }
        mature[y] = true;   
    }
    
}