#include <stdio.h>

int main(){
    int n_aero, n_voos, cont=0, x, y, maior_num_voos=0, id=0;
    int qtd_voos_por_aero[110]={};

    do
    {
        scanf("%d %d", &n_aero, &n_voos);

        if(n_aero != 0 || n_voos != 0)
        {
            for(int c = 0; c< n_voos; c++)
            {
                scanf("%d %d", &x, &y);

                for (int i = 1; i <= n_aero; i++)
                {
                    if( i == x || i == y)
                    {
                        qtd_voos_por_aero[i]++;
                    }
                }
            }
            for (int i = 1; i <= n_aero; i++)
            {
                if(qtd_voos_por_aero[i] > maior_num_voos){
                   maior_num_voos = qtd_voos_por_aero[i];
                }
            }
            
            cont++;
            printf("Teste %d\n", cont);
            for (int i = 1; i <= n_aero; i++)
            {
                if(qtd_voos_por_aero[i] == maior_num_voos)
                {
                    printf("%d ", i);
                }
            }
            printf("\n\n");
            maior_num_voos = 0;
        }
       for(int c =0; c <= n_aero; c++)
            {
                qtd_voos_por_aero[c] =0;
            }
    }while (n_aero != 0 || n_voos != 0);

    return 0;
}