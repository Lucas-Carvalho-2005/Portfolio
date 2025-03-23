#include <stdlib.h>
#include <stdio.h>

int SomaVetor (int vet[])
{
    int MaiorValor = vet[0];
    int MenorValor = vet[0];

    for (int i = 0; i < 7; i++)
    {
        if (vet[i] > MaiorValor)
            MaiorValor = vet[i];

        if (vet[i] < MenorValor)
            MenorValor = vet[i];
    }
    return (MaiorValor + MenorValor);
}

int main(void)
{
    int vet[7];
    for (int i = 0; i < 7; i++)
    {
        printf("Digite o valor da posicao [%d] do vetor: ", i);
        scanf("%d", &vet[i]);
    }
    printf("\n%d", SomaVetor(vet));
}
