#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[15];
    int maior_numero;
    int menor_numero;
    int indice;

    for (indice = 0; indice < 15; indice++){
        printf("Digite um numero: ");
        scanf("%d", &vetor[indice]);
    }

    for (indice = 0; indice < 15; indice++){

        if (indice == 0){
            maior_numero = vetor[indice];
            menor_numero = vetor[indice];
        }

        else{
            if (vetor[indice] > maior_numero)
                maior_numero = vetor[indice];

            if (vetor[indice] < menor_numero)
                menor_numero = vetor[indice];
        }
    }

    printf("\nO maior numero do vetor: %d", maior_numero);
    printf("\nO menor numero do vetor: %d\n", menor_numero);

    return 0;

}
