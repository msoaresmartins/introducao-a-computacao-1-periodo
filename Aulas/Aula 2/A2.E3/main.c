/*3. Desenvolva um programa que receba quatro números e mostre sua média aritmética.*/
#include <stdio.h>

int main() {
    float n1, n2, n3, n4, media;
    
    printf("Digite quatro numeros inteiros, apertando a tecla enter depois de cada numero: ");
    scanf("%f %f %f %f", &n1, &n2, &n3, &n4);
    
    media = ((n1 + n2 + n3 + n4) /4);
    
    printf("A a media entre os valores %f, %f, %f e %f foi de: %f ", n1, n2, n3, n4, media);
    
    return 0;
}
