#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero_atual;
    int maior_numero_atual;
    int i;

    printf("Digite um numero: ");
    scanf("%d", &numero_atual);

    maior_numero_atual = numero_atual;

    for (i = 1; i <= 9; i++){
        printf("Digite um numero: ");
        scanf("%d", &numero_atual);

        if (numero_atual > maior_numero_atual)
            maior_numero_atual = numero_atual;
    }

    printf("\nO maior numero dentre os digitados: %d", maior_numero_atual);

    return 0;
}
