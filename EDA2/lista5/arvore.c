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
//Retorna um nó indica pela chave dado
no *busca(no *raiz, int dado){
    if(raiz == NULL || raiz->dado == dado)
        return raiz;
    if(dado < raiz->dado)
        return busca(raiz->esq, dado);
    else
        return busca(raiz->dir, dado);

}
no *remover(no *r, int dado){
    no *raiz = busca(r, dado);

    if(raiz->esq == NULL && raiz->dir == NULL){
        printf(">%d\n", raiz->dado);
        free(raiz);
        raiz = NULL;
    }else if(raiz->esq == NULL){
        printf(">>%d\n", raiz->dado);
        
        no *temp = raiz;
        raiz = raiz->dir;
        free(temp);
    }else if(raiz->dir == NULL){
        printf(">>>%d\n", raiz->dado);
        
        no *temp = raiz;
        raiz = raiz->esq; //raiz->esq
        free(temp);
    }
    
}
//Remove um nó mantendo a raiz como de busca
no *removeRaiz(no *raiz){
   no *pai, *ant;//pai de ant e ant a raiz
    if (raiz->esq == NULL) {
       ant = raiz->dir;
       free (raiz);
       return ant;
    }
    pai = raiz; 
    ant = raiz->esq;
    while (ant->dir != NULL) {
        pai = ant;
        ant = ant->dir;
    }

    if (pai != raiz) {
       pai->dir = ant->esq;
       ant->esq = raiz->esq;
    }
    ant->dir = raiz->dir;
    free (raiz);
    return ant;

}
void emOrdem(no *raiz){
	if(raiz != NULL){
        emOrdem(raiz->esq);
        printf("%d ", raiz->dado);
        emOrdem(raiz->dir);
    }
}
int main(){
    int dado;
    no *raiz = criaArvore();
    no *lixo;
    char op;

    while (scanf("%d", &dado) != EOF){
        raiz = insere(raiz, dado);
    }


    emOrdem(raiz);
    printf(".\n");
    return 0;
}
