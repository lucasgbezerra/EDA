#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int v[1001];
    int n, nota, maiorNota = -1, maior = -1;

    memset(v, 0, sizeof(int)* 1001);

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &nota);
        v[nota]++;

        if(v[nota] >= maiorNota){
            if(v[nota] == maiorNota){
                if(nota > maior){
                    maiorNota = v[nota];
                    maior = nota;
                }
            }else{
                maiorNota = v[nota];
                maior = nota;
            }
        }
        
    }

    printf("%d\n", maior);

    return 0;
}