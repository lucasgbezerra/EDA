#include <stdio.h>

void func1 (int x) {
   *x = 9 * *x;
}

void func2 (int v[]) {
   v[0] = 9 * v[0];
}

int main () {
   int x, v[2];
   x = 111;
   func1 (&x); printf (" x: %d\n" , x);
   v[0] = 111;
   func2 (v); printf (" v[0]: %d\n" , v[0]);
   return 0;
}