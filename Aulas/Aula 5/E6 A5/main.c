//6. Escreva um programa que leia 5 números e escreva o menor valor lido e o maior valor lido

#include <stdio.h>

int main() {
    int n, contador, valor, maior, menor;

    printf("Introduza a quantidade de numeros (n): ");
    scanf("%d", &n);

    for (contador = 1; contador <= n; contador++) {
        
        printf("Introduza o numero %d: ", contador);
        scanf("%d", &valor);
        
        if (contador == 1) {
            maior = valor;
            menor = valor;
        } else {
            if (valor > maior) {
                maior = valor; 
            }
            
            if (valor < menor) {
                menor = valor; 
            }
        }
    }

   printf("O maior inteiro da sequencia e %d\n", maior);
   printf("O menor inteiro da sequencia e %d\n", menor);

    return 0;
}