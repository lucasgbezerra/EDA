#include <stdio.h>
#include <stdlib.h>

//Pre order
//Visitamos o nó depois visita o nó da esquerda e depois da direita
//In order
//Vidita o a(subarvore) esquerda, visita o nó, visita a subarvore direita
//Pos order
//Visita as subarvores esquerda, direita, nó


typedef char Item;

typedef struct no {
   int dado;
   struct no *esq, *dir;
} no;



//inicializa a arvore
node *criaArvore(Item item){
	node *raiz = malloc(sizeof(node));
	raiz->l = raiz->r = NULL;
	raiz->item = item;

	return raiz;
}

node *criaNo(Item item){
	//Criando novo nó
	node *novo = malloc(sizeof(node));
	novo->l = novo->r = NULL;
	novo->item = item;

	return novo;
}


//Inserir novo nó
node *inserir(node *raiz, node *novo){
	
	if(raiz == NULL)
		return novo;
	if(raiz->item > novo->item)
		raiz->l = inserir(raiz->l, novo);
	else
		raiz->r = inserir(raiz->r, novo);

	return raiz;
}
// Pre order
void preOrder(node *raiz){
  if (raiz != NULL) {
    printf ("%c ", raiz->item);
    preOrder(raiz->l);
    preOrder(raiz->r); 
  }
}
// Pos order
void posOrder(node *raiz){
	if(raiz == NULL)
		return;
	posOrder(raiz->l);
	posOrder(raiz->r);
    printf("%c ", raiz->item);
}

//In order
void inOrder(node *raiz){
	if(raiz == NULL)
		return;
	inOrder(raiz->l);
    printf("%c ", raiz->item);
	inOrder(raiz->r);
}

int main(){
	node *raiz = malloc(sizeof(node));
	Item input;
	char op, print;
	scanf(" %c", &input);
	raiz = criaArvore(input);
	while (scanf(" %c", &input) != EOF)
	{
		node *novo = criaNo(input);
		raiz = inserir(raiz, novo);
	}
	printf("\nPre Ordem\n");
	preOrder(raiz);
	printf("\nIn Ordem\n");
	inOrder(raiz);
	printf("\nPos Ordem\n");
	posOrder(raiz);
	printf("\n");
	
	/*
	printf("Digite um char para inserir como nó raiz: ");
	scanf(" %c", &input);
	raiz = criaArvore(input);
	printf("Escolha uma opção: (I)nserir, (R)emover, im(P)rimir, (S)air\n");
	scanf(" %c", &op);
	while (op != 's')
	{
		switch (op)
		{
		case 'i':
			printf("Digite um char para inserir: ");
			scanf(" %c", &input);
			node *novo = criaNo(input);
			raiz = inserir(raiz, novo);
			break;
		case 'r':
			printf("Digite um número para remover: ");
			scanf("%c", &input);
			break;
		case 'p':
			printf("Imprimir em P(o)s-Ordem, Pr(e)-Ordem (i)n-Ordem: ");
			scanf(" %c", &print);
			if(print == 'e')
				preOrder(raiz);
			break;
		default:
			break;
		}
		printf("\nEscolha uma opção: (I)nserir, (R)emover, im(P)rimir, (S)air\n");
		scanf(" %c", &op);

	}
	*/
	return 0;	
}