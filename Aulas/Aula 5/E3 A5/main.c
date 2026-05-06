//3. Escreva um programa para calcular a média aritmética de 𝑁 números. O valor de 𝑁 é dado pelo usuário

#include <stdio.h>

int main() {
    int contador, valor, qntd; 
    float media; 
    int soma = 0; 
    
    printf("Escreva quantos numeros você quer calcular na media: ");
    scanf("%d", &qntd);

    for (contador = 1; contador <= qntd; contador++) {
        
        printf("Digite um numero: ");
        scanf("%d", &valor); 
        
        soma += valor;       
    }
    
    media = soma / qntd;
    printf("A media dos numeros digitados é %.2f.\n", media);

    return 0;
}