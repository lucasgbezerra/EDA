#include <stdio.h>
#include <string.h>

int main(){
    int c = 0, n, maior = -1;
    char str[102], max[102];

    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", str);
        while(str[c] != '\0')
            c++;
        if(c > maior){
            maior = 0;
             for(int i = 0; i < c; i++)
                max[maior++] = str[i];
            max[maior] = '\0';
            maior = c;
        }
       
    }
    printf("%s\n", max);
    return 0;
}