#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

typedef struct {
    int v;
    int w;
}Edge;

Edge EDGE(int x, int y){
    Edge e;

    e.v = x;
    e.w = y;

    return e;
}

typedef struct queue *Fila;
 
typedef struct Node* celula;
struct Node { 
    Edge item; 
    celula prox; 
};
struct queue { /* aqui esta especificado o que e' */
    celula ini; /* uma fila: dois apontadores para Node */
    celula fim; 
}; 
 
celula NODEnew(Edge item, celula prox) {
    celula x = (celula) malloc(sizeof *x);
    x->item = item; x->prox = prox; 
    return x; 
} 
 
Fila QUEUEinit() { 
    Fila q = (Fila) malloc(sizeof *q); 
    q->ini = q->fim = NULL; 
    
    return q;
}
 
bool QUEUEempty(Fila f) {
    if(f->ini == NULL)
        return true;
    return false; 
}
 
void QUEUEput(Fila f, Edge item){ 
    if (f->ini == NULL){ 
        f->fim = NODEnew(item, NULL);
        f->ini = f->fim; 
        return; 
    }
    f->fim->prox = NODEnew(item, NULL); 
    f->fim = f->fim->prox;
}
 
Edge QUEUEget(Fila f){ 
    Edge item = f->ini->item;
    celula t = f->ini->prox;
    free(f->ini); 
    f->ini = t;
    return item;
}
 
void QUEUEclean(Fila f){ 
    while (f->ini != NULL) { 
        celula t = f->ini->prox;
        free(f->ini);
        f->ini = t;
    }
    free(f);
}
int main(){
    Fila fila = QUEUEinit();
    Edge e;

    printf("Empty: %d\n",QUEUEempty(fila)); // 1

    QUEUEput(fila, EDGE(0, 1));
    printf("Empty: %d\n",QUEUEempty(fila)); // 0

    QUEUEput(fila, EDGE(4, 5));

    e = QUEUEget(fila);
    printf("%d-%d\n", e.v, e.w);    // 0-1
    printf("Empty: %d\n",QUEUEempty(fila)); // 0

    e = QUEUEget(fila);
    printf("%d-%d\n", e.v, e.w);    // 4-5
    printf("Empty: %d\n",QUEUEempty(fila)); // 1

    
}