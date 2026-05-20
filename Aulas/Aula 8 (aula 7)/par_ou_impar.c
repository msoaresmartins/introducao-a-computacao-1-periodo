/* 7. Ler uma sequência de números inteiros e determinar se eles são pares ou não.
Deverá ser informado o número de dados lidos e número de valores pares. O
processo termina quando for digitado o número 1000 */

#include <stdio.h>
int main() {

    int pares, num, quantidade;
    
    pares = 0;
    quantidade = 0;

    scanf ("%d", &num);

    while (num != 1000) {
        quantidade++;
        if (num %2 == 0) {
            pares++;
        }
     scanf ("%d", &num);
    }

    printf("%d numeros lidos\n", quantidade);
    printf ("%d de valores pares\n", pares);
    return 0;
}