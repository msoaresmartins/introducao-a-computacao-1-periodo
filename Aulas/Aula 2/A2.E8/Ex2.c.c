/**2. Implemente um programa que receba três números e mostre a sua soma.*/
#include <stdio.h>

int main() {
    int n1, n2, n3, soma;
    
    printf("Digite tres numeros inteiros, apertando a tecla enter depois de cada numero: ");
    scanf("%d %d %d", &n1, &n2, &n3);
    
    soma = n1 + n2 + n3;
    
    printf("A soma resultante de %d, %d e %d foi de: %d ", n1, n2, n3, soma);

    return 0;
}
