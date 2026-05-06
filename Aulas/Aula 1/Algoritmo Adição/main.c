//Aula 1: InComp
//Exercício 1: Operação de Adição

#include<stdio.h>

int main() {
    int num1, num2, soma;
    
    //Solicitação de valores:
    printf ("Digite o primeiro valor: ");
    scanf ("%d", &num1);
    printf ("Digite o segundo valor: ");
    scanf ("%d", &num2);
    
    //Realização da soma
    soma = num1 + num2;
    printf ("O total da soma de %d + %d é: %d\n", num1, num2, soma);
    
    return 0;
}