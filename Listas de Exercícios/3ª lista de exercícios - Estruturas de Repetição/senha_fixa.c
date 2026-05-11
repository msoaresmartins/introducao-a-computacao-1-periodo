/*
  Beecrowd | 1114
  Problema: Senha Fixa
  Link: https://judge.beecrowd.com/pt/problems/view/1114
*/

#include <stdio.h>
 
int main() {
 
    int senha;
    
    scanf ("%d", &senha);
    
    while (senha != 2002) { printf ("Senha Invalida\n");
    
        scanf ("%d", &senha);
    }
    
   printf ("Acesso Permitido\n");
 
    return 0;
}