#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int numero_atual;

    printf("Digite um numero: ");
    scanf("%d", &numero);
    numero_atual = numero;

    while (numero_atual % 10 != 0) {

        if (numero_atual % 3 !=0)
            printf("\n%d", numero_atual);

        numero_atual++;
    }

    return 0;
}
