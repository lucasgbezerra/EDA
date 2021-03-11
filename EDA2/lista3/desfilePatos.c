//Desfile dos patos
// Tabela Hash
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int *v;
    int maiorCod = 0, maiorRep = 0;
    int n, cod;
    v = malloc(sizeof(int)* 1000001);
    scanf("%d", &n);
    while (n != 0)
    {
        memset((void*)v, 0, sizeof(int) * 1000001);
        maiorCod = 0, maiorRep = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &cod);
            v[cod]++;
            if(v[cod] > maiorRep){
                maiorRep = v[cod];
                maiorCod = cod;
            }
        }
        printf("%d\n", maiorCod);
        scanf("%d", &n);
    }
    return 0;
}