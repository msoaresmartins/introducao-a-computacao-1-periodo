/* 5. Faça uma função que recebe por parâmetro o raio de uma esfera e calcula o seu volume (v = 4/3.P .R3). */

#include <stdio.h>

double VolumeEsfera (float R){ 
    double volume;
    const double PI = 3.14159;

    volume = (4.0*PI*R*R*R)/3.0;

    return volume;
}

int main (){
    float R;

    scanf ("%f", &R);

    printf ("%.4f\n", VolumeEsfera (R));

    return 0;
}