/*5. Faça um procedimento que recebe 2 valores inteiros por
parâmetro e retorna-os ordenados em ordem crescente.
*/


#include <stdio.h>
#include <stdlib.h>

int ordenaValores (int x, int y)
{
    if (x > y)
        printf("\nValores ordenados: %d - %d", y, x);

    else
        printf("\nValores ordenados: %d - %d", x, y);

    return 0;
}

int main ()
{
    int valor1, valor2;

    printf("Digite o valor 1: ");
    scanf("%d", &valor1);
    printf("Digite o valor 2: ");
    scanf("%d", &valor2);

    ordenaValores(valor1, valor2);
}
