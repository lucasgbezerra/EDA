#include <stdio.h>

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exchange(A, B) {int t = A; A = B; B = t;}
#define cmpexch(A,B) {if less (B, A) exchange(A, B)}

void bubbleSort(int *v, int l, int r){
	for(int i = 1; i < r; i++)
		for(int j = l+1; j <= r; j++)
				cmpexch(v[j-1], v[i]);
}

int main(){
	int v[1001], i = 0;

	while(scanf("%d", &v[i]) != EOF)
		i++;
	bubbleSort(v, 0, i);
	for(int c = 0; c < i; c++)
		printf("%d ", v[c]);
	printf("\n");

	return 0;
}
