#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int i;
    int resultado;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    printf("\nImprimindo a tabuada do numero %d:", numero);
    for (i = 0; i <= 10; i++){
        resultado = numero * i;
        printf("\n%d * %d = %d", numero, i, resultado);
    }
    printf("\n");

    return 0;
}
