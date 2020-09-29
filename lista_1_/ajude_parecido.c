#include <stdio.h>

int main(){
	int contas;
	int sum_contas=0;
	int resp;
	for(int i =0; i<3; i++){
		scanf("%d", &contas);
		sum_contas += contas;
	}
	scanf("%d", &resp);
	
	if(resp == sum_contas)
		printf("Acertou\n");
	else
		printf("Errou\n");
	return 0;

}
