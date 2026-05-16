/*
  Beecrowd | 1172
  Problema: Substituição em Vetor I
  Link: https://judge.beecrowd.com/pt/problems/view/1172
*/
#include <stdio.h>

int main() {
int X[10], i;

i=0;

    for(i=0; i<10; i++) {
        scanf ("%d", &X[i]);
            if (X[i]<=0) {
                X[i] = 1; }
        printf ("X[%d] = %d\n", i, X[i]); }

return 0;
}