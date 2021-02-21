#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int busca_binaria(int v[], int esq, int dir, int x, int n){
  int p = 0;
  int m;
  if(esq == dir-1){
    if(x > v[esq]){
      return n-dir;  
    }
    if(x <= v[esq] ){
      return n-esq;
    }
  }
  m = (esq+dir)/2;
  if(v[m] < x)
    return busca_binaria(v, m, dir, x, n);
  else
    return busca_binaria(v, esq, m, x, n);

}

int main(){
  int *c, t, x, y, n;
  int r;
  long long int pont =0;
  scanf("%d %d", &n, &t);
  c = malloc(n * sizeof(int));
  for(int i = 0; i < n; i++){
    scanf("%d", &c[i]);
  }
  for(int i = 0; i < t; i++){
    scanf("%d %d", &x, &y);
    r = ceil(sqrt((pow(x,2)+pow(y,2))));
    if(r <= c[n-1] && r > c[0])
      pont += busca_binaria(c, 0,n-1, r, n);
    if(r <= c[0])
      pont+= n;

  }
  printf("%lld\n", pont);
  
  return 0;
}