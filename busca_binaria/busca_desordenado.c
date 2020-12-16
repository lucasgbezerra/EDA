#include <stdio.h>
#include <stdlib.h>

typedef struct combo {
  int posIni;
  int dado;
} combo;

int separa(combo v[], int inicio, int fim)
{
  combo pivo = v[fim];
  int j = inicio;
  combo temp;
  for (int i = inicio; i < fim; i++)
  {
    if (v[i].dado < pivo.dado)
    {
      temp = v[j];
      v[j] = v[i];
      v[i]= temp;
      j++;
    }
  }
  v[fim] = v[j];
  v[j] = pivo;

  return j;
}

void quickSort(combo v[], int inicio, int fim)
{
  int posPivo; // posição do pivô

  if (inicio >= fim)
    return;

  posPivo = separa(v, inicio, fim);
  quickSort(v, inicio, posPivo - 1);
  quickSort(v, posPivo + 1, fim);
}
int busca_binaria(combo v[], int esq, int dir, int x){
  int m;
  while (esq <= dir)
  {
    int m = (esq+dir)/2;
    if(x == v[m].dado)
      return v[m].posIni;
    if(x < v[m].dado)
      dir = m - 1;
    else
      esq = m + 1;
  }
  return -1;
  
}


int main(){
  int m, n, x;
  combo *v;
  scanf("%d %d", &n, &m);
  v = malloc(n * sizeof(combo));
  for(int i = 0; i < n; i++){
    scanf("%d", &v[i].dado);
    v[i].posIni = i;
  }

  //busca
  quickSort(v, 0, n - 1);
  for(int i = 0; i < m; i++){
    scanf("%d", &x);
    x = busca_binaria(v, 0 , n-1, x);
    printf("%d\n", x);
  }
  return 0;
}