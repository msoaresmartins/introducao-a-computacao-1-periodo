#include <stdio.h>
 
int main() {
   float preco;
   int codigo, quantidade;
   scanf("%d %d", &codigo, &quantidade);
   
   switch(codigo) {
       case 1: preco = 4*quantidade;
       printf("Total: R$ %.2f\n", preco); break;
       case 2: preco = 4.5*quantidade;
       printf("Total: R$ %.2f\n", preco); break;
       case 3: preco = 5*quantidade;
       printf("Total: R$ %.2f\n", preco); break;
       case 4: preco = 2*quantidade;
       printf("Total: R$ %.2f\n", preco); break;
       case 5: preco = 1.5*quantidade;
       printf("Total: R$ %.2f\n", preco); break;
   }
    return 0;
}