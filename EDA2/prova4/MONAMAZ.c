#include <stdio.h>
#include <stdlib.h>

#define less(A,B) (A.dis < B.dis || (A.dis == B.dis && A.x < B.x) || (A.dis == B.dis && A.x == B.x && A.y == B.y))
#define exch(A,B) { ord t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

typedef struct node{
	int V;
	struct node *next;
} node;

typedef struct graph{
	int V;
	int E;
	int **adj;
} graph;

typedef struct edge{
	int v;
	int w;
} edge;

typedef struct dict{
	int x;
	int y;	
} dict;

typedef struct ord{
	int dis;
	int pos;
	int x;
	int y;
} ord;

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

void graphInsert(graph *G, edge *e){
	int v = e->v, w = e->w;
	if(G->adj[v][w] == 0){
		G->E++;
		G->adj[v][w] = 1;
	}
}


void graphRemove(graph *G, edge *e){
	int v = e->v, w = e->w;
	if(G->adj[v][w] == 1)
		G->E--;
	G->adj[v][w] = 0;
	G->adj[w][v] = 0;
}

edge *edgeInit(int v, int w){
	edge *e = malloc(sizeof(edge));
	e->v = v;
	e->w = w;
	return e;
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
	if(conexos == 1)
		printf("All stations are reachable.\n");
	else
		printf("There are stations that are unreachable.\n");
}



void *distances(ord *m , dict *d, int N, int i){
	for(int j=0;j<N;j++){
		m[j].dis = (d[i].x-d[j].x)*(d[i].x-d[j].x) + (d[i].y-d[j].y)*(d[i].y-d[j].y);
		m[j].pos = j;
		m[j].x = d[j].x;
		m[j].y = d[j].y;
	}
}

void print(graph *g){
	for(int i=0;i<g->V;i++){
		printf("%d ->", i);
		for(int j=0;j<g->V;j++)
			if(g->adj[i][j] == 1)
			printf(" %d", j);
		printf("\n");
	}
}

void merge(ord *V, int l, int m, int r)
{
  	ord *R = malloc(sizeof(ord)*(r-l));
  	int i1 = l, i2 = m, i3 = 0;
  	while(i1<m && i2<r)
  	{
    	if(V[i1].dis < V[i2].dis || (V[i1].dis == V[i2].dis && V[i1].x < V[i2].x) || (V[i1].dis == V[i2].dis && V[i1].x == V[i2].x && V[i1].y == V[i2].y))
      		R[i3++] = V[i1++];
    	else
      		R[i3++] = V[i2++];
  	}
  	while(i1 < m)
      	R[i3++] = V[i1++];
  	while(i2 < r)
      	R[i3++] = V[i2++];
	for (int i=l;i<r;i++)
		V[i] = R[i-l];
}

int separa(ord *V, int l, int r){
	ord c=V[r];
	int j=l, temp;
	for(int k=l;k<r;k++){
		if(V[k].dis < c.dis || (V[k].dis == c.dis && V[k].x < c.x) || (V[k].dis == c.dis && V[k].x == c.x && V[k].y == c.y)){
		exch(V[k], V[j]);
		j++;
		}
	}
	exch(V[r], V[j]);
	return j;
}

void quickSelect(ord *V, int l, int r, int k){
	if(l>=r)
		return;
	int i;	

	exch(V[(l+r)/2],V[r-1]);
  	cmpexch(V[l],V[r-1]);
  	cmpexch(V[l],V[r]);
  	cmpexch(V[r-1],V[r]);

	i = separa(V, l, r);
	
	if (i>k)
		quickSelect(V, l, i-1, k);
	if (i<k)
		quickSelect(V, i+1, r, k);
}

void mergeSort(ord *V, int l, int r)
{
	if ((l >= r-1)) {
		return;
	}
  	int m=(l+r)/2;
  	mergeSort(V, l, m);
  	mergeSort(V, m, r);
  	merge(V, l, m, r);
}

int main(){
	int N , x, y, z, t, l;
	int *c = malloc(sizeof(int));	
	while(1){
		scanf("%d", &N);
		if(N == 0)
			break;
		dict *d = malloc(N * sizeof(dict));
		int *pre = malloc(N * sizeof(int));
		graph *g = graphInit(N);
		ord *dist = malloc(N * sizeof(ord));
		for(int i=0;i<N;i++)
			scanf("%d %d", &d[i].x, &d[i].y);
		for(int i=0;i<N;i++){
			distances(dist, d, N, i);
			quickSelect(dist, 0, N-1, 3);
			mergeSort(dist, 0, 2);
			graphInsert(g, edgeInit(i, dist[1].pos));
			graphInsert(g, edgeInit(i, dist[2].pos));
			
		}
		//print(g);
		graphSearch(g, c, pre);
		free(g);
		free(d);
		free(pre);
		free(dist);
	}
	free(c);
	return 0;
}
