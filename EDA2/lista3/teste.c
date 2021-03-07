#include <stdio.h>
#include <stdlib.h>

#define less(A, B) ((A.ele) < (B.ele))
#define lesseq(A, B) ((A.ele) <= (B.ele))
#define exch(A, B){no t = A; A = B; B = t;}
#define cmpexch(A, B){if(less(B, A)) exch(A, B)}

typedef struct no{
	unsigned long int  ele;
	unsigned long int prx;
	unsigned long int ant;
}no;
int buscaBinaria(no *v, int l, int r, unsigned long int x){
	int m = (r+l)/2;	

	if(l == r -1){
		if(v[l].ele == x)
			return l;
		if(v[r].ele == x)
			return r;
		else
			return -1;
	}
	
	if(x < v[m].ele)
		return buscaBinaria(v, l, m, x);
	else
		return buscaBinaria(v, m, r, x);
}

int partition(no *v, int l, int r){
	no pv = v[r];
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
void quickSortM3(no *v, int l, int r){
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
	no *v;
	int i = 0, t = 10000;
	no ptr1, ptr2, *ptr, *cam;
	int idx, k = 0;
	
	v = malloc(sizeof(no) * t);
	while(scanf("%lx %lx %lx", &v[i].ele, &v[i].ant, &v[i].prx) != EOF){
		i++;
		if(i == t-10){
			//v = realloc(v, 2*t * sizeof(no));
			t = t*2;
		}		
	}

	ptr1 = v[0];
	ptr2 = v[1];
	
	quickSortM3(v, 0, i-1);
	ptr = &ptr1;
	idx = buscaBinaria(v, 0, i-1, ptr->prx);
	for(int j = 0; j < i; j++){
		if(idx != -1){
			ptr = &v[idx];
			cam[k++] = v[idx];
			idx = buscaBinaria(v, 0, i-1, ptr->prx);
		
		if(ptr->ele == v[idx].ele)
			printf("De ptr1 -> ptr2 OK\n");
		}
	}

	for(int j = 0; j < k; j++){
		printf("cam: %lx -> ", cam[j].ele);
	}
	printf("\n");

    return 0;
}
