#include <stdlib.h>
#include <stdio.h>

struct pessoa
{
    int id;
    char nome[20];
    char sobrenome[20];
    char sexo[1];
    float saldoConta;
};

int main(void)
{
    FILE *arq;
    struct pessoa dados;
    arq = fopen("questao1.txt", "w");

    if (arq == NULL)
        fprintf(stderr, "\nErro na abertura do arquivo.");

    printf("Digite o numero do ID: ");
    scanf("%d", &dados.id);

    while (dados.id != 0)
    {
        printf("Digite o nome, sobrenome, sexo e saldo da conta:\n");
        scanf("%s%s%s%f", dados.nome, dados.sobrenome, dados.sexo, &dados.saldoConta);
        fwrite(&dados, sizeof(struct pessoa), 1, arq);
        printf("Digite o numero do ID: ");
        scanf("%d", &dados.id);
    }

    if (fwrite != 0)
        printf("Os dados foram salvos com sucesso!");

    else
        printf("Houve falha ao salvar os dados.");

    fclose(arq);
}




