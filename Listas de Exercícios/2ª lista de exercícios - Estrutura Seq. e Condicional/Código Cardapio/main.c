#include <stdio.h>

int main() {
    int id, quant;
    float valor_pago;
    
    printf("CARDAPIO\n 101 - Bauru\n 102 - Hamburger\n 103 - Cheeseburger\n 104 - Refrigerante\n");
    printf("Digite o codigo do item: \n");
    scanf("%d", &id);
    printf("Digite a quantidade consumida: \n");
    scanf("%d", &quant);
    
    switch (id) {
        case 101:
            valor_pago = 6.30 * quant;
            break;
        case 102:
            valor_pago = 12.10 * quant;
            break;
        case 103:
            valor_pago = 13.30 * quant;
            break;
        case 104:
            valor_pago = 6.00 * quant;
            break;
        default:
            printf("Codigo invalido \n");
    }
    
    printf("O valor a ser pago e de %.2f\n", valor_pago);
    return 0;
}