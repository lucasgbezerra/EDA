#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define key(A) (A.cont)
#define eq(A, B) ((key(A)) == (key(B)))
#define less(A, B) ((key(A)) > (key(B)))
#define lesseq(A, B) ((key(A)) >= (key(B)))
#define exch(A, B){Item t = A; A = B; B = t;}
#define cmpexch(A, B){if(less(B, A)) exch(A, B)}

typedef struct Ced{
    int idx;
    int cont;
}Ced;
typedef Ced Item;


void merge(Item *v, int l, int m, int r){

	Item *R =  malloc(sizeof(Item)*(r-l+1));
	int i = l, j = m + 1, k = 0;

	while(i <= m && j <= r){
		if(less(v[i], v[j])){
			R[k++] = v[i++];
        }else if(eq(v[i], v[j])){
                if(v[i].idx > v[j].idx)
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
    int numS, numF, numE;
    int cp = 0, cs = 0, cf = 0, ce = 0, nulo = 0;
    Ced *pr, *sen, *fed, *est;
    int n;

    pr =  malloc(sizeof(Ced) * 100);
    sen = malloc(sizeof(Ced) * 1000);
    fed = malloc(sizeof(Ced) * 10000);
    est = malloc(sizeof(Ced) * 100000);

    memset(pr, 0,  sizeof(Ced) * 100);
    memset(sen, 0, sizeof(Ced) * 1000);
    memset(fed, 0, sizeof(Ced) * 10000);
    memset(est, 0, sizeof(Ced) * 100000);


    scanf("%d %d %d", &numS, &numF, &numE);
    while (scanf("%d", &n) != EOF){
        if(n >= 10 && n < 100){
            pr[n].cont++;
            pr[n].idx = n;
            cp++;
        }else if(n >= 100 && n < 1000){
            sen[n].cont++;
            sen[n].idx = n;
            cs++;
        }else if(n >=1000 && n < 10000){
            fed[n].cont++;
            fed[n].idx = n;
            cf++;
        }else if(n >= 10000 && 99999){
            est[n].cont++;
            est[n].idx = n;
            ce++;
        }else{
            nulo++;
        }
    }

    printf("%d %d\n", cp+cs+cf+ce, nulo);
    //presidente
    mergeSort(pr, 0, 99);
    double r = pr[0].cont * 1.0 / cp;
    if(r > 0.5)
        printf("%d\n", pr[0].idx);
    else
        printf("Segundo Turno\n");
    
    //Senador
    mergeSort(sen, 0, 999);
    for(int i = 0; i < numS; i++){
        printf("%d", sen[i].idx);
        if(i != numS-1)
            printf(" ");
    }
    printf("\n");

    //Dep. Federal
    mergeSort(fed, 0, 9999);
    for(int i = 0; i < numF; i++){
        printf("%d", fed[i].idx);
         if(i != numF-1)
            printf(" ");
    }
    printf("\n");

    //Dep.Estadual
    mergeSort(est, 0, 99999);
    for(int i = 0; i < numE; i++){
        printf("%d", est[i].idx);
        if(i != numF-1)
            printf(" ");
    }
    printf("\n");

    return 0;
}