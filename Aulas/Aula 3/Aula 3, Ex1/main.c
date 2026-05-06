/*1. Escreva um programa que leia 2 números inteiros e imprima se os valores dos números são iguais.*/

#include <stdio.h>

int main() {
    int num1, num2;

    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero inteiro: ");
    scanf("%d", &num2);

   if (num1 == num2) {
        printf("Os valores dos números são iguais.\n");} 
        
    return 0;
}