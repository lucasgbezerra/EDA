#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct ced
{
    int valor;
    int contagem;
}ced;

typedef ced Item;
#define Key(A) (A.contagem) 
#define less(A, B) (Key(A) > Key(B))
#define eq(A, B) (Key(A) == Key(B))
#define lesseq(A, B) (Key(A) >= Key(B))
#define exch(A, B){Item t = A; A = B; B = t;}
#define cmpexch(A, B){if(less(B, A)) exch(A, B)}

void merge(Item *v, int l, int m, int r){

	Item *R =  malloc(sizeof(Item)*(r-l+1));
	int i = l, j = m + 1, k = 0;

	while(i <= m && j <= r){
		if(less(v[i], v[j]))
			R[k++] = v[i++];
		else if(eq(v[i], v[j])){
            if(v[i].valor > v[j].valor)
                R[k++] = v[i++];
            else
			    R[k++] = v[j++];

        }else 
			R[k++] = v[j++];
	}
	while(i <= m)
		R[k++] = v[i++];

	while(j <= r)
		R[k++] = v[j++];

    k = 0;
	for(int i = l; i <= r; i++)
		v[i] = R[k++];

	free(R);
}
void mergeSort(Item *v,  int l, int r){
	if(l >= r)
        return;

    int meio = (l + r)/2;
    mergeSort(v, l, meio);
    mergeSort(v, meio+1, r);
    merge(v, l, meio, r);
    
}

int main(){
    char x;
    ced *v;
    int i =0;

    v = malloc(sizeof(ced)* 150);
    memset(v, 0, sizeof(ced) * 150);
    
    while (scanf("%c", &x) != EOF)
    {
        if(x != '\n'){
            if(v[(int)x].contagem == 0)
                i++;
            v[(int)x].contagem++;
            v[(int)x].valor = (int)x;
        }else{
            mergeSort(v, 0, 150);
            for(int j = i-1; j >= 0; j--){
                printf("%d %d\n", v[j].valor, v[j].contagem);
            }
            printf("\n");
            memset(v, 0, sizeof(ced) * 150);
            i = 0;

        }
    }
    
    return 0;
}