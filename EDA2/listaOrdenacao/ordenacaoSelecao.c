#include <stdio.h>

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exchange(A, B) {int t = A; A = B; B = t;}
#define cmpexch(A,B) {if less (B, A) exchange(A, B)}

void selectionSort(int *v, int l, int r){
	for(int i = l; i < r-1; i++){
		int minIdx = i;
		for(int j = i+1; j < r; j++)
			if(less(v[j], v[minIdx]))	
				minIdx = j;
		exchange(v[i], v[minIdx]);
	}
}

int main(){
	int v[1001], i = 0;

	while(scanf("%d", &v[i]) != EOF)
		i++;
	selectionSort(v, 0, i);
	for(int c = 0; c < i; c++)
		printf("%d ", v[c]);
	printf("\n");

	return 0;
}
