#include <stdio.h>
#include <string.h>

void traduzP(char *str, char *txt){
    int c = 0;

    for(int i = 1; str[i] != '\0'; i+=2)
            txt[c++] = str[i];
    txt[c++] = '\0';
}

char rot13(char c){
    char rot;

    if(c <= 90){
        if(c + 13 > 90)
            rot = 64 + ((c + 13) - 90);
        else
            rot = c + 13;
    }else
    {
         if(c + 13 > 122)
            rot = 96 + ((c + 13) - 122);
        else
            rot = c + 13;
    }
    return rot;
}

int main(){
    char str[1000002];
    char x;
    char txt[1000002];
    char result[1000002];
    int c = 0;

    while (scanf(" %[^\n]", str) != EOF)
    {
        c = 0;
        traduzP(str, txt);
        while (txt[c] != '\0'){
            if((txt[c] >= 65 && txt[c]<= 90) || (txt[c] >= 97 && txt[c]<= 122))
                result[c] = rot13(txt[c]);
            else
                result[c] = txt[c];
            c++;    
        }
        result[c++] = '\0';
        memset(txt,0,sizeof(txt));
        memset(str,0,sizeof(str));
        printf("%s\n", result);
    }
    
    return 0;
}