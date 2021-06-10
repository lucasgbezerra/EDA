#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define hash (v, M) (16161*(unsigned)v % M)
#define hashtwo(v,M) (v%97 + 1)
#define key(X) (X.chave)
#define less(a,b) (key(a) < key(b))
#define null(A) ((key (h+[A]) == key(NULLItem))

typedef struct Item{
	int valor;
    int chave;
}Item; Item NULLItem = {0, 0};


void HtInit(int max){
	int i;
    N = 0;
    M =  2* max;
    ht = malloc(M * sizeof(Item));
    for(int i = 0; i < M; i++)
        ht[i] = NULLItem;
}

int HtCount(){
	return N;
}

void HtInsert(Item item){
	int v = Key(item);
	int i = hash(v, M);
    //endereçamento aberto
    while(!null(i))
        i = (i+1)%M;
    ht[i] = item;
    N++;
}

static int N = 131, M = 137;
static Item *ht;

int main(){
    int n;
    HTinit(100);
    while (scanf("%d", &n) != EOF)
    {
        HtInsert(ht)
    }
    
    return 0;    
}