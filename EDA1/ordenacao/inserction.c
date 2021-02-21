#include <stdio.h>
//Inserção
//Complexidade no melhor caso O(n), no pior caso O(n²)
void insercao(int v[], int n){
  for(int i=1; i < n; i++){
    int elem = v[i];
    for (int j = i-1; j >=0 && v[j] > elem; j--){
      v[j+1] = v[j];
      v[j] = elem;
    }
  }
}
void insercao_rec(int v[], int n){
  if(n==1)
    return;
  insercao(v,n-1);
  for (int j = n-1; j >=0 && v[j] > v[n]; j--){
      v[j+1] = v[j];
      v[j] = v[n];
    }
  
}
int main(){
  int v[1000];
  int i = 0;

  while (scanf("%d", &v[i]) != EOF)
    i++;
  
  for(int c = 0; c < i; c++)
    printf("%d ", v[c]);
  printf("\n");
  insercao_rec(v, i);
  for(int c = 0; c < i; c++)
    printf("%d ", v[c]);
  printf("\n");

  return 0;

}