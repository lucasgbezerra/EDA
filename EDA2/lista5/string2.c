#include <stdio.h>
#include <string.h>

int main(){
    int c = 0;
    char str[1002];

    scanf("%s", str);
    while(str[c] != '\0')
        c++;
    
    for(int i = c - 1; i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");
    return 0;
}