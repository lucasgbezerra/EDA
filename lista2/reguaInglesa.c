#include <stdio.h>
int pot(int a, int b)
{
    if(b==0)
        return 1;
    else 
        return a*pot(a,b-1);
}
void desenho_tracos(int ordem)
{
    if(ordem > 0){
        printf("-");
        desenho_tracos(ordem-1);
    }else
        printf("\n");
}
void regua_inglesa(int ordem, int n_dots)
{
    int pm = n_dots/2;
    if(ordem >0){
        regua_inglesa(ordem-1, pm);
        printf("ORDEM: %d\n", ordem);
        printf(".");
        desenho_tracos(ordem);
        regua_inglesa(ordem-1, pm);
    }else
        return;

}
int main()
{
    int ordem, n_dots;
    scanf("%d", &ordem);
    n_dots = pot(2,ordem) -1;
    regua_inglesa(ordem, n_dots);
    return 0;
}