#include <stdio.h>
//Caso base 1 dig e não é 7
void conta_7s(long int num, long int *num7s)
{
    if(num  != 0){
        conta_7s(num/10, num7s);
        if(num%10 == 7)
            *num7s+=1;
    }else
        return;  
}

int main()
{
    long int num, num7s=0;
    scanf("%ld", &num);
    conta_7s(num, &num7s);
    printf("%ld\n", num7s);

    return 0;
}