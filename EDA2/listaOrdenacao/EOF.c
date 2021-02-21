#include <stdio.h>

int main(){
	int num = 0;
	int x;

	while( scanf("%d", &x) != EOF)
		num++;

	printf("%d\n", num);
	return 0;
}

