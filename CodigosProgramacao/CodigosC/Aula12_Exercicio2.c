#include <stdlib.h>
#include <stdio.h>

char *SinalValor (int num)
{
    if (num > 0)
        return "Positivo";

    else if (num < 0)
        return "Negativo";

    else
        return "Zero";
}

int main(void)
{
    int valor;
    printf("Digite um valor: ");
    scanf("%d", &valor);
    printf("%d: %s", valor, SinalValor(valor));
}
