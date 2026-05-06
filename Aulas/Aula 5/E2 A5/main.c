#include <stdio.h>

int main() {
    int contador; // Variável apenas para contar as rodadas (1 a 5)
    int valor;    // Variável para guardar o número que o usuário digitar
    int soma = 0; // Nosso "cofrinho" que começa vazio

    // O laço vai rodar exatamente 5 vezes
    for (contador = 1; contador <= 5; contador++) {
        
        printf("Digite um numero: ");
        scanf("%d", &valor); // Captura o número digitado
        
        soma += valor;       // Adiciona o número digitado à soma total
    }

    printf("A soma dos numeros digitados é %d.\n", soma);

    return 0;
}