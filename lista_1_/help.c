#include <stdio.h>
#include <stdlib.h>

int main()
{
    char fraseEntrada[10001];
    char fraseCopia[10001];
    char palavraProcurada[41];
    char palavraParaTroca[41];
    int contador , tamanhoProcurada, tamanhoParaTroca, tamanhoEntrada,z,x = 0;

    scanf(" %[^\n]s", fraseEntrada);
    scanf(" %[^\n]s", palavraProcurada);
    scanf(" %[^\n]s", palavraParaTroca);

    for(tamanhoEntrada = 0;fraseEntrada[tamanhoEntrada] != '\0';tamanhoEntrada++);
    for(tamanhoProcurada = 0;palavraProcurada[tamanhoProcurada] != '\0';tamanhoProcurada++);
    for(tamanhoParaTroca = 0;palavraParaTroca[tamanhoParaTroca] != '\0';tamanhoParaTroca++);
    
    for (int i = 0;i < tamanhoEntrada;i++)
    {
        if (fraseEntrada[i] == palavraProcurada[0])
        {   
            contador = 0;
            for (int c = 0;c < tamanhoProcurada;c++)
            {
                if (fraseEntrada[i+c] == palavraProcurada[c])
                {
                    contador++;
                }
            }
            if (contador == tamanhoProcurada)
            {
                for(z = 0;z < tamanhoParaTroca;z++)
                {
                    fraseCopia[i] = palavraParaTroca[z];
                    i++;
                    x++;
                }
            }else{
                contador =0;
                fraseCopia[i] = fraseEntrada[i-x];
            }
        }else{
            fraseCopia[i] = fraseEntrada[i-x];
        }
    }
    for(int a = 0;a < tamanhoEntrada + (tamanhoParaTroca - tamanhoProcurada);a++)
    {
        printf("%c",fraseCopia[a]);
    }
    printf("\n");
    return 0;
}