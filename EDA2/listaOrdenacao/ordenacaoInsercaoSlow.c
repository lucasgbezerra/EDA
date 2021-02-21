#include <stdio.h>

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exchange(A, B) {int t = A; A = B; B = t;}
#define cmpexch(A,B) {if less (B, A) exchange(A, B)}

void insertionSortSlow(int *v, int l, int r){
	for(int i = l+1; i <= r; i++){
		for(int j = i; j > l; j--)
				cmpexch(v[j-1], v[j]);
	}
}

int main(){
	int v[1001], i = 0;

	while(scanf("%d", &v[i]) != EOF)
		i++;
	insertionSortSlow(v, 0, i-1);
	for(int c = 0; c < i; c++)
		printf("%d ", v[c]);
	printf("\n");

	return 0;
}
