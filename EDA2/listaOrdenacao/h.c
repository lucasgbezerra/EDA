#include <stdio.h>
#include <stdlib.h>

int verifica(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  

        if (arr[mid] == x) 
            return mid; 
  
      
        if (arr[mid] > x) 
            return verifica(arr, l, mid - 1, x); 
  
        return verifica(arr, mid + 1, r, x); 
    } 
  
   
    return -1; 
}

int *merge(int *v, int l, int m, int r){
	int tl = m-l+1;
	int tr = r-m;

	int *vl = malloc(tl * sizeof(int));
	int *vr	= malloc(tr * sizeof(int));

	for( int i = 0; i < tl; i++)
		vl[i] = v[l+i];
	for( int i = 0; i < tr; i++)
		vr[i] = v[m+1+i];
	
	int i = 0, j = 0, k = l; // index 

	while(i < tl && j < tr){
		if(vl[i] <= vr[i])
			v[k++] = vl[i++]; //k++, usa o k atual e incrementa
		else
			v[k++] = vr [j++];
	
	}
	while(i < tl)
		v[k++] = vl[i++];

	while(j < tr)
		v[k++] = vr[j++];
	
}
void mergeSort(int *v,  int l, int r){
	if(l >= r)
		return;

	int meio = (l + r - 1)/2;
	mergeSort(v, l, meio);
	mergeSort(v, meio + 1, r);
	merge(v, l, meio, r);
		
}
int main(){
	int v[1000000];
	int n, x, cont = 1;

	scanf("%d", &n);
	scanf("%d", &v[0]);
	
	for(int i = 1; i < n; i++){
		mergeSort(v, 0, i-1);
		scanf("%d", &x);
		if(verifica(v, 0, i-1, x) == -1){
			v[i] = x;
			cont++;			
		}
	}
	printf("%d\n", cont);
	return 0;
}