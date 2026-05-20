/* 6. Escreva um algoritmo que leia certa quantidade 𝑥 de números e imprima o maior
deles e quantas vezes o maior número foi lido. A quantidade 𝑥 de números a serem
lidos deve ser fornecida pelo usuário.
*/

#include <stdio.h>
int main() {
int x, maior, quantidade, i, num;

i = 0;
quantidade = 0;
num = 0;
maior = -9999;

scanf ("%d", &x);

for (i=0; i<x; i++) {
    scanf("%d", &num);

    if (num > maior) {
        maior = num;
        quantidade = 1;
    } else { 
        if (num == maior) {
            quantidade++;
        }
    }
}

printf ("%d\n", maior);
printf ("%d\n", quantidade);

return 0;
}