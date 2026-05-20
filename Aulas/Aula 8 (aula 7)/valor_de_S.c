/* 9. Faça um programa que calcule e escreva o valor de 𝑆, onde 𝑆 = 1/1 + 3/2 + 5/3 + 7/4 … 99/50.*/

#include <stdio.h>
int main() {

    float i, S;

    i=0;
    S=0;

    for (i=1; i<=50; i++) {
        S = S + ((2*i -1)/i);
    }

    printf("%.2f", S);

    return 0;
}