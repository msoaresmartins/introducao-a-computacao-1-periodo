/* 6. Faça uma função que recebe um valor inteiro e verifica se o valor é par. A função deve retornar 1 se o número for par e 0 se for ímpar.*/

#include <stdio.h>

int ParImpar (int a) {
    if (a%2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main (){
    int x;

    scanf ("%d", &x);

    printf ("%d", ParImpar(x));

    return 0;
}