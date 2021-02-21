#include <stdio.h>
int main(){
		int ent, dia = 0;
		int rest, nota, best_rest, best_nota;
	while (scanf("%d", &ent) != EOF)
	{

		dia++;
		for(int c =0; c < ent; c++){
			scanf("%d %d", &rest, &nota);
			if(c ==0){
				best_nota =nota;
				best_rest = rest;
			}
			if(nota >= best_nota){
				if(nota == best_nota){
					best_nota = best_rest > rest ? nota : best_nota;
					best_rest = best_rest > rest ? rest : best_rest;
				}else
				{
					best_nota = nota;
					best_rest = rest;	
				}
				
			}
		}
		printf("Dia %d\n%d\n\n", dia, best_rest);
	}
	

	return 0;
}
