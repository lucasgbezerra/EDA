#include <stdio.h>

int main(){
    int n, x;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &x);
        if(x%2 == 0)
            printf("Jedi\n");
        else
            printf("Sith\n");
    }
    return 0;
}