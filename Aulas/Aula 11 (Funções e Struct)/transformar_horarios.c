/* 5. Faça uma função que recebe por parâmetro o tempo de duração de uma fábrica expressa em segundos e retorna também por parâmetro esse tempo em horas, minutos e segundos.
 */

 void TransformarHorario (int segundos_total) {
    int horas, minutos, segundos;

    horas = segundos_total / 3600;
    minutos = (segundos_total % 3600) / 60;
    segundos = segundos_total % 60;

    printf("%dh : %dm : %ds\n", horas, minutos, segundos);
}

int main () {
    int segundos_total;

    scanf("%d", &segundos_total);

    TransformarHorario(segundos_total);

    return 0;
}