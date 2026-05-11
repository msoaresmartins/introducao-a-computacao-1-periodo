#include <stdio.h>

int main() {
    double salario, reajuste, diferenca, porcentagem, novoSalario;
    int percentual; 

    scanf("%lf", &salario);

    if (salario >= 0 && salario <= 400.00) {
        porcentagem = 1.15;
        percentual = 15;
    } else if (salario <= 800.00) {
        porcentagem = 1.12;
        percentual = 12;
    } else if (salario <= 1200.00) {
        porcentagem = 1.10;
        percentual = 10;
    } else if (salario <= 2000.00) {
        porcentagem = 1.07;
        percentual = 7;
    } else {
        porcentagem = 1.04;
        percentual = 4;
    }

    novoSalario = salario * porcentagem;
    diferenca = novoSalario - salario;

    printf("Novo salario: %.2f\n", novoSalario);
    printf("Reajuste ganho: %.2f\n", diferenca);
    printf("Em percentual: %d %%\n", percentual);

    return 0;
}