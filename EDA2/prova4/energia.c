#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int V;
	struct node *next;
} node;

typedef struct graph{
	int V;
	int E;
	int **adj;
	int **tc;
} graph;

typedef struct edge{
	int v;
	int w;
} edge;

typedef struct fila{
	edge *V;
	struct fila *next;
} fila;

fila *filaInit(){
	fila *new = malloc(sizeof(fila));
	new->next = NULL;
}

int filaVazia(fila *f){
	return f->next == NULL; 
	
}

int **matrixInit(int n, int V){
	int **m = malloc(V * sizeof(int*));
	for(int i=0;i<V;i++){
		m[i] = malloc(V * sizeof(int));
		for(int j=0;j<V;j++)
			m[i][j] = n;
	}
	return m;
}

void insereFila(fila *f, edge *e){
	fila *new = malloc(sizeof(fila));
	new->V = e;
	new->next = NULL;
	if (filaVazia(f))
		f->next = new;
	else{
		fila *tmp = f->next;
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

edge *removeFila(fila *f){

	fila *tmp = f->next;
	f->next = tmp->next;
	edge *e	= tmp->V;
	free(tmp);

	return e;
}

node *nodeNew(int V, node *next){
	node *new = malloc(sizeof(node));
	new->V = V;
	new->next = next;
	return new;
}

graph *graphInit(int V){
	graph *G = malloc(sizeof(graph));
	G->V = V;
	G->E = 0;
	G->adj = matrixInit(0, V);
	return G;
}

void graphInsert(graph *G, edge *e, int p){
	int v = e->v, w = e->w;
	if(G->adj[v][w] == 0)
		G->E++;
	G->adj[v][w] = 1;
	if(p == 2)
		G->adj[w][v] = 1;
}

edge *edgeInit(int v, int w){
	edge *e = malloc(sizeof(edge));
	e->v = v;
	e->w = w;
	return e;
}

int graphEdges(edge **a, graph *G){
	int v, w, E=0;
	for(v=0; v<G->V; v++)
		for(w = v+1;w<G->V;w++)
			if(G->adj[v][w]==1)
				a[E++] = edgeInit(v, w);
	return E;
}

void graphTc(graph *g){
	int i, s, t;
	g->tc = matrixInit(0, g->V);
	for(s=0;s<g->V;s++)
		for(t=0;t<g->V;t++)
			g->tc[s][t] = g->adj[s][t];
	for(s=0;s<g->V;s++)
		g->tc[s][s] = 1;
	for(i=0;i<g->V;i++)
		for(s=0;s<g->V;s++)
			if(g->tc[s][i] == 1)
				for(t=0;t<g->V;t++)
					if(g->tc[i][t] == 1)
						g->tc[s][t] = 1;

}

void dfsR(graph *g, edge *e, int *count, int *pre){
	int t, w = e->w;
	pre[w] = (*count)++;
	for(t=0;t<g->V;t++){
		if(g->adj[w][t]!=0)
			if(pre[t] == -1)
				dfsR(g, edgeInit(w, t), count, pre);
	}
}
/*
void bfs(graph *g, edge *e, int *count, int *pre){
	int v, w, t;
	node *l;
	fila *f = filaInit();
	insereFila(f, e);
	pre[e->w] = *count++;
	while(!filaVazia(f)){
		e = removeFila(f);
		w = e->w;
		for(l=g->adj[w];l!=NULL;l=l->next){
			t = l->V;
			if(pre[t] == -1){
				insereFila(f, e);
				pre[t] = *count++;			
			}
		}
	}
}
*/

void graphSearch(graph *g, int *count, int *pre){
	int v, conexos = 0;
	*count = 0;
	for(v=0;v<g->V;v++)
		pre[v] = -1;
	for(v=0;v<g->V;v++){
		if(pre[v] == -1){
			dfsR(g, edgeInit(v, v), count, pre);
			conexos++;
		}
	}
}

int graphReach(graph *g, int s, int t){
	return g->tc[s][t];
}

int main(){
	int N, M, v, w, t=1, p;

	while(1){
		scanf("%d %d", &N, &M);
		if(N == 0 && M == 0)
			break;
		int *pre = malloc(N * sizeof(int));
		graph *g = graphInit(N);
		for(int i=0;i<M;i++){
			scanf("%d %d", &v, &w);
			graphInsert(g, edgeInit(v-1, w-1), 2);
		}
		graphTc(g);
		for(int i =0 ; i < g->V; i++){
			for(int j =0 ; j < g->V; j++){
				printf("%2d ", g->tc[i][j]);
			}
			printf("\n");
		}
		printf("Teste %d\n", t);
		p = 0;
		for(int i=0;i<N;i++){
			for(int j=i;j<N;j++){
				v = graphReach(g, i, j);
				if(v != 1)
					p = 1;
			}
		}
		if(p == 0)
			printf("normal\n\n");
		else
			printf("falha\n\n");
		t++;
		free(g);
		free(pre);
	}

	return 0;
}
