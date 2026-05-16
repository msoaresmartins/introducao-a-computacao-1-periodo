/*
  Beecrowd | 1179
  Problema: Preenchimento de Vetor IV
  Link: https://judge.beecrowd.com/pt/problems/view/1179
*/

#include <stdio.h>

int main() {
    int par[5], impar[5], X, i, cont_par, cont_impar, j;
    i=0;
    cont_par = 0;
    cont_impar = 0;
    
    for (i = 0; i < 15; i++) {
        scanf("%d", &X); 
        
    if (X % 2 == 0) {
        par[cont_par] = X;
        cont_par++;
        if (cont_par==5) {
            for (j=0; j<5;j++) {
                printf("par[%d] = %d\n", j, par[j]);
            }
            cont_par = 0;
            }
    } else {
    impar[cont_impar] = X;
    cont_impar++;
    if (cont_impar==5) {
            for (j=0; j<5;j++) {
                printf("impar[%d] = %d\n", j, impar[j]);
            }
            cont_impar = 0;
            }
        }
    }
    for (j = 0; j < cont_impar; j++) {
        printf("impar[%d] = %d\n", j, impar[j]);
    }
    for (j = 0; j < cont_par; j++) {
        printf("par[%d] = %d\n", j, par[j]);
    }
        
return 0;
}