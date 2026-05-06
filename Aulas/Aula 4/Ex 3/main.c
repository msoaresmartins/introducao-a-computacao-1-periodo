#include <stdio.h>

int main()
{
    int data, dia;
    scanf("%d", &data);
    
    switch (data) {
        case 1: printf ("Hoje e domingo"); break;
        case 2: printf ("Hoje e segunda"); break;
        case 3: printf ("Hoje e terca"); break;
        case 4: printf ("Hoje e quarta"); break;
        case 5: printf ("Hoje e quinta"); break;
        case 6: printf ("Hoje e sexta"); break;
        case 7: printf ("Hoje e sabado"); break;
        
        default: printf ("Valor incorreto");
        
    }
    
    return 0;
}
