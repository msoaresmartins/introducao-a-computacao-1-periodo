//Aula 1: InComp
//Exercício 1: Operação de Multiplicação

#include <stdio.h>

int main() {
    float n1, n2, result;
    
    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);
    
    printf("Digite o segundo numero: ");
    scanf("%f", &n2);
    
    result = n1 * n2;
    
    printf("Resultado de %.2f x %.2f e: %.2f\n", n1, n2, result);
    
    return 0;
}