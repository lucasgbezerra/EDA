#include <stdio.h>
void desenho_tracos(int ordem)
{
    if(ordem > 0){
        printf("-");
        desenho_tracos(ordem-1);
    }else
        printf("\n");
}
void regua_inglesa(int ordem)
{
    if(ordem >0)
    {
        regua_inglesa(ordem-1);
        printf(".");
        desenho_tracos(ordem);
        regua_inglesa(ordem-1);
    }else
        return;

}
int main()
{
    int ordem;
    scanf("%d", &ordem);
    regua_inglesa(ordem);
    return 0;
}