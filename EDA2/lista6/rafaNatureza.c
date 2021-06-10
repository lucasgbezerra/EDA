#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


#define vertex int
typedef int Item;

static int cnt;
int *fila, p, u;

typedef struct node *link;
struct node 
{
   int w;
   int c;
   link next;
};
//typedef struct node node;

struct graph 
{
   int V; 
   int A; 
   link *adj; 
};
typedef struct graph *Graph;

static link NEWnode( int w, link next, int c) { 
   link a = malloc( sizeof (struct node));
   a->w = w; 
   a->c = c;
   a->next = next;     
   return a;                         
}

Graph GRAPHinit( int V) { 
   Graph G = malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = malloc( V * sizeof (link));
   for (int v = 0; v < V; ++v) 
      G->adj[v] = NULL;
   return G;
}


void GRAPHinsert( Graph G, int v, int w, int c, int t) 
{ 
   if(t == 0)
   {
       G->adj[v] = NEWnode( w, G->adj[v], c);
       G->adj[w] = NEWnode( v, G->adj[w], c); 
       G->A++;    
   }   
   else if(t == 1)
   {
       G->adj[v] = NEWnode( w, G->adj[v], c);
       G->A++;  
   }  
}

void GRAPHdestroy(Graph G)
{
    for(int i=0; i<G->V; i++) free(G->adj[i]);
    free(G->adj);;
    free(G);
}

void GRAPHshow(Graph G)
{
   for(int i=0; i<G->V; i++)
   {
      printf("%d: ", i);
      for (link a = G->adj[i]; a != NULL; a = a->next)
      {
         printf(" %d", a->w);
      }
      printf("\n");
   }
}

//Fila
typedef struct queue *QUEUE;

typedef struct QUEUEnode* linq;
struct QUEUEnode { 
  Item item; 
  linq prox; 
};
struct queue { /* aqui esta especificado o que e' */
  linq inicio; /* uma fila: dois apontadores para QUEUEnode */
  linq fim;    
}; 

linq NEW(Item item, linq prox)      
{ 
   linq x = (linq) malloc(sizeof *x);
   x->item = item; x->prox = prox;     
   return x;                         
}     
                              
QUEUE QUEUEinit(int maxN) 
{ 
  QUEUE q = (QUEUE) malloc(sizeof *q); 
  q->inicio = NULL; 
  q->fim = NULL; 
  return q;
}

int QUEUEempty(QUEUE q)
{ 
  return q->inicio == NULL; 
}

void QUEUEput(QUEUE q, Item item)
{ 
   if (q->inicio == NULL)
   { 
   q->fim = NEW(item, NULL);
   q->inicio = q->fim; 
   return; 
   }
   q->fim->prox = NEW(item, NULL); 
   q->fim = q->fim->prox;
}

Item QUEUEget(QUEUE q)
{ 
  Item item = q->inicio->item;
  linq t = q->inicio->prox;
  free(q->inicio); 
  q->inicio = t;
  return item;
}

void QUEUEfree(QUEUE q)
{ 
  while (q->inicio != NULL) 
    { 
      linq t = q->inicio->prox;
      free(q->inicio);
      q->inicio = t;
    }
  free(q);
}

//Fim de Fila

bool GRAPHcptBF( Graph G, vertex s, vertex *pa, int *dist)
{
   bool onqueue[2002];
   for (vertex j = 0; j < G->V; ++j)
      pa[j] = -1, dist[j] = INT_MAX, onqueue[j] = false;
   pa[s] = s, dist[s] = 0;
   QUEUE fila = QUEUEinit( G->A);
   QUEUEput( fila, s);
   onqueue[s] = true;
   vertex V = G->V; // pseudovértice
   QUEUEput(fila, V); // sentinela
   int k = 0;

   while (1) 
   { 
      vertex v = QUEUEget(fila);
      if (v < V) 
      {
         for (link a = G->adj[v]; a != NULL; a = a->next) {
            if (dist[v] + a->c < dist[a->w]) 
            {
               dist[a->w] = dist[v] + a->c; 
               pa[a->w] = v;
               if (onqueue[a->w] == false) 
               {
                  QUEUEput(fila, a->w);
                  onqueue[a->w] = true;
               }
            }
         }
      } 
      else 
      {
         if (QUEUEempty(fila)) return true; // A
         if (++k >= G->V) return false; // B
         QUEUEput(fila,V); // sentinela
         for (vertex u = 0; u < G->V; ++u) 
            onqueue[u] = false;
      }
   }
   QUEUEfree(fila);
}



int main()
{
   int tamanho, flag = 0, distTotal = 0;
   int v,w,c,t;
   Graph Conexao, ConexaoNegative;
   int pa[2002], paN[2002];
   int dist[2002], distN[2002];
   
   scanf("%d", &tamanho);
   Conexao = GRAPHinit(tamanho);
   ConexaoNegative = GRAPHinit(tamanho);
   
   scanf("%d%d%d%d", &v, &w, &c, &t);

   //montar o grafo
   while(1)
   {
      if(t == 1) flag = 0;
      distTotal += c;
      if(t == 0)
         GRAPHinsert(Conexao,v,w,c,t);
      GRAPHinsert(ConexaoNegative,v,w,c,t);

      scanf("%d%d%d%d", &v, &w, &c, &t);
      if(v==0 && w==0)
         if(c==0 && t == 0) break;
   }
   GRAPHshow(ConexaoNegative);
   GRAPHshow(Conexao);
   int o,x;
   if(flag == 1)//SE NÃO TIVER SUPER CONEXÃO NÃO HA NECESSIDADE DE UZAR 2 GRAFOS
   {
      while(scanf("%d", &o) != EOF)
      {
         scanf("%d", &x);
         if(GRAPHcptBF(Conexao,x,pa,dist) == true)
         {
            int aux = dist[o];
            if(dist[o] >= distTotal) printf("Impossibru\n");
            else if(GRAPHcptBF(ConexaoNegative,x,pa,dist) == false)
            {
               printf("Impossibru\n");
            }
            else if(GRAPHcptBF(ConexaoNegative,x,pa,dist) == true)
            {
               if(dist[o] >= distTotal) printf("Impossibru\n");
               else printf("%d %d\n",aux, dist[o]);
            }
         }
         else if(GRAPHcptBF(Conexao,x,pa,dist) == false)
         {
            printf("Impossibru\n");
         }
      }
   }
   else if(flag == 0)
   {
      while(scanf("%d", &o) != EOF)
      {
         scanf("%d", &x);
         if(GRAPHcptBF(ConexaoNegative, o, paN, distN)){
            printf("%d\n", distN[x]);
         }
      }
   }
   // GRAPHshow(Conexao);
   // printf("\n");
   // GRAPHshow(ConexaoNegative);
   
   GRAPHdestroy(Conexao);
   GRAPHdestroy(ConexaoNegative);

   return 0;
}