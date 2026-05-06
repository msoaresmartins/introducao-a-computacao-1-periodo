//4. Dados um número inteiro 𝑛>0, e uma sequência com 𝑛 números inteiros, determinar o maior inteiro da sequência. Por exemplo, para a sequência 6, −2, 7, 0, 8, 4 o seu programa deve escrever o número 8

#include <stdio.h>

int main() {
    int n, contador, valor, maior;

    printf("Introduza a quantidade de numeros (n): ");
    scanf("%d", &n);

    // O ciclo vai repetir 'n' vezes
    for (contador = 1; contador <= n; contador++) {
        
        printf("Introduza o numero %d: ", contador);
        scanf("%d", &valor);
        
        // Se for o 1º número a ser lido, ele é automaticamente o "maior" até ao momento
        if (contador == 1) {
            maior = valor;
        } 
        // Para o 2º, 3º, 4º número, etc., verificamos se o novo valor bate o recorde
        else if (valor > maior) {
            maior = valor; // Atualizamos a variável com o novo número campeão
        }
    }

    // Depois de analisar todos os 'n' números, imprimimos o resultado 
    printf("O maior inteiro da sequencia e %d\n", maior);

    return 0;
}