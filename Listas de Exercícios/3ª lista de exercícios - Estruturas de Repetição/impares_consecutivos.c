#include <stdio.h>
 
int main() {
 
    int x, y, i, contador;
    contador=0;
    
    scanf("%d %d", &x, &y);
    
    if (x > y) {
    int temp = x;
    x = y;
    y = temp;
    }
    
    for (i = x+1; i < y; i++) {
        if (i%2!=0) {
            contador += i;
        }
    }
 printf("%d\n", contador);
    return 0;
}