#include <stdio.h>

int main()
{
    int data, dia;
    scanf("%d", &data);
    
    switch (data) {
        case 1: printf ("Estamos em janeiro"); break;
        case 2: printf ("Estamos em fevereiro"); break;
        case 3: printf ("Estamos em marco"); break;
        case 4: printf ("Estamos em abril"); break;
        case 5: printf ("Estamos em maio"); break;
        case 6: printf ("Estamos em junho"); break;
        case 7: printf ("Estamos em julho"); break;
        case 8: printf ("Estamos em agosto"); break;
        case 9: printf ("Estamos em setembro"); break;
        case 10: printf ("Estamos em outubro"); break;
        case 11: printf ("Estamos em novembro"); break;
        case 12: printf ("Estamos em dezembro"); break;
        
        default: printf ("Valor incorreto");
        
    }
    
    return 0;
}
