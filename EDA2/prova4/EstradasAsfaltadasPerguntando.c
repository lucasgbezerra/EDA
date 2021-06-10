#include <stdio.h>
#include <stdlib.h>

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

int **matrixInit(int n, int V){
	int **m = malloc(V * sizeof(int*));
	for(int i=0;i<V;i++){
		m[i] = malloc(V * sizeof(int));
		for(int j=0;j<V;j++)
			m[i][j] = n;
	}
	return m;
}

graph *graphInit(int V){
	graph *G = malloc(sizeof(graph));
	G->V = V;
	G->E = 0;
	G->adj = matrixInit(0, V);
	return G;
}

void graphInsert(graph *G, edge *e, int d){
	int v = e->v, w = e->w;
	if(G->adj[v][w] == 0)
		G->E++;
	G->adj[v][w] = 1;
	if(d == 2)
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
	pre[w] = *count++;
	for(t=0;t<g->V;t++){
		if(g->adj[w][t]!=0)
			if(pre[t] == -1)
				dfsR(g, edgeInit(w, t), count, pre);
	}
}

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

void print(graph *g){
	for(int i=0;i<g->V;i++){
		for(int j=0;j<g->V;j++)
			printf("%d ", g->tc[i][j]);
		printf("\n");
	}
}

int main(){
	int V, v, w, d;
	scanf("%d", &V);
	graph *g = graphInit(V);
	while(1){
		scanf("%d %d %d", &v, &w, &d);
		if(v == 0 && w == 0 && d == 0)
			break;
		graphInsert(g, edgeInit(v, w), d);
	}
	graphTc(g);
	while(scanf("%d %d", &v, &w) != EOF){
		d = graphReach(g, v, w);
		V = graphReach(g, w, v);
		if(d == 1 && V == 1)
			printf("Ida e Volta\n");
		else if (d == 1)
			printf("Apenas Ida\n");
		else if (V == 1)
			printf("Apenas Volta\n");
		else
			printf("Impossibru\n");
	}

	return 0;
}
