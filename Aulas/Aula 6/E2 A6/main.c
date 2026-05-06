#include <stdio.h>

int main()
{
    double precos[6] = {40.0, 60.0, 25.0, 10.0, 10.00, 5.00};
    double total = 0;
    int opcao, taxa;
    
    do {
        printf ("Cardápio \n");
        printf ("1 - Hamburguer (R$40,00) \n");
        printf ("2 - Pizza (R$60,00) \n");
        printf ("3 - Fritas (R$25,00) \n");
        printf ("4 - Suco (R$10,00) \n");
        printf ("5 - Refrigerante (R$10,00) \n");
        printf ("6- Água (R$5,00) \n");
        printf ("0 - Finalizar pedido \n\n");
        printf ("Escolha seu pedido:");
        scanf ("%d", &opcao);
        
            if (opcao >= 1 && opcao <= 6) 
            {
            total = total + precos[opcao -1];
            printf("Item adicionado! Total ate agora: R$%.2f\n\n", total); 
            } else if (opcao != 0) {
            printf("Opcao invalida!\n\n");
            }
        
        } while (opcao != 0); 
            printf("\nTotal do pedido: R$%.2f\n\n", total);
            
                {printf ("Taxa de entrega (digite a opção): \n");
                printf("Tipo de entrega:\n");
                printf("1 - Retirada na loja (R$0,00)\n");
                printf("2 - Entrega normal (R$10,00)\n");
                printf("3 - Entrega expressa (R$20,00)\n");
                scanf("%d", &taxa); }
                
                switch (taxa) {
                case 1: taxa = 0; break;
                case 2: taxa = 10; break;
                case 3: taxa = 20; break;
                default: printf ("Valor invalido!\n");
                }
                
                total = total + taxa;
                printf("O preço da sua conta é de %.2lf\n", total);
                

    return 0;
}