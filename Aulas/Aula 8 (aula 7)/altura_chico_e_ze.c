/*10. Chico tem 1.50 metro e cresce 2 centímetros por ano, enquanto Zé tem 1.10 metros
e cresce 3 centímetros por ano. Escreva um programa que calcule e imprima
quantos anos serão necessários para que Zé seja maior que Chico. */

#include <stdio.h>

int main() {
    int chico, ze, anos;

    chico = 150;
    ze = 110;
    anos = 0;

    while (ze < chico) {
        chico = chico + 2;
        ze = ze + 3;
        anos++;
    }

    printf("Para Ze ser maior que Chico, serao necessarios %d anos\n", anos);

    return 0;
}