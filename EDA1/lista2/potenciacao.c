#include <stdio.h>
//Potenciação - Recursão
//Identificar caso base
//  o caso base é a⁰, que será sempre i
float pot(int a, int b)
{
    if(b==0)
        return 1.0;
    else{
        if(b>=0)
            return a*pot(a,b-1);
        else
            return 1/(a*1.0)*pot(a,b+1);
    }
}

int main()
{
    float result;
    int a, b;

    scanf("%d %d", &a, &b);
    if(a==0 && a==b)
        printf("indefinido\n");
    else
    {
        result = pot(a,b);
        printf("%f\n", result);
    }
    return 0;
}