#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qtd_macas;
    float custo_unitario;
    float custo_total;

    printf("Digite a quantidade de macas: ");
    scanf("%d", &qtd_macas);

    if (qtd_macas < 12){
        custo_unitario = 1.30;
    }

    else{
        custo_unitario = 1.00;
        printf("\nComprou mais de uma duzia! Cada maca saindo por R$ 1,00.\n");
    }

    printf("\nQuantidade de Macas: %d\n", qtd_macas);
    printf("Custo Unitario: R$%.2f\n", custo_unitario);

    custo_total = qtd_macas * custo_unitario;
    printf("\nCusto total da compra: R$%.2f\n", custo_total);

    return 0;
}
