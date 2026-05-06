#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, x2, y2, Distancia;
    
    scanf("%lf %lf", &x1, &y1);
    scanf("%lf %lf", &x2, &y2);
    
    Distancia = sqrt(pow(x2-x1, 2.0) + pow(y2-y1, 2.0));
    
    printf("%.4lf\n", Distancia);
    
    return 0;
}