#include <stdio.h>
#include <stdlib.h>

int main () {

    float numero;
    int parte_inteira;
    float parte_fracionaria;

    printf("Digite um numero real: ");
    scanf("%f", &numero);

    parte_inteira = (int)numero;
    parte_fracionaria = numero - parte_inteira;

    printf("\nParte Inteira: %d \n", parte_inteira);
    printf("Parte Fracionaria: %.2f \n", parte_fracionaria);




}
