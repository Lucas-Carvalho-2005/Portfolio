#include <stdio.h>
#include <stdlib.h>

int main(){

    int segundos;
    int minutos;
    int horas;
    int segundos_quebrados;
    int minutos_quebrados;


    printf("Digite o numero de segundos: ");
    scanf("%d", &segundos);

    minutos = segundos / 60;
    horas = minutos / 60;
    minutos_quebrados = minutos % 60;
    segundos_quebrados = segundos % 60;

    printf("Esse tempo representa: %d hora(s) %d minuto(s) e %d segundo(s)", horas, minutos_quebrados, segundos_quebrados);


}
