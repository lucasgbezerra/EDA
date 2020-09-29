#include <stdio.h>

int main(){
	int num_trilhas;
	int id_trilha;
	int num_medicoes;
	int subida_ida;
	int subida_volta;
	int menor_subida =0;
	int med=0;
	int med_ant;

	scanf("%d", &num_trilhas);
	for(int x =1; x <= num_trilhas; x++){
		scanf("%d", &num_medicoes);
		subida_ida =0;
		subida_volta =0;
		for(int i = 0; i<num_medicoes; i++){
			med_ant = med;
			scanf("%d", &med);
			if(i > 0){
				if((med-med_ant) > 0){
					subida_ida += med - med_ant;
				}
				if(med_ant - med > 0){
					subida_volta += med_ant - med;
				}
			}
		}
		if(x == 1 ){
			if(subida_ida > subida_volta)
				menor_subida = subida_volta;
			else
				menor_subida = subida_ida;
			id_trilha = x;
		}
		if(x >1){
			if(subida_ida < menor_subida){
				menor_subida = subida_ida;
				id_trilha = x;
				}
			if(subida_volta < menor_subida){
				menor_subida = subida_volta;
				id_trilha = x;
			}
		}
	}
	printf("%d\n", id_trilha);

	return 0;
}
