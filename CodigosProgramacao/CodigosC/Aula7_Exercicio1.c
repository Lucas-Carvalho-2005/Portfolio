#include <stdio.h>
#include <stdlib.h>

int main()
{
    float menor_numero_atual;
    float numero;
    int i;

    printf("Digite um numero: ");
    scanf("%f", &numero);
    menor_numero_atual = numero;

    for (i = 1; i <= 9; i++){
        printf("Digite um numero: ");
        scanf("%f", &numero);

        if (numero < menor_numero_atual)
            menor_numero_atual = numero;
    }

    printf("\nO menor numero dos listados: %f", menor_numero_atual);
}
