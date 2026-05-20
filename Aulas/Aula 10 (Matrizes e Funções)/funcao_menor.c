/* 5. Escreva uma função que receba dois números reais e retorne o menor número.*/

#include <stdio.h>

float Menor (float a, float b){
     if (a < b){
        return a;
     } else { return b;}
}

int main (){
    float x, y, resultado;

    scanf("%f %f", &x, &y);

    resultado = Menor (x, y);

    printf("%f", resultado);

    return 0;

}