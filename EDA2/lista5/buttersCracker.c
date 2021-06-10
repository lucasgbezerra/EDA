#include <stdio.h>
#include <stdlib.h>

unsigned int mudou(int *v, int tam,unsigned int ini, unsigned int fim){
    int cont = 0;
    unsigned int semente;
    while (ini <= fim)
    {
        cont  = 0;
        semente = ini;
        for (int i = 0; i <= tam && cont == i; i++)
        {
            for(int j=1;j<10000;j++)
                rand_r(&semente);
            if(rand_r(&semente)%256 == v[i])
                cont++;
            
        }
        if(cont == tam)
            return ini;
        ini++;
    }
    return ini;
}

int main(){
    unsigned int ini, fim, r;
    int *v;
    int i = 0;
    int t = 10000;

    v = malloc(sizeof(int)*t);
    scanf("%u %u", &ini, &fim);
    while (scanf("%d", &v[i++]) != EOF)
        if(i == t - 2){
            t = 2 * t;
            v = realloc(v, sizeof(int) * t);
        }
    
    r = mudou(v, i-1,ini, fim);
    
    printf("%u\n", r);
    return 0;
}