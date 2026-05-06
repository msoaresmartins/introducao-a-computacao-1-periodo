/*5. Faça um programa que calcule a média ponderada de três provas sendo peso 
de 10% para a primeira, 30% para a segunda e 60% para a terceira */
#include <stdio.h>

int main() {
    float n1, n2, n3, media;
    
    printf("Digite as notas das tres provas, apertando a tecla enter depois de cada nota: ");
    scanf("%f %f %f", &n1, &n2, &n3);
    
    media = (n1*0.1 + n2*0.3 + n3*0.6);
    
    printf("A a media ponderada resultante foi de: %f ", media);
    
    return 0;
}
