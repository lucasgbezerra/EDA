#include <stdio.h>

int main(){
	int num, maior_num = 0, inter= 0;

	while(scanf("%d", &num)!= EOF){
		inter++;
		maior_num = inter == 1 ? num : maior_num;
		maior_num = maior_num < num ? num : maior_num;
	}
	printf("%d\n", maior_num);
	return 0;
}
