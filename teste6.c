#include <stdio.h>
#include <stdlib.h>

int *fibonacci (int n) {
  int *elementos = malloc(n * sizeof(int));
  elementos[0] = elementos[1] = 1;
  for (int i = 2; i < n; i++)
    elementos[i] = elementos[i-1] + elementos[i-2];
  printf("-%p\n", elementos);
  return elementos;
}

int main () {
  int n;
  int *elementos;

  printf ("Digite quantos elementos deseja calcular: ");
  scanf ("%d", &n);

  elementos = fibonacci(n);
  printf("%p\n", elementos);
  for (int i = 0; i < n; i++)
    printf ("%d\n", elementos[i]);
    free(elementos);
  return 0;
}