/* 2. Leia 2 matrizes 3x2, mostre elas na tela. Calcule e mostre a soma(elemento a elemento) entre elas.
*/

#include <stdio.h>

int somar (int a, int b) { 
    return (a + b); 
    }

int main () {
    int X[3][2], Y[3][2], i, j, soma;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &X[i][j]);
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", X[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &Y[i][j]);
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", Y[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", somar(X[i][j], Y[i][j])); 
        }
        printf("\n");
    }

    return 0;
}