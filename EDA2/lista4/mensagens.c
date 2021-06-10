#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Key(A) (A.num)
#define less(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
#define exch(A, B){Item t = A; A = B; B = t;}
#define cmpexch(A, B){if(less(B, A)) exch(A, B)}

typedef struct Item
{
    int num;
    char msg;
}Item;

int partition(Item *v, int l, int r){
	Item pv = v[r];
	int j = l;
	int aux;

	for(int k = l; k < r; k++){
		if(lesseq(v[k], pv)){
			exch(v[k], v[j]);
			j++;
		}
	}

	exch(v[r], v[j]);	
	return j;
}

void quickSortM3(Item *v, int l, int r){
	int j;
	int m = (r+l)/2;
	if(r <= l)
		return;
	cmpexch(v[m], v[r]);
	cmpexch(v[l], v[m]);
	cmpexch(v[r], v[m]);

	j = partition(v, l, r);
	quickSortM3(v, l, j-1);
	quickSortM3(v, j+1, r);
}

int main(){
    Item *v;
    int i = 0;
    int tam = 10000;

    v = malloc(sizeof(Item) * tam);
    while (scanf("%d %c", &v[i].num, &v[i].msg) != EOF)
    {
        i++;
        if(i  == tam - 2){
            tam*=2;
            v = realloc(v, sizeof(Item) * tam);
        }
    }
    quickSortM3(v, 0, i-1);
    printf("%c", v[0].msg);
    for (int j = 1; j < i; j++)
        if(v[j].num != v[j-1].num)
            printf("%c", v[j].msg);
        
    printf("\n");
    
    return 0;
}