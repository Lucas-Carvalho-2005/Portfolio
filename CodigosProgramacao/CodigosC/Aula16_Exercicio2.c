#include <stdlib.h>
#include <stdio.h>

struct pessoa
{
    int id;
    char nome[20];
    char sobrenome[20];
    char sexo[1];
    float saldo;
};

int main(void)
{
    FILE *arq;
    struct pessoa dados;
    arq = fopen("questao1.txt", "r");

    if (arq == NULL)
        printf("Erro na abertura do arquivo.");

    while (fread(&dados, sizeof(struct pessoa), 1, arq) )
    {
        printf("ID: %d \n", dados.id);
        printf("Nome: %s \n", dados.nome);
        printf("Sobrenome: %s \n", dados.sobrenome);
        printf("Sexo: %s \n", dados.sexo);
        printf("Saldo: %.f \n\n", dados.saldo);
    }
    fclose(arq);
}
