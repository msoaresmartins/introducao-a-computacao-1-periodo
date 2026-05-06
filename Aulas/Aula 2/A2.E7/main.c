/*7. Faça um programa que calcule o volume de um cilindro*/
#include <stdio.h>
#include <math.h>

int main() {
    float PI, h, r, V;
    
    PI = 3.14;
    
    printf("Qual o raio do cilindro?: ");
    scanf("%f", &r);
    
    printf("Qual a altura do cilindro?: ");
    scanf("%f", &h);
    
    V = (PI*r*r*h);
    
    printf("O volume do cilindro, considerando PI = 3.14, e: %f ", V);

    return 0;
}