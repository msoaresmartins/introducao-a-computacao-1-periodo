/* 6. Faça uma função que recebe a idade de uma pessoa em anos, meses e dias e retorna essa idade expressa em dias (desconsidere anos bissextos). */

#include <stdio.h> 

int TransformarIdade (int anos, int meses, int dias){
    int dias_totais;

    dias_totais = (anos * 365) + (meses * 30) + dias;

    return dias_totais;
}

int main (){
    int a, m, d;

    scanf ("%d %d %d", &a, &m, &d);

    printf("Voce viveu %d dias ao todo\n", TransformarIdade (a, m, d));

    return 0;
}