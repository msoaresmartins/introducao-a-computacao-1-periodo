/* 7. Escreva uma função que calcule e retorne a distância entre dois pontos (𝑥1, 𝑦1) e (𝑥2 e 𝑦2). Todos os números e valores de retorno devem ser do tipo float. */

#include <stdio.h>
#include <math.h>

float Distancia (float x1, float y1, float x2, float y2){
    float distancia;

    distancia = sqrt ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));

    return distancia;
}

int main (){
    float x1, x2, y1, y2, distancia;

    printf("Escreva as coordenadas do primeiro ponto: ");
    scanf ("%f %f", &x1, &y1);

    printf("Escreva as coordenadas do segundo ponto: ");
    scanf ("%f %f", &x2, &y2);

    printf("A distancia entre os pontos e: %.2f", Distancia(x1, y1, x2, y2));
    

    return 0;
}