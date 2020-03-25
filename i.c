#include <stdio.h>

int main()
{
	unsigned long long int cpf,cpft;
	int dv,soma =0,d1,d2,c;

	scanf("%llu",&cpf);
	dv = cpf % 100;
	
	cpft = cpf/100;
	for(int i = 2; i < 11 ; i++)
	{
		soma += cpft%10 * i;
		cpft = cpft/10;
	}


	if(soma%11 < 2)
	{
		d1 = 0;
	}else{
		d1 =11 -( soma%11 );
	}

	soma =0;
	cpft =( cpf/100)*10+d1;
	
	for (int i = 2; i < 12; i++)
	{
		soma+= cpft % 10 *i;
		cpft = cpft / 10;
	}

	if(soma%11 < 2)
        {
                d2 = 0;
        }else{
                d2 =11 -( soma%11 );
        }
	c = (d1*10)+d2;
	if (dv == c){
		printf("valido\n");
	}else{
		printf("invalido\n");
	}
	
	return 0;
}
