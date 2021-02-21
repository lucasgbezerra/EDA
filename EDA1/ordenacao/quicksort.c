#include <stdio.h>
//Quicksort
//Complexidade no melhor caso O(n log n), no pior caso O(n²)
void troca(int v[], int i, int j)
{
  int k = v[i];
  v[i] = v[j];
  v[j] = k;
}

int separa(int v[], int inicio, int fim)
{
  int pivo = v[fim];
  int j = inicio;
  for (int i = inicio; i < fim; i++)
  {
    if (v[i] < pivo)
    {
      int temp = v[j];
      v[j] = v[i];
      v[i] = temp;
      j++;
    }
  }
  v[fim] = v[j];
  v[j] = pivo;

  return j;
}

void quickSort(int v[], int inicio, int fim)
{
  int posPivo; // posição do pivô

  if (inicio >= fim)
    return;

  posPivo = separa(v, inicio, fim);
  quickSort(v, inicio, posPivo - 1);
  quickSort(v, posPivo + 1, fim);
}
int main()
{
  int v[1000];
  int i = 0;

  while (scanf("%d", &v[i]) != EOF)
    i++;

  quickSort(v, 0, i - 1);
  for (int c = 0; c < i; c++)
    printf("%d ", v[c]);
  printf("\n");

  return 0;
}