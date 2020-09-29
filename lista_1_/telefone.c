#include <stdio.h>

int main(){
    char number[15];
    int i=0;

    scanf("%s", number);
    while (number[i] != '\0')
    {
         if(number[i] == 'A' || number[i] == 'B' || number[i] == 'C' )
            number[i] = '2';
        else if(number[i] == 'D' || number[i] == 'E' || number[i] == 'F' )
            number[i] = '3';
        else if(number[i] == 'G' || number[i] == 'H' || number[i] == 'I' )
            number[i] = '4';
        else if(number[i] == 'J' || number[i] == 'K' || number[i] == 'L' )
            number[i] = '5';
        else if(number[i] == 'M' || number[i] == 'N' || number[i] == 'O' )
            number[i] = '6';
        else if(number[i] == 'P' || number[i] == 'Q' || number[i] == 'R' || number[i] == 'S' )
            number[i] = '7';
        else if(number[i] == 'T' || number[i] == 'U' || number[i] == 'V' )
            number[i] = '8';
        else if(number[i] == 'W' || number[i] == 'X' || number[i] == 'Y' || number[i] == 'Z' )
            number[i] = '9';
        i++;
    }
    printf("%s\n", number);

    return 0;
}