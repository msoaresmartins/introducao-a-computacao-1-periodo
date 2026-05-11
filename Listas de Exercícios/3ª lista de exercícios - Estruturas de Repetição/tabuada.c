/*
  Beecrowd | 1078
  Problema: Tabuada
  Link: https://judge.beecrowd.com/pt/problems/view/1078
*/

#include <stdio.h>
 
int main() {
 
    int N, tabuada, i;
    
    scanf ("%d", &N);
    
    for (i=1; i<=10; i++) {
        
       tabuada = i*N;
        printf("%d x %d = %d\n", i, N, tabuada);
    }
 
    return 0;
}