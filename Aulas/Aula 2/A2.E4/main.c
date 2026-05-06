/* 4. Implemente um programa que calcule o salário de um funcionário baseado no 
valor/hora, quantidade de horas trabalhadas, imposto de funcionário. 
Considere: salário = (valor*horas) – imposto */
#include <stdio.h>

int main() {
    float n1, n2, n3, salario;
    
    printf("Qual o seu valor/hora?: ");
    scanf("%f", &n1);
    
    printf("Quantas horas você trabalha?: ");
    scanf("%f", &n2);
    
    printf("Quanto você paga de imposto?: ");
    scanf("%f", &n3);
    
    salario = (n1*n2) - n3;
    
    printf("Seu salario e: %f ", salario);
    
    return 0;
}
