#include <stdio.h>
#include <stdlib.h>

int main()
{
    float valor_compra;
    float desconto;
    float valor_final;

    printf("Digite o valor da compra: ");
    scanf("%f", &valor_compra);

    if (valor_compra > 100)
        desconto = 0.10;

    else
        desconto = 0.04;

    valor_final = valor_compra - (valor_compra * desconto);
    printf("\nValor final da compra: R$ %.2f\n", valor_final);

    return 0;
}
