#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int *v, int l, int r,int x){

	int meio = (r + l)/2;
	if(l == r -1){
		if(x > v[r])
			return r+1;
		else if(x <= v[l])
			return l;
		else
			return r;	
	}
		
	if(x < v[meio])
		return buscaBinaria(v, l,meio, x);
	else
		return buscaBinaria(v, meio, r, x);

}

int main(){
	int n, m, x, r;
	int *v;

	scanf("%d %d", &n, &m);
	v = malloc(n * sizeof(int));

	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);		

	for(int i = 0; i < m; i++){
		scanf("%d", &x);
		r = buscaBinaria(v, 0,n-1,x);
		printf("%d\n", r);
	}		
		
	return 0;
}
