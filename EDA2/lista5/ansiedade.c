#include <stdio.h>
#include <stdlib.h>

int main(){
    int cont = 0, sim = 0, out = 0;
    char resp[4];

    while (scanf("%s", resp) != EOF)
    {
        cont++;
        if(resp[0] == 's')
            sim++;
        if(cont == 10){
            if(sim >= 2)
                out++;
            cont = 0;
            sim = 0;
        }
    }
    
    printf("%d\n", out);
    return 0;
}