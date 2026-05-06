#include <stdio.h>

int main()
{
   float salario_inicial, salario_atual, aumento;
   int ano;
  
   salario_inicial = 2300.;
   ano = 2015;
   
    salario_atual = 2300*1.015;
    
    ano = 2016;
   do {
       aumento = salario_atual - salario_inicial; 
       printf ("Em %d o salario foi de %.3f, com um aumento de %.2f\n", ano, salario_atual, aumento);
       salario_inicial = salario_atual;
       salario_atual = (salario_atual + aumento*2);
       ano++;
   } while (ano <= 2026);

    return 0;
}
