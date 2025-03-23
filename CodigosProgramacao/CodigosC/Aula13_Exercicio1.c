#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int qtdAlfa (char *nome)
{
    char Alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghjiklmnopqrstuvwxyz";
    int i, j, cont = 0;
    for (i=0; i<strlen(nome); i++)
    {
        for (j=0; j<strlen(Alfabeto); j++)
        {
            if (nome[i] == Alfabeto[j])
                cont++;
        }
    }
    return cont;

}

int main(void)
{
    char nm[30];
    printf("Digite uma palavra: ");
    scanf("%s", nm);
    printf("\nPalavra: %s", nm);
    printf("\nO numero de caracteres alfabeticos: %d\n", qtdAlfa(nm));
}
