/* 4. Forneça um vetor de 5 números inteiros sem nenhum número repetido e uma matriz 2x2, informe quantos números existentes no vetor também existem na matriz.
*/

#include <stdio.h>

void lerVetor (int V[5]) {
    int i = 0;

    for (i=0; i<5; i++){
        scanf("%d", &V[i]);
    }
}

void lerMatriz (int M[][2], int linhas){
    int i = 0, j = 0;

    for (i=0; i< linhas; i++){
        for (j = 0; j< 2; j++){
            scanf("%d", &M[i][j]);
        }
    }
}

int Contador (int V[5], int M[][2], int linhas) {
    int i, j, k;
    int contador = 0; 

    for (i = 0; i < 5; i++) {
        for (j = 0; j < linhas; j++) {
            for (k = 0; k < 2; k++) {
                if (V[i] == M[j][k]) {
                    contador++;
                }
            }
        }
    }
    
    return contador; 
}

int main (){
    int V[5], M[2][2], contador;

    lerVetor (V);
    lerMatriz (M, 2);

    contador = Contador(V, M, 2);
    printf("Numeros repetidos: %d\n", contador);

}