#include <stdio.h>

int main()
{
    int op;
    float x1, x2, resultado;
    
   printf ("Escreva a operacao desejada:\n");
   printf ("1 – Adicao\n");
   printf ("2 – Subtracao\n");
   printf ("3 - Multiplicacao\n");
   printf ("4 – Divisao\n");
   scanf ("%d", &op);
   printf ("Escreva os valores a serem calculados:\n");
   scanf ("%f %f", &x1, &x2);
   
   switch (op) 
   { case 1: resultado = x1+x2; break;
     case 2: resultado = x1-x2; break;
     case 3: resultado = x1*x2; break;
     case 4: resultado = x1/x2; break;
    
    default: printf ("Os valores digitados estao incorretos");
   }
    
    printf("O resultado e %2.f", resultado);
    return 0;
}