#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Bem vindo! Aqui esta o cardapio:\n\n"
           "Especificacao:\t\t"         "Codigo:\t\t"       "Preco:\n"
           "Cachorro-quente\t\t"        "100\t\t"           "R$ 1,20\n"
           "Bauru simples\t\t"          "101\t\t"           "R$ 1,30\n"
           "Bauru com ovo\t\t"          "102\t\t"           "R$ 1,50\n"
           "Hamburguer\t\t"             "103\t\t"           "R$ 1,40\n"
           "Refrigerante\t\t"           "104\t\t"           "R$ 1,00\n");

    char lanche[50];
    int codigo_do_lanche;
    int quantidade_lanche;
    float custo_unitario;
    float custo_total;

    printf("\nDigite o codigo do seu lanche: ");
    scanf("%d", &codigo_do_lanche);

    switch (codigo_do_lanche){
        case 100:
            strcpy(lanche, "Cachorro-quente");
            custo_unitario = 1.20;
            break;

        case 101:
            strcpy(lanche, "Bauru simples");
            custo_unitario = 1.30;
            break;

        case 102:
            strcpy(lanche, "Bauru com ovo");
            custo_unitario = 1.50;
            break;

        case 103:
            strcpy(lanche, "Hamburguer");
            custo_unitario = 1.40;
            break;

        case 104:
            strcpy(lanche, "Refrigerante");
            custo_unitario = 1.50;
            break;
    }

    printf("\nQuanta unidades do %s gostaria de pedir? ", lanche);
    scanf("%d", &quantidade_lanche);

    custo_total = custo_unitario * quantidade_lanche;
    printf("O custo total do seu lanche ficou: R$%.2f\n", custo_total);

    return 0;
}
