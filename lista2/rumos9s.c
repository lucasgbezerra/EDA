#include <stdio.h>

int convert(char *str){
    int dig, i = 0, sum=0;
    while(str[i] != '\0')
    {
        dig = (int)str[i] - 48;
        sum+=dig;
        i++;
    }
    return sum;
}
int soma(int num, int *degree)
{
    int sum = 0;
    *degree+=1;
    if(num > 9){
        while (num != 0)
        {
            sum+=num%10;
            num = num/10;
        }        
        soma(sum, degree);
    }else
        return num;
    
}

int main()

{
    char str[1001];
    int degree=0;
    int sum =0;

    scanf("%s", str);
    while(str[0] != '0')
    {
        sum = convert(str);
        sum = soma(sum, &degree);
        if(sum == 9){
            printf("%s is a multiple of 9 and has 9-degree %d.\n", str, degree);
        }else
        {
            printf("%s is not a multiple of 9.\n", str);   
        }
        scanf("%s", str);
        degree=0;
    }

    return 0;
}