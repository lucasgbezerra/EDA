#include<stdio.h>
#include<stdlib.h>

typedef int bool;
#define true 1
#define false 0 

#define TAM 1000
#define NUM_VIZINHOS 2
 
int n;
bool visitado[TAM];
int locX[TAM];
int locY[TAM];
 
int grafo[TAM][NUM_VIZINHOS];
 
void swap(int &a, int& b)
{
 int tmp = a;
 a = b;
 b = a;
}
 
inline bool precede(int a, int b)
{
 if (locX[a] == locX[b]) return locY[a] < locY[b];
 else if (locX[a] < locX[b]) return true;
 else return false;
}
 
void ordena(int& a, int& b, int& dist0, int& dist1)
{
 if (dist1 < dist0 || (dist1 == dist0 && precede(b, a)))
 {
  swap(dist0, dist1);
  swap(a, b);
 }
}
 
void calcDist()
{
 for (int i = 0; i < n; i++)
 {
  grafo[i][0] = -1;
  grafo[i][1] = -1;
  int dist0 = 0;
  int dist1 = 0;
   
  for (int j = 0; j < n; j++)
  {
   if (j != i)
   {
    int dx = locX[i] - locX[j];
    int dy = locY[i] - locY[j];
    int dist = dx*dx + dy*dy;
     
    if (grafo[i][0] == -1) { 
     grafo[i][0] = j;
     dist0 = dist;
    }
    else if (grafo[i][1] == -1) { 
     grafo[i][1] = j; 
     dist1 = dist;
      
     ordena(grafo[i][0], grafo[i][1], dist0, dist1);
    }
    else
    {
     if (dist == dist1) {
      if (precede(j, grafo[i][1]))
      {
       grafo[i][1] = j;
      }
       
      ordena(grafo[i][0], grafo[i][1], dist0, dist1);
     }
     else if (dist1 < dist) {
      grafo[i][1] = j;
      dist1 = dist;
       
      ordena(grafo[i][0], grafo[i][1], dist0, dist1);
     }
    }
   }
  }
 }
}
 
void dfs(int no)
{
 visitado[no] = true;
  
 for (int i = 0; i < NUM_VIZINHOS; i++)
 {
  if (!visitado[grafo[no][i]]) dfs(grafo[no][i]);
 }
}
 
int main()
{
 while (scanf("%d\n", &n) == 1)
 {
  if (n == 0) break;
   
  for (int i = 0; i < n; i++)
  {
   scanf("%d %d\n", &locX[i], &locY[i]);
  }
   
  calcDist();
  for (int i = 0; i < n; i++) visitado[i] = false;
  dfs(0);
  bool alcancaveis = true;
   
  for (int i = 0; i < n; i++)
  {
   if (!visitado[i]) {
    alcancaveis = false;
    break;
   }
  }
   
  if (alcancaveis) printf("All stations are reachable.\n");
  else printf("There are stations that are unreachable.\n");
 }
 return 0;
}