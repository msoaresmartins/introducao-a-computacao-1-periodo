/* 8. Escreva uma função que receba 3 notas de um aluno e uma letra. Se a letra for A, a função retorna a média aritmética das notas do aluno e se for P, a sua média ponderada (pesos: 5, 3 e 2) */

#include <stdio.h>

float Media (float x, float y, float z, char L) {
    float aritmetica, ponderada;

    aritmetica = (x + y + z)/3;
    ponderada = (5*x + 3*y + 2*z)/10;

    if (L == 'A'){
        return aritmetica;
    } else if (L == 'P') {
        return ponderada;
    }

    return 0;
}

int main (){
    float x, y, z;
    char L;

   scanf ("%f %f %f %c", &x, &y, &z, &L);

    printf ("%.2f\n", Media (x, y, z, L));


    return 0;
}