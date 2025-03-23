#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    struct funcionario
    {
        char nome[15];
        char telefone[12];
        float venda;
    };

    struct funcionario func[6];
    int i, maiorVenda, indMaior;

    for (i = 0; i < 6; i++)
    {
        printf("Informe o nome do funcionario [%d]: ", i);
        scanf("%s", func[i].nome);

        printf("Informe o telefone do funcionario [%d]: ", i);
        scanf("%s", func[i].telefone);

        printf("Informe o valor vendido pelo funcionario [%d]: ", i);
        scanf("%f", &func[i].venda);

        printf("\n");
    }

    printf("\nLista dos funcionarios:\n");
    for (i = 0; i < 6; i++)
    {
        printf("\nFuncionario [%d]:", i);
        printf("\nNome: %s", func[i].nome);
        printf("\nTelefone: %s", func[i].telefone);
        printf("\nVenda: %f\n", func[i].venda);
    }

    printf("\nLista dos funcionarios que venderam mais de R$100,00:\n");
    for (i = 0; i < 6; i++)
    {
        if (func[i].venda >= 100)
            printf("%s\n", func[i].nome);
    }

    maiorVenda = func[0].venda;
    for (i = 0; i < 6; i++)
    {
        if (func[i].venda > maiorVenda)
        {
            maiorVenda = func[i].venda;
            indMaior = i;
        }
    }

    printf("\nFuncionario que realizou a maior venda:");
    printf("\nNome: %s", func[indMaior].nome);
    printf("\nTelefone: %s\n", func[indMaior].telefone);
}
