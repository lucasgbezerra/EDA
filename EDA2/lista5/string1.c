#include <stdio.h>
#include <string.h>

int main(){
    int c = 0;
    char str[1002];

    scanf("%s", str);
    while(str[c] != '\0')
        c++;

    printf("%d\n", c);
    return 0;
}