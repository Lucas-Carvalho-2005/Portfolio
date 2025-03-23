#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int strcount (char *nome, char ch)
{
    int i, conta = 0;
    for (i = 0; nome[i] != '\0'; i++)
    {
        if (nome[i] == ch)
            conta++;
    }
    return conta;
}

int main(void)
{
    char vetAlfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char nm[30];

    printf("Digite um nome: ");
    scanf("%s", nm);

    for (int l = 0; l < strlen(vetAlfabeto); l++)
        printf("Quantidade de '[%c]' = %d \n", vetAlfabeto[l],  strcount(nm, vetAlfabeto[l]));

}
