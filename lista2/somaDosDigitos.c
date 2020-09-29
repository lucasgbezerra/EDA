#include <stdio.h>
//Soma dos digitos
//Caso base são números com apenas um digito
void soma_dos_digitos(long int numb, long int *result)
{
    if(numb<10){
        *result+=numb;
    }else{
        soma_dos_digitos(numb/10,result);
        *result+=numb%10;
    }
}

int main()
{
    long int numb, result=0;
    scanf("%ld", &numb);
    soma_dos_digitos(numb, &result);
    printf("%ld\n",result);
    return 0;
}

/*
int soma_dos_digitos(int num)
{
    if (num < 10)
        return num;
    else
        return (num % 10) + soma_dos_digitos(num / 10);

}

int main()
{
    long int num;
    int result
    
    scanf("%d", num);
    resutl = soma_dos_digitos(num)
    printf("%ld\n",result);
}
*/
