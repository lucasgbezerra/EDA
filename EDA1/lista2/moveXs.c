#include <stdio.h>
// Caso base não tem x

void imprime(char *str, int n)
{
    if(str[n] == '\0')
        return;
    else
    {
        if(str[n] != 'x'){
            printf("%c", str[n]);
            imprime(str,n+1);
        }else
        {
            imprime(str,n+1);
            printf("%c", str[n]);
        }
        
    }
}
int main()
{
    char str[101];
    scanf("%s", str);
    imprime(str,0);
    printf("\n");  
    return 0;
}