#include <stdio.h>

int main(){
    char frase[10000] , word1[40], word2[40];
    int len_frase=0, len_word1=0, cont =0;
    scanf("%[^\n]", frase);
    scanf("%s %s", word1, word2);

    do{
        len_frase++;
    }while (frase[len_frase] != '\0');
    do{
        len_word1++;
    }while (word1[len_word1] != '\0');
    
    for (int i = 0; i < len_frase; i++)
    {
        if(frase[i] == word1[cont])
        {
            cont++;
        }else{
            if(cont != 0){
                i -= cont;
                cont = 0;
            }
            printf("%c", frase[i]);
        }
        if(cont == len_word1){
            printf("%s", word2);
            cont =0;
        }

       
    }
    printf("\n");

	return 0;
}

