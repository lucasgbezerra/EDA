#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   char dado;
   struct no *esq, *dir;
} no;

static int idx = 0;

no *criaArvore(){
    idx = 0;
    return NULL;
}
no *criaNo(char dado, no *esq, no *dir){
  no *novo = malloc(sizeof(no));
  novo->dado = dado;
  novo->esq = esq;
  novo->dir = dir;

  return novo;
}

int buscaNo(char ele, int ini,int fim, char *em){
    for(int i = ini; i <= fim; i++)
        if(ele == em[i])
            return i;
    
}
void posOrdem(no *raiz){
	if(raiz != NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%c", raiz->dado);
    }
}

no *geraArvore(int ini, int fim, char *pre, char *em){
    no *v;

    if(ini > fim)
        return NULL;
    v = criaNo(pre[idx++], NULL, NULL);

    if(ini == fim)
        return v;
    int k = buscaNo(v->dado, ini, fim, em);

    v->esq = geraArvore(ini, k-1, pre, em);
    v->dir = geraArvore(k+1, fim, pre, em);

    return v;
}

int main(){
    int c, n;
    char pre[53]; 
    char em[53];
    no *raiz;

    scanf("%d", &c);
    while (c--)
    {
        raiz = criaArvore();
        scanf("%d %s %s", &n, pre, em);
        raiz = geraArvore(0, n-1, pre, em);
        posOrdem(raiz);
        printf("\n");        
    }
    free(raiz);

    return 0;
}
