/* 3. Dada duas sequências de 4 números, calcule e imprima a soma de cada número com o
seu índice correspondente (exemplo: 𝑥[0] + 𝑦[0]; 𝑥[1] + 𝑦[1]; etc)*/

#include <stdio.h>

int main (){
    int x[4], y[4], i, soma;

    i = 0;
    soma = 0;

    for (i = 0; i<4; i++) {
        scanf ("%d", &x[i]);
        scanf ("%d", &y[i]);

        soma = x[i] + y[i];

        printf ("x[%d] + y[%d] = %d\n", i, i, soma);
    }

    return 0;
}