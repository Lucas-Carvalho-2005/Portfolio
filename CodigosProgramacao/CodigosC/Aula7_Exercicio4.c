#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int i;
    int contagem_crescente = 0;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    for (i = numero; i >= 1; i--){
        printf("\n%d\t%d", (contagem_crescente+1), numero);
        contagem_crescente++;
        numero--;
    }
}
