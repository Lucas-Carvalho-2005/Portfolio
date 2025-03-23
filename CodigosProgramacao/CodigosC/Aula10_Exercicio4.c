#include <stdio.h>
#include <stdlib.h>

int somaVetor (int x)
{
    int vet[x], i, soma = 0;

    for (i = 0; i < x; i++)
    {
        printf("Digite o elemento de posicao [%d] do vetor: ", i);
        scanf("%d", &vet[i]);
        soma = soma + vet[i];
    }

    return soma;
}


int main ()
{
    int n = 10;
    printf("\nSoma dos vetores: %d", somaVetor(n));
}
