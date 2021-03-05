#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dic{
	char jp[85];
	char pt[85];
}dic;

#define Key(A) (A)
#define less(A,B) (strcmp(A,B))
#define exch(A, B) {dic t = A; A = B; B = t;}
#define cmpexch(A, B) {if (less (B.jp, A.jp) < 0) exch (A,B);}


int separa(dic *d, int l, int r){
	dic pv = d[r];
	int j = l;

	for(int k = l; k < r; k++){
		if(strcmp(d[k].jp, pv.jp) < 0){
			exch(d[k], d[j]);
			j++;
		}
	}

	exch(d[r], d[j]);	
	return j;
}
void quickSort(dic *d, int l, int r){
	int j;
	int m = (r+l)/2;
	if(r <= l)
		return;
	cmpexch(d[m], d[r]);
	cmpexch(d[l], d[m]);
	cmpexch(d[r], d[m]);

	j = separa(d, l, r);
	quickSort(d, l, j-1);
	quickSort(d, j+1, r);
}


void buscaBinaria(char *key, dic *d, int l,  int r){
	int m, cp;
	if(l > r){
		printf("%s", key);
		return;
	}
	m = (r+l)/2;
	cp = strcmp(key, d[m].jp);

	if(cp == 0){
		printf("%s", d[m].pt);
		return;
	}	
	else if(cp < 0)
		return buscaBinaria(key, d, 0, m-1);
	else
		return buscaBinaria(key, d, m+1, r);
		
}

void tradutor(char *mus, dic *d, int m){
	int ini = 0;
	char palavra[85];

	for(int i = 0; mus[i] != '\0'; i++){
		if(mus[i] != ' '){
			palavra[ini++] = mus[i];
		}
		if(mus[i] == ' ' || mus[i+1] == '\0'){
			
			palavra[ini] = '\0';
			buscaBinaria(palavra, d, 0, m-1);
			
			ini = 0;
		}
		if(mus[i] == ' ')
			printf(" ");
	}
}
int main()
{
	int t, n, m;
	char mus[85], lixo;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		scanf("%d %d", &m, &n);
		dic *d = malloc(m * sizeof(dic));
		scanf("%c", &lixo);
		for(int j = 0; j < m; j++){
			fgets(d[j].jp, 85, stdin);
			fgets(d[j].pt, 85, stdin);
			d[j].jp[strlen(d[j].jp) - 1] = '\0';
			d[j].pt[strlen(d[j].pt) - 1] = '\0';
		}
		quickSort(d, 0, m-1);

		for(int j = 0; j < n; j++){
			
			fgets(mus, 85, stdin);
			mus[strlen(mus) - 1] = '\0';	
			
			tradutor(mus, d, m);
			printf("\n");
		}
		printf("\n");
		free(d);
	}
	return 0;	
}
