#include <stdio.h>

int main () {

int codigo, qnt_pedidos, acumulador, i;
double valor_pedido, valor_total;

acumulador = 0;

printf("Quantos pedidos voce fara?\n");
scanf ("%d", &qnt_pedidos);

for (i = 1 ; i <= qnt_pedidos; i++) {
printf("Qual o seu codigo?\n");
scanf ("%d", &codigo);
printf ("Qual o valor do seu pedido?\n");
scanf ("%lf", &valor_pedido);

valor_total = 2.5 + valor_pedido;

printf ("Seu codigo e %d e o valor total e R$%.2lf\n", codigo, valor_total);
}

return 0;

}