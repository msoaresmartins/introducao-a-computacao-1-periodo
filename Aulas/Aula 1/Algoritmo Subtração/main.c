//Aula 1: InComp
//Exercício 1: Operação de Subtração

#include <stdio.h>

int main() {
    float n1, n2, result;
    
    printf("Digite o primeiro número: ");
    scanf("%f", &n1);
    
    printf("Digite o segundo número: ");
    scanf("%f", &n2);
    
    result = n1 - n2;
    
    printf("Resultado de %.2f - %.2f e: %.2f\n", n1, n2, result);
    
    return 0;
}