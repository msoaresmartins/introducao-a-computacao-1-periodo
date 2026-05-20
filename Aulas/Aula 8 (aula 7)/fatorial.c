/* 8. Faça um programa que leia um valor 𝑁 inteiro e positivo, calcule e mostre o valor 𝐸,
conforme a fórmula a seguir: 𝐸 = 1 + 1/1! + 1/2! + 1/3! + … + 1/𝑁!*/

#include <stdio.h>
int main() {
    int N, i;
    float E, fatorial;

    i = 0;
    E = 1.0;
    fatorial = 1.0;

scanf("%d", &N);

    for (i=1; i<=N; i++) {
        fatorial = fatorial * i;
        E = E + (1.0 / fatorial);
    }

printf ("%.2f", E);

}