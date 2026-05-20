/* 1. Ler 6 números, armazenando-os no vetor 𝑋[6]. Calcular a soma dos números ímpares e
mostrá-la na tela.*/

#include <stdio.h>

int main () {
    
int X[6], i, soma;

i = 0;
soma = 0;

for (i=0; i<6; i++) {
    scanf("%d", &X[i]);

    if ((X[i] % 2) != 0){
        soma = soma + X[i];
    }
}

printf ("%d", soma);
    return 0;

}