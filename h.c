#include <stdio.h>

int main()
{
	int c,p;
	p=7;
	scanf("%d",&c);
	if (c > 100)
	{	
		p+= (c- 100)*5;
		c=100;
	}

	if (c > 30)
	{
		p+=(c-30)*2;
		c =30;
	}

	if (c > 10)
		p+=c-10;
	printf("%d\n",p);
	return 0;
}
