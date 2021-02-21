#include <stdio.h>

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exchange(A, B) {int t = A; A = B; B = t;}
#define cmpexch(A,B) {if less (B, A) exchange(A, B)}

void insertionSort(int *v, int l, int r){
	for(int i = r; i > l; i--)
		cmpexch(v[i-i], v[i]);
	for (int i = l+2; i <= r; i++){
		int j = i;
		int temp = v[j];
		while(less(temp, v[j-1])){
			v[j] = v[j-1];
			j--;
		}
		v[j] = temp;
	}
	
}

int main(){
	int v[50001], i = 0;

	while(scanf("%d", &v[i]) != EOF)
		i++;
	insertionSort(v, 0, i-1);
	for(int c = 0; c < i; c++)
		printf("%d ", v[c]);
	printf("\n");

	return 0;
}


