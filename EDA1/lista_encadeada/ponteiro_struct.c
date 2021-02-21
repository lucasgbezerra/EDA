#include <stdio.h>
typedef struct no
{
    int hora;
    int minuto;

}no;


int main()
{
    no  x;
    no *p;

    x.hora = 20; //atribuição direta
    p = &x;
    p->minuto = 11; //atibuição pelo ponteiro

    printf("%d:%d\n\n", x.hora, p->minuto);

    int number=21;
    int *numberP = &number;
    int **numberPP = &numberP;

    printf("&number: %p\n",&number);  //End de number
    printf("number: %d\n\n",number);    //Valor de number = 21

    printf("&numberP: %p\n",&numberP); //endereço de numberP 
    printf("*numberP: %d\n",*numberP);  //valor de numberP = 21
    printf("numberP: %p\n\n",numberP);    //Endereço apontado pelo numberP = &number

    printf("&numberPP: %p\n",&numberPP);    //End. de numberPP
    printf("**numberPP: %d\n",**numberPP);    //Valor de numberPP   = number
    printf("*numberPP: %p\n",*numberPP);    //Valor de numberPP = &number
    printf("numberPP: %p\n",numberPP);    //Endereço apontado pelo numberPP = &numperP




    return 0;
}