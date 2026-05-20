/* Faça uma função que recebe a idade de um nadador por parâmetro e retorna ,
também por parâmetro, a categoria desse nadador de acordo com a tabela: */

#include <stdio.h> 

void Categoria(int  idade) {

    if (idade>= 5 && idade<=7){
        printf("Infantil A\n");
    } else if (idade>= 8 && idade<=10){
        printf("Infantil B\n");
    } else if (idade>= 11 && idade<=13){
        printf("Juvenil A\n");
    } else if (idade>= 14 && idade<=17){
        printf("Juvenil B\n");
    } else if (idade>= 18){
        printf("Adulto\n");
    }

}

int main (){
    int idade;

    scanf("%d", &idade);

    Categoria(idade);

    return 0;
}