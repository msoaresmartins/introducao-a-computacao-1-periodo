#include <stdio.h>
 
int main() {
 
    int numero, horas;
    double valor,  salario;
    
    scanf("%d %d %lf", &numero, &horas, &valor);
    
    salario = horas*valor;
    
    printf("NUMBER = %d\n", numero);
    printf("SALARY = U$ %.2lf\n", salario);
 
    return 0;
}