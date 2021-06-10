#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 100

int main(){
    int a, v;
    int x, y;
    int teste = 1, maior = 0, cont = 0;
    int *list = malloc(sizeof(int) * tam);
    
    memset(list, 0, sizeof(int)* tam);
    scanf("%d %d", &a, &v);
    while(a != 0 || v != 0){
        maior = 0;
        for(int i = 0; i < v; i++){
            scanf("%d %d", &x, &y);
            list[x]++;
            list[y]++;
            if(list[x] > maior)
                maior = list[x];
            if(list[y] > maior)
                maior = list[y];
        }
        if(teste > 1)
            printf("\n");

        printf("Teste %d\n", teste);
        for(int i = 0; i <= a; i++){
            if(list[i] == maior)
                printf("%d ", i);
            list[i] = 0;
        }
        printf("\n");
        teste++;
        scanf("%d %d", &a, &v);
    }

}