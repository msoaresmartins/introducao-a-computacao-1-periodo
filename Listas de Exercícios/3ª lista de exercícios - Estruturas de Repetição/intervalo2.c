/*
  Beecrowd | 1072
  Problema: Intervalo 2
  Link: https://judge.beecrowd.com/pt/problems/view/1072
*/
#include <stdio.h>
 
int main() {
 
    int N, i, contador, dentro, fora;
    
    dentro = 0;
    fora = 0;
    contador = 0;
    
    scanf("%d", &N);
    
    for (i=0; i<N; i++) { 
        scanf("%d", &contador);
        if (contador>=10 && contador<=20) {
            dentro++;
        } else { fora++; }
        
    }
    
    printf("%d in\n", dentro);
    printf("%d out\n", fora);
    
    return 0;
}