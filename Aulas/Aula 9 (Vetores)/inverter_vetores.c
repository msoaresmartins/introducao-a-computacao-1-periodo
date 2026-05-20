/* 2. Ler 5 números, armazenando-os no vetor 𝑋[5]. Copiar este vetor, de trás para frente (na
ordem inversa de leitura), em um segundo vetor 𝑌[5]. Imprima o vetor Y */

#include <stdio.h>

int main (){
    int X[5], Y[5], i;

    i = 0;

    for (i=0; i<5; i++){
        scanf("%d", &X[i]);
        Y[4 - i] = X[i];
    }

    for (i=0; i<5; i++){
        printf("%d ", Y[i]);
    }

    return 0;
}