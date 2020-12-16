#include <stdio.h>
//Seleção
//Complexidade no melhor caso e no pior caso O(n²)
void selecao(int v[], int n)
{
  for (int i = 0; i < n; i++)
  {
    int min = v[i];
    for (int j = i + 1; j < n; j++)
    {
      if (v[j] < v[i])
      {
        v[i] = v[j];
        v[j] = min;
        min = v[i];
      }
    }
  }
}
void selecao_rec(int v[], int i, int n)
{
  int min = i;
  if (i < n)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (v[j] < v[i])
      {
        v[i] = v[j];
        v[j] = min;
        min = v[i];
      }
    }
    selecao_rec(v, i + 1, n);
  }
}
int main()
{
  int v[1000];
  int i = 0;

  while (scanf("%d", &v[i]) != EOF)
    i++;
  
  printf("Inicial\n");
  for (int c = 0; c < i; c++)
    printf("%d ", v[c]);
  printf("\n");
  selecao(v, i);
  printf("Ordenação por seleção\n");
  for (int c = 0; c < i; c++)
    printf("%d ", v[c]);
  printf("\n");
  printf("Ordenação por seleção(recursiva)\n");
  selecao_rec(v, 0, i);
  for (int c = 0; c < i; c++)
    printf("%d ", v[c]);
  printf("\n");

  return 0;
}