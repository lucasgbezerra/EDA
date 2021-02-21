#include <stdio.h>
#include <string.h>

void reprovado(int n){
    char repr[21], nome[21];
	int notaRepr, nota, inst = 0;
    scanf("%s %d", repr, &notaRepr);
    	for(int i = 1; i < n; i++){
    		scanf("%s %d", nome, &nota);
    		if( nota < notaRepr){
    			notaRepr = nota;
    			strcpy(repr, nome);
    		}else if(nota == notaRepr){
    			if(strcmp(repr, nome) < 0){
    				notaRepr = nota;
    				strcpy(repr, nome);

    			}
    		}
    	}
		printf("%s\n", repr);

}
int main(){
	int n, inst = 1;
	scanf("%d", &n);
	
	while(scanf("%d",&n) != EOF){
	    printf("Instancia %d\n", inst++);
	    reprovado(n);
	    printf("\n");
	}
	return 0;

}
