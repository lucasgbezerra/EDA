#include <string.h>
#include <stdio.h>

int main(){
    char str[102];
    int cont = 0, c;

    while (scanf("%s", str) != EOF)
    {
        c = 0;
        while (str[c] != '\0')
        {
            if(str[c] == 'o')
                cont++;
            c++;
        }
        
    }
    printf("%d\n", cont);

    return 0;
}