#include <stdio.h>

int main(){
    float N1, N2, N3, N4, N5, media1, media2;
    scanf("%f %f %f %f", &N1, &N2, &N3, &N4);
    
    media1 = (N1*2 + N2*3 + N3*4 + N4*1)/10;
    printf("Media: %.1f\n", media1);
    
    if (media1>=7) {
        printf("Aluno aprovado.\n", media1);
    } else if (media1<5) {
        printf("Aluno reprovado.\n", media1);
    } else {
            printf("Aluno em exame.\n");
            scanf("%f", &N5);
            printf("Nota do exame: %.1f\n", N5);
            media2 = (media1 + N5)/2;
            
            if (media2>=5) { 
                printf ("Aluno aprovado.\nMedia final: %.1f\n", media2);
            } else {
                printf ("Aluno reprovado.\nMedia final: %.1f\n", media2);
                 } 
            }
    return 0;
}