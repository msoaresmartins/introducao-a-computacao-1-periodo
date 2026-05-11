/*
  Beecrowd | 1113
  Problema: Crescente e Decrescente
  Link: https://judge.beecrowd.com/pt/problems/view/1113
*/
#include <stdio.h>
 
int main() {
 
    int X, Y;
    
    scanf ("%d %d", &X, &Y);
    
    while (X != Y) {
        if (X<Y) {
            printf ("Crescente\n");
        } else {
            printf ("Decrescente\n");
        }
    
        scanf ("%d %d", &X, &Y);
    }
 
    return 0;
}