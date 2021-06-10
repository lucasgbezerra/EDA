#ifndef MACROS_H
#define MACROS_H

// se for struct
//#define Key(A) (A.chave)
typedef int Item;
//#define Key(A) (A) 
#define less(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
#define exch(A, B){Item t = A; A = B; B = t;}
#define cmpexch(A, B){if(less(B, A)) exch(A, B)}

#endif
