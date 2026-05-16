/*
  Beecrowd | 1175
  Problema: Troca em Vetor I
  Link: https://judge.beecrowd.com/pt/problems/view/1175
*/

#include <stdio.h>
 
int main() {
 
    int N[20], i, substituicao;
    
    for (i=0; i<20; i++) {
        scanf("%d", &N[i]);
    }
    
    for (i=0; i<10; i++) {
        substituicao = N[i];
        N[i] = N[19 - i];
        N[19 - i] = substituicao;
        
    }
    
    for (i=0; i<20;i++) {
        printf("N[%d] = %d\n", i, N[i]);
    }
 
    return 0;
}