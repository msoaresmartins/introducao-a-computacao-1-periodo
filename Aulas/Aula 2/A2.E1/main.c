/*1. Implemente um programa que receba dois números. Imprima o 2º número primeiro e depois o 1º número, respectivamente.*/
#include <stdio.h> 

int main () {
    int n1, n2;
    
    printf("Digite um numero: ");
    scanf("%d", &n1);
    
    printf("Digite outro numero: ");
    scanf("%d", &n2);
    
    printf("O segundo numero foi: %d \n", n2);
    printf("O primeiro numero foi: %d", n1);
    
    return 0;
}