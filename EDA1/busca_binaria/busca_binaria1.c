#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int v[], int esq, int dir, int x){
  int m;
  if(esq == dir-1){
    if(x > v[dir])
      return dir+1;  
    if(x <= v[esq])
      return esq;
    else
      return dir;
  }
  m = (esq+dir)/2;
  if(v[m] < x)
    return busca_binaria(v, m, dir, x);
  else
    return busca_binaria(v, esq, m, x);
}


int main(){
  int m, n, x;
  int *v;
  scanf("%d %d", &n, &m);
  v = malloc(n * sizeof(int));
  for(int i = 0; i < n; i++){
    scanf("%d", &v[i]);
  }

  //busca
  for(int i = 0; i < m; i++){
    scanf("%d", &x);
    x = busca_binaria(v, 0, n-1, x);
    printf("%d\n", x);
  }
  return 0;
}