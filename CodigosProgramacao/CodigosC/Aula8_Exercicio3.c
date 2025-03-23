#include <stdio.h>
#include <stdlib.h>

int main()
{

    int matriz[5][4];
    int i;
    int j;
    int quantidade_de_numeros_negativos = 0;
    int quantidade_de_numeros_positivos = 0;
    int soma_dos_numeros_positivos = 0;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {

            printf("Digite um numero: ");
            scanf("%d", &matriz[i][j]);
        }
    }


    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {

            if (matriz[i][j] < 0)
                quantidade_de_numeros_negativos++;

            if (matriz[i][j] > 0) {
                quantidade_de_numeros_positivos++;
                soma_dos_numeros_positivos += matriz[i][j];
            }
        }
    }

    printf("\nQuantidade de numeros negativos: %d", quantidade_de_numeros_negativos);
    printf("\nQuantidade de numeros positivos: %d", quantidade_de_numeros_positivos);
    printf("\nSoma dos numeros positivos: %d\n", soma_dos_numeros_positivos);

    return 0;
}
