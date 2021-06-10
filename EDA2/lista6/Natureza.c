//Grafo - Lista de adjacência
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Key(A) (A.nome)
#define less(A,B) (strcmp(Key(A), Key(B)))
#define lesseq(A,B) (strcmp(Key(A), Key(B))
#define exch(A, B) {Criaturas t = A; A = B; B = t;}
#define cmpexch(A, B) {if less (B,A) exch (A,B);}

typedef struct {
    int v;
    int w;
}Edge;

typedef struct Criaturas{
    char nome[32];
}Criaturas;

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
static int cont = 0;

// Ordenação QuicksortM3
int separa(Criaturas *v, int l, int r){
	Criaturas pv = v[r];
	int j = l;
	int aux;

	for(int k = l; k < r; k++){
		if(strcmp(v[k].nome, pv.nome) < 0){
			exch(v[k], v[j]);
			j++;
		}
	}

	exch(v[r], v[j]);	
	return j;
}
void quickSort(Criaturas *v, int l, int r){
	int j;
	int m = (r+l)/2;
	if(r <= l)
		return;
	cmpexch(v[m], v[r]);
	cmpexch(v[l], v[m]);
	cmpexch(v[r], v[m]);

	j = separa(v, l, r);
	quickSort(v, l, j-1);
	quickSort(v, j+1, r);
}
//Busca Binária
int buscaBinaria(Criaturas *v, int l, int r, char *x){
	int m = (r+l)/2;	

	if(l == r -1){
		if(strcmp(v[l].nome, x) == 0)
			return l;
		if(strcmp(v[r].nome, x) == 0)
			return r;
		else
			return -1;
	}
	
	if(strcmp(x, v[m].nome) < 0)
		return buscaBinaria(v, l, m, x);
	else
		return buscaBinaria(v, m, r, x);
}


//


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
    G->adj[w] = NEW(v, G->adj[w]);
    G->adj[v] = NEW(w, G->adj[v]);
    G->E++;
}

//Busca em profundidade com lista de adjacências
void dfsR(Graph G, Edge e){
    int  t, w = e.w;
    link l;
    pre[w] = cnt++;

    for(l = G->adj[w]; l != NULL; l = l->next)
    {
        t = l->v;
        if(pre[t] == -1){
            dfsR(G, EDGE(w, t));
        }
    }
}
int GRAPHsearch(Graph G){
    int v;
    int maxVert = 0;
    cnt = 0;

    for(v= 0; v < G->V;++v)
        pre[v] = -1;
    for(v = 0; v < G->V;++v){
        cnt = 0;
        if(pre[v] == -1){
            dfsR(G, EDGE(v,v));
            if(cnt > maxVert)
                maxVert = cnt;
        }
    } 
    return maxVert;
}

void clean(link l){
    if(l != NULL){
        clean(l->next);
        free(l);
    }
}
void GRAPHdestroy(Graph G){
    int i;
    for(i = 0; i < G->V; i++)
        clean(G->adj[i]);
    free(G->adj);
}

int main(){
    int C, R;
    Criaturas *c = malloc(sizeof(Criaturas)*5000);
    char presa[32], predador[32];
    int pr = -1, pd = -1;

    scanf("%d %d", &C, &R);
   
    while (C != 0)
    {
        for(int i = 0; i < C; i++)
            scanf("%s", c[i].nome);
               
        quickSort(c, 0, C-1);
        
        Graph graph = GRAPHinit(C);
        for(int i = 0; i < R; i++){
            scanf("%s %s", presa, predador);
            pr = buscaBinaria(c, 0, C, presa);
            pd = buscaBinaria(c, 0, C, predador);
            
            GRAPHinsertE(graph, EDGE(pr,pd));
            
        }
        printf("%d\n",GRAPHsearch(graph));
        GRAPHdestroy(graph);
        scanf("%d %d", &C, &R); 
    }
    return 0;
}
