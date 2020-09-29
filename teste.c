#include <stdio.h>

int main()
{

    int var;
	char *ptr;
	ptr = &var;
	ptr[0] = 's';
	ptr[1] = 'o';
	ptr[2] = 'l';
	ptr[3] = '\0';
	// printf("end var: %p\n", &var);
	// printf("var: %d\n", var);
	// printf("ptr[0]: %p\n", &ptr[0]);
	// printf("ptr[0]: %c\n", ptr[0]);
	// printf("ptr[1]: %p\n", &ptr[1]);
	// printf("ptr[1]: %c\n", ptr[1]);
	// printf("ptr[2]: %p\n", &ptr[2]);
	// printf("ptr[2]: %c\n", ptr[2]);
	// printf("rest %d\n",(var-3584)/255);
	printf( "%s ... var = %d\n\n", (char *) ptr, var);
	var = var - 256;
	printf( "%s ... var = %d\n\n", (char *) ptr, var);

	
	return 0;
}
