#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contador;
    int numero_de_leituras;
    int numero_atual;
    int menor_numero_atual;


    printf("Digite quantos numeros gostaria de digitar: ");
    scanf("%d", &numero_de_leituras);

    printf("\nDigite um numero: ");
    scanf("%d", &numero_atual);

    menor_numero_atual = numero_atual;

    for (contador = 1; contador <= (numero_de_leituras-1); contador++){
        printf("Digite um numero: ");
        scanf("%d", &numero_atual);

        if (numero_atual < menor_numero_atual)
            menor_numero_atual = numero_atual;
    }

    printf("\nO menor numero dentre os digitados: %d", menor_numero_atual);

    return 0;
}
