#include <stdio.h>

int main ()
{
	int n,c =0,m;

	while(scanf("%d",&n) != EOF)
	{
		if (c == 0)
			m = n;
		
		if (n > m)
			m = n;

		c = 1;
	}
	printf("%d\n",m);
	return 0;
}
