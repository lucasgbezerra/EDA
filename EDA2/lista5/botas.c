#include <stdio.h>
#include <stdlib.h>

#define M 31
#define hash(v, M) (v%M)
#define key(X) (X.chave)
#define less(a,b) (key(a) < key(b))
typedef int Item;

typedef struct par{
	int e, d;
}par; par NullItem = {0,0};


static int N;
par *ht;

void HtInit(int max){
    N = 0;
    ht = malloc(M * sizeof(par));
    for(int i = 0; i < M; i++)
        ht[i] = NullItem;
}

void HtInsert(int item, char lado){
	int v = item;
	int i = hash(v, M);
    //endereçamento aberto
	if(lado == 'E'){
    	ht[i].e++;
	}else
    	ht[i].d++;
    N++;
}


int main(){
	int num;
	char lado;
	int cont = 0;
	ht = malloc(sizeof(par) * M);

	while(scanf("%d %c", &num, &lado) != EOF){	
		HtInsert(num, lado);
	}
	for(int i =0; i < M; i++){
		if(ht[i].e != 0 && ht[i].e <= ht[i].d)
			cont+= ht[i].e;
		else if(ht[i].e != 0 && ht[i].e > ht[i].d)
			cont+= ht[i].d;
	}
	printf("%d\n", cont);
	return 0;
}
