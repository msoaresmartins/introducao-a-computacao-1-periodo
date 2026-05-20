/* 1. Crie um programa que informa qual o menor número de uma matriz 3x3 de números inteiros. Leia os valores da matriz pelo teclado.
*/

#include <stdio.h>

int main (){
    int M[3][3], i, j, menor;

    i = 0;
    j = 0;

    for (i=0; i<3; i++){
        for (j=0; j<3; j++){
            scanf("%d", &M[i][j]);
        }
    }

    menor = M[0][0];

    for (i=0; i<3; i++){
        for (j=0; j<3; j++){
            if (M[i][j] < menor) {
            menor = M[i][j];
            }
        }
    }
    printf ("%d", menor);

    return 0;
}