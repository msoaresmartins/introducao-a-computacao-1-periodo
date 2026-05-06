/*3. Escreva um programa em C que receba 2 números e calcule a soma dos números 
digitados e indique o valor do maior e do menor número digitado.*/

#include <stdio.h>

int main() {
    int num1, num2, soma;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    soma = num1 + num2;
    
    printf("A soma dos dois numeros é: %d\n", soma);

    if (num1 > num2) {
        printf("O maior numero digitado foi: %d\n", num1);
        printf("O menor numero digitado foi: %d\n", num2);
    } else {
            printf("O maior numero digitado foi: %d\n", num2);
            printf("O menor numero digitado foi: %d\n", num1);
        }

    return 0;
}