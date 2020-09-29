#include <stdio.h>

int main(){
	int num_linhas, dot=0, c=1;
	scanf("%d", &num_linhas);
	for(int i =num_linhas; i > 0; i--){
		for(int c = 0; c < i-1; c++){
			printf(" ");
		}
		for(int x = 0; x < c; x++){
			printf("*");
		}
		printf("\n");
		c+=2;
	}
	return 0;
}
