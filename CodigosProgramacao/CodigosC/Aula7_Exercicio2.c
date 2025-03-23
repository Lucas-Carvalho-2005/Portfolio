#include <stdio.h>
#include <stdlib.h>

int main()
{
    float soma = 0;
    float menor_numero_atual;
    float maior_numero_atual;
    float numero_analisado;
    int i;

    printf("Digite um numero: ");
    scanf("%f", &menor_numero_atual);

    maior_numero_atual = menor_numero_atual;
    soma = soma + menor_numero_atual;

    for (i = 1; i <= 5; i++){
        printf("Digite um numero: ");
        scanf("%f", &numero_analisado);
        soma = soma + numero_analisado;

        if (numero_analisado < menor_numero_atual)
            menor_numero_atual = numero_analisado;

        if (numero_analisado > maior_numero_atual)
            maior_numero_atual = numero_analisado;
    }

    printf("\nA soma dos 6 numeros: %f", soma);
    printf("\nO menor numero: %f", menor_numero_atual);
    printf("\nO maior numero: %f", maior_numero_atual);
}
