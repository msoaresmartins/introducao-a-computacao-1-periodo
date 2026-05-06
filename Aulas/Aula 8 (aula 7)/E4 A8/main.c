#include <stdio.h>

int main()
{
    int i, valor, soma;
    
    i = 0;
    valor = 0;
    soma = 0;
    
    for  (i=1; i<=4; i++) {
        printf ("Digite um numero: ");
        scanf ("%d", &valor);
        
        soma = valor + soma;
    
    }
    
    printf ("O resultado foi: %d", soma);
    return 0;
}
