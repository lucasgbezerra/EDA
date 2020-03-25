#include <stdio.h>
int main()
{
	int num[11], som = 0, d1, d2, dv1, dv2;
	char cpf[11];
	scanf(" %s", cpf);
	for (int i=0; i < 11; i++)
	{
		num[i] = cpf [i] - 48;
	}

	dv1 = num[9];
	dv2 = num[10];
	
	for (int i = 0; i<9; i++)
	{
		som += num[i]*(10-i);
	}
	
	if(som % 11 < 2 ){
		d1 = 0;
	}else{
		d1 = 11 -(som % 11);
	}
	
	num[9] = d1;
	som =0;

	for (int i = 0; i<10; i++)
        {
                som += num[i]*(11-i);
        }
        if(som % 11 < 2 ){
                d2 = 0;
        }else{
                d2 = 11 -(som % 11);
        }
	num[10] = d2;

	if (dv1 == d1 && dv2 == d2)
	{
		printf("valido\n");
	}else{
		printf("invalido\n");
	}
	return 0;
}
