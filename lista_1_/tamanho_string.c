#include <stdio.h>

int main(){
    char word[1000];
    int numb =0;

    scanf("%s", word);
    
    do{
        numb++;
    }while (word[numb] != '\0');
    
    printf("%d\n", numb);
    return 0;

}