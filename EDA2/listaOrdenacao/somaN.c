#include <stdio.h>

int main(){
	int n, a, result = 0;

	scanf("%d", &n);

	for(int i = 0; i < n ;i++){
		scanf("%d", &a);
		result+= a;
	}
	printf("%d\n", result);

	return 0;
}

