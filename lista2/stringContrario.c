#include <stdio.h>
// Caso base uma string de apenas \0
void inverte_string(char *str, int n)
{
    if(str[n] == '\0')
        return;
    else
    {
        inverte_string(str,n+1);
        printf("%c", str[n]);
    }
    
}

int main()
{
    char str[501];
    scanf("%s", str);
    inverte_string(str,0);
    printf("\n");
    return 0;
}