#include <stdio.h>
#include <string.h>

int main(){
    int c = 0, n, maior = -1;
    char str[1002];

    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", str);
        while(str[c] != '\0')
            c++;
        if(c > maior)
            maior = c;
    }
    printf("%d\n", c);
    return 0;
}