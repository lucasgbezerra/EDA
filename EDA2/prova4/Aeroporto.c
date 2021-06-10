#include <stdio.h>
#include <stdlib.h>

int main(){

	int A, V, t=1, *Ae, x, y, m;
	while(1){
		scanf("%d %d", &A, &V);
		m = 0;
		if(A == 0 && V == 0)
			break;
		Ae = calloc(A+1, sizeof(int));
		for(int i=0;i<V;i++){
			scanf("%d %d", &x, &y);
			Ae[x]++;
			Ae[y]++;
			if(Ae[x]>=m)
				m = Ae[x];
			if(Ae[y]>m)
				m = Ae[y];
		}
		printf("Teste %d\n", t);
		for(int i=1;i<=A;i++)
			if(Ae[i] == m)
				printf("%d ", i);
		printf("\n\n");
		free(Ae);
		t++;
	}
}
