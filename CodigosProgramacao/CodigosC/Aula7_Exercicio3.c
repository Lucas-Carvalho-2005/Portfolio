#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numero;
    float contagem_dos_numeros = 0;
    float soma_dos_numeros = 0;
    float media = 0;;

    int resposta = 1;

        while (resposta == 1){
        printf("Digite um numero: ");
        scanf("%f", &numero);

       if ((int)numero % 2 == 0) {
            soma_dos_numeros = soma_dos_numeros + numero;
            contagem_dos_numeros++;
        }

        else{
            printf("O numero digitado nao e par. Digite um numero par");
        }

        printf("\nGostaria de continuar a soma?\nDigite 1 para continuar ou 0 para parar.");
        scanf("%d", &resposta);
        printf("\n");
    }

    media = soma_dos_numeros / contagem_dos_numeros;
    printf("\nA media dos numeros e: %f", media);

}
