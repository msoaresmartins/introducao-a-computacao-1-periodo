/*8. Ler o ano de nascimento da pessoa e o ano atual, retorne a idade da pessoa.
Se a pessoa for maior de idade imprima a mensagem "Você pode ir no Inter”*/

#include <stdio.h>

int main() {
    int nascimento, atual, idade;

    printf("Digite o seu ano de nascimento: ");
    scanf("%d", &nascimento);

    printf("Digite o ano atual: ");
    scanf("%d", &atual);

    idade = atual - nascimento;
    
    printf("Sua idade e: %d anos.\n", idade);

    if (idade >= 18) {
        printf("Voce pode ir no Inter!\n"); }

    return 0;
}