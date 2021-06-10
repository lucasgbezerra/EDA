#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Key(x) (x.cod)
#define less(a,b) (Key(a) < Key(b))
#define null(A) ((Key (ht[A]) == Key(nullItem))) //item null?
#define M 5003
#define hash(v, M) (v%M)

typedef struct Item
{
    int cont;
    int cod;
}Item; Item nullItem = {0 , 0};

static int N;
int maior;
int HTcount(){
	return N;
}

void HTinsert(Item *ht, int item){
	int v = item;
	int i = hash(v, M);
    //endereçamento aberto
    /*
    while(!null(i))
        i = (i+1) % M;
    */
    if(ht[i].cod == v){
        ht[i].cont++;
        if(ht[i].cont++ > maior)
            maior = ht[i].cod;
    }else{
        ht[i].cod = item;
        ht[i].cont++;
        N++;
    }

}

//Busca
/*
Item HTsearch(int v){
	int i = hash(v, M);
	while(!null(i))
		if(eq(v, Key(ht[i])))
			return ht[i];
		else
			i = (i+1) % M;
	return nullItem;
}
*/

int main(){
    int n, cod;
    Item input;
    scanf("%d", &n);
    while (n != 0)
    {
        Item *ht;
        N = 0;
        maior = 0;
        ht = malloc(M * sizeof(Item));
        for(int i = 0; i < M; i++){
            ht[i].cont = 0;
            ht[i].cod = 0;
        }
        while (n--){
            scanf("%d", &cod);

            HTinsert(ht, cod);
        }
        //for(int i = 0; i < M; i++)
            //if(ht[i].cont != 0)
                //printf("%d: %d\n",ht[i].cod, ht[i].cont);
        printf("%d\n", maior);
        scanf("%d", &n);
        free(ht);
    }
    
    
    
    return 0;
}