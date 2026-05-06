// 5. Faça um programa que some todos os números naturais abaixo de 100 que são múltiplos de 3 ou 5

#include <stdio.h>

int main() {
    int contador, soma;
    soma =0;

    for (contador = 1; contador < 100; contador++) {
        
        if ((contador % 3 == 0) || (contador % 5 == 0))
        {soma += contador;} 
        
    }
    
    printf(" o valor da soma e %d.", soma); 

    return 0;
}