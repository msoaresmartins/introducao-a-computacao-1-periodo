#include <stdio.h>
 
int main() {
 
    double n, r, area;
    
    scanf ("%lf", &r);
    
    n = 3.14159;
    area = n*r*r;
    
    printf("A=%.4lf\n", area);
 
    return 0;
}