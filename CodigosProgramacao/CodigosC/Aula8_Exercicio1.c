#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanho_do_vetor = 10;
    int vetor[tamanho_do_vetor];
    int indice_do_elemento;
    int elemento;
    int quantidade_de_elementos_pares = 0;
    int soma_dos_elementos = 0;

    for (indice_do_elemento = 0; indice_do_elemento < tamanho_do_vetor; indice_do_elemento++){
        printf("Digite um numero: ");
        scanf("%d", &elemento);
        vetor[indice_do_elemento] = elemento;

        soma_dos_elementos += vetor[indice_do_elemento];

        if ( vetor[indice_do_elemento] % 2 == 0)
            quantidade_de_elementos_pares++;
    }

    printf("\nA quantidade de numeros pares: %d", quantidade_de_elementos_pares);
    printf("\nA soma dos elementos do vetor: %d\n", soma_dos_elementos);

    return 0;
}
