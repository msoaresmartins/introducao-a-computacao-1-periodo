/*6. Faça um programa que calcule e imprima o volume do cone quando o usuário 
informar a altura e o raio.*/
#include <stdio.h>
#include <math.h>

int main() {
    float PI, h, r, V;
    
    PI = 3.14;
    
    printf("Qual a altura do cone?: ");
    scanf("%f", &h);
    
    printf("Qual o raio do cone?: ");
    scanf("%f", &r);
    
    V = ((PI*r*r*h))/3;
    
    printf("O volume do cone, considerando PI = 3.14, e: %f ", V);

    return 0;
}
