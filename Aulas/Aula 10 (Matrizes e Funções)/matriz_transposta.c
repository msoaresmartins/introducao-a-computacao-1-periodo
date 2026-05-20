/* 3. Leia uma matriz 3x3, calcule e mostre sua transposta*/

#include <stdio.h>

void LerMatriz (int M[][3], int linhas) {
    int i, j;
    for (i=0; i< linhas; i++){
        for (j=0; j<3; j++){
            scanf("%d", &M[i][j]);
        }
    }
}

void Trasposta (int T[][3],int M[][3], int linhas) {
    int i, j;
    for (i=0; i< linhas; i++){
        for (j=0; j<3; j++){
            T[i][j] = M[j][i];
        }
    } 
}

void ImprimirMatriz (int T[][3], int linhas){
    int i, j;
    for (i=0; i< linhas; i++){
        for (j=0; j<3; j++){
            printf ("%d ", T[i][j]);
        }
        printf("\n");
    }
}

int main (){
    int M[3][3], T[3][3], i, j;

    LerMatriz (M, 3);

    Trasposta(T, M, 3);

    ImprimirMatriz(T, 3);

    return 0;
}