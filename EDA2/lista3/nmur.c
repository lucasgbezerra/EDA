#include <stdio.h>
#include <stdlib.h>

//Números malucos únicos reinseridos
//Questão da P1
int *intercala(int *va,int la, int ra, int *vb, int lb, int rb){
	int ta = ra - la + 1;
	int tb = rb - lb + 1;
	int *vc = malloc(sizeof(int) * (ta+tb));
	int lc = 0, rc = ta + tb - 1;
	int ia = la, ib = lb, ic = lc;
	while(ia <= ra && ib <= rb){
		if(va[ia] <= vb[ib])
			vc[ic++] = va[ia++];		
		else
			vc[ic++] = vb[ib++];		
	}
	while(ia <= ra)
		vc[ic++] = va[ia++];		
	while(ib <= rb)
		vc[ic++] = vb[ib++];		

	return vc;
}

void mergeSort(int *v, int l, int r){
	if(l >= r)
		return;
	int m = (r + l)/2;
	mergeSort(v, l, m);
	mergeSort(v, m+1, r);
	
	int *c = intercala(v, l, m, v, m+1, r);
	
	for(int i = 0; i < (r + 1); i++)
		v[l++] = c[i];
		//printf("c[%d] %d\n", i, c[i]);
	free(c);

}

int buscaBinaria(int *v, int l, int r, int x){
	if(l == r - 1){
		if(v[l] == x)
			return l;
		else if(v[r] == x)
			return r;
		else
			return -1;
	}
	int m = (r+l)/2;
	if(v[m] > x)
		buscaBinaria(v, l, m, x);
	else
		buscaBinaria(v, m, r, x);
		

}
int main(){
	int *v, n;

	scanf("%d", &n);

	v = malloc((n+(n/2)+1) * sizeof(int));

	for( int i = 0; i < n; i++)//Ler números
		scanf("%d", &v[i]);

	mergeSort(v, 0, n-1); //ordenar

	int ni = 0;
	for(int i = 1; i < n; i++){
		if(v[i] !=  v[ni])
			v[++ni] = v[i];	
	}
	ni++;
	if(ni %2 != 0)
		v[ni++] = 1000000000;
	n = ni;
	for(int i = 1; i < n; i+=2){
		int nm = v[i] + v[i-1];
		if(buscaBinaria(v, 0, n-1, nm) == -1)
			v[ni++] = nm;
	}
	printf("ni: %d\n", ni);
	n = ni;
	//mergeSort(v, 0, n-1);	
	for(int i = 0; i <= ni; i++)
		printf("%d\n", v[i]);



	return 0;
}
