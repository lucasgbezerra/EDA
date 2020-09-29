#include <stdio.h>

int main(){
	int id_m=0, id_a=0, id_b=0, id_c=0, older;
	

	scanf("%d", &id_m);
	scanf("%d", &id_a);
	scanf("%d", &id_b);

	id_c = id_m - (id_a+id_b);

	if((id_a > id_b) && (id_a > id_c)){
		older = id_a;
	}else if(id_b > id_c){
		older = id_b;
	}else{
		older = id_c;
	}

	printf("%d\n", older);
	return 0;
}
