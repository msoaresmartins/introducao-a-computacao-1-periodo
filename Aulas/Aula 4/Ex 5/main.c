#include <stdio.h>

int main()
{
    int dia, mes, ano;

    printf("Qual e o dia?\n");
    scanf("%d", &dia);
    printf("Qual e o mes? Escreva sem o zero a esquerda. Ex: Janeiro = 1\n");
    scanf("%d", &mes);
    printf("Qual e o ano?\n");
    scanf("%d", &ano);
    
    if (dia<1 || dia>31) {printf ("O dia esta incorreto.\n");}
    
    switch (mes) {
        case 1: printf ("Estamos em %d de janeiro de %d", dia, ano); break;
        case 2: printf ("Estamos em %d de fevereiro de %d", dia, ano); break;
        case 3: printf ("Estamos em %d de marco de %d", dia, ano); break;
        case 4: printf ("Estamos em %d de abril de %d", dia, ano); break;
        case 5: printf ("Estamos em %d de maio de %d", dia, ano); break;
        case 6: printf ("Estamos em %d de junho de %d", dia, ano); break;
        case 7: printf ("Estamos em %d de julho de %d", dia, ano); break;
        case 8: printf ("Estamos em %d de agosto de %d", dia, ano); break;
        case 9: printf ("Estamos em %d de setembro de %d", dia, ano); break;
        case 10: printf ("Estamos em %d de outubro de %d", dia, ano); break;
        case 11: printf ("Estamos em %d de novembro de %d", dia, ano); break;
        case 12: printf ("Estamos em %d de dezembro de %d", dia, ano); break;
        
        default: printf ("O mes esta incorreto");
        
    }
    
    return 0;
}
