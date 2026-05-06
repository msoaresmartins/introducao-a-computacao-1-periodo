/*8. Faça um programa que calcule a idade do usuário quando ele informar o ano 
que ele nasceu.*/
#include <stdio.h>

int main() {
    int nascimento, idade;
    
    printf("Em qual ano voce nasceu? ");
    scanf("%d", &nascimento);

    idade = 2026 - nascimento;
    
    printf("Você tem ou fara %d anos de idade neste ano", idade);
    return 0;
}
