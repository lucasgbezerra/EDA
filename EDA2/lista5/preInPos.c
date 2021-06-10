#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int dado;
   struct no *esq, *dir;
} no;

no *criaArvore(){
    return NULL;
}

no *insere(no *raiz, int dado){
    if(raiz == NULL){
        raiz = malloc(sizeof(no));
        raiz->dado = dado;
        raiz->esq = raiz->dir = NULL;
    }else if(dado < raiz->dado){
        raiz->esq = insere(raiz->esq, dado);
    }else{
        raiz->dir = insere(raiz->dir, dado);
    }

    return raiz;
}
void preOrdem(no *raiz){
	if(raiz != NULL){
        printf("%d ", raiz->dado);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}
void emOrdem(no *raiz){
	if(raiz != NULL){
        emOrdem(raiz->esq);
        printf("%d ", raiz->dado);
        emOrdem(raiz->dir);
    }
}
void posOrdem(no *raiz){
	if(raiz != NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->dado);

    }
}
int main(){
    int dado;
    no *raiz = criaArvore();

    while (scanf("%d", &dado) != EOF)
        raiz = insere(raiz, dado);

    preOrdem(raiz);
    printf(".\n");
    emOrdem(raiz);
    printf(".\n");
    posOrdem(raiz);
    printf(".\n");
    return 0;
}
