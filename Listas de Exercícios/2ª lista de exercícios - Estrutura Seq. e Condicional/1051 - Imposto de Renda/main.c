#include <stdio.h>

int main() {
    double renda, imposto;

    scanf("%lf", &renda);

    if (renda <= 2000.00) {
        printf("Isento\n");
        return 0; 
    } else if (renda <= 3000.00) {
        imposto = (renda - 2000.00)*0.08;
    } else if (renda <= 4500.00) {
        imposto = (renda - 3000.00)*0.18 + 80.00;
    } else {
        imposto = (renda - 4500.00)*0.28 + 270.00 + 80.00;
    }

    printf("R$ %.2lf\n", imposto);

    return 0;
}