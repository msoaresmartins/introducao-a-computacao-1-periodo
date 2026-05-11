// Faça um programa que leia 6 valores. Estes valores serão somente negativos ou positivos (desconsidere os valores nulos). A seguir, mostre a quantidade de valores positivos digitados.

#include <stdio.h>

int main () {

    double numero;
    int i, contador;

    contador = 0;

    for (i=0; i<6; i++) {
        scanf("%lf", &numero);
        if (numero >= 0) {
            contador++;
        }
    }

        printf ("%d valores positivos\n", contador);
}