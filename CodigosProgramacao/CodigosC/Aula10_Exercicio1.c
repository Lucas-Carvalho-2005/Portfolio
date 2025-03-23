/* 1) Fa�a um programa que tenha uma fun��o para receber por par�metro o
      tamanho do vetor, em seguida realiza as seguintes opera��es:
        a) Aceitar somente n�meros �mpares e positivo.
        b) A fun��o deve retornar a soma do maior e do menor elemento do vetor.
*/


#include <stdio.h>
#include <stdlib.h>

int somaVetor(int n){
    int i, maiorNumero, menorNumero, vet[n], numero;

    for (i = 0; i < n; i++)
    {
        do
        {
            printf("Digite o elemento da posicao [%d] do vetor: ", i);
            scanf("%d", &numero);
        }
        while( (numero % 2 == 0) || (numero <= 0) );

        vet[i] = numero;
    }

    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            maiorNumero = vet[i];
            menorNumero = vet[i];
        }

        else
        {
            if (vet[i] > maiorNumero)
                maiorNumero = vet[i];

            if (vet[i] < menorNumero)
                menorNumero = vet[i];
        }
    }

    return maiorNumero + menorNumero;
}

int main ()
{
    int num;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &num);
    printf("Soma do vetor = %d", somaVetor(num));
}
