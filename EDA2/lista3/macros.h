#ifndef MACROS_H
#define MACROS_H

#define less(A, B) ((A) < (B))
#define lesseq(A, B) ((A) <= (B))
#define exch(A, B){int t = A; A = B; B = t;}
#define cmpexch(A, B){if(less(B, A)) exch(A, B)}

#endif
