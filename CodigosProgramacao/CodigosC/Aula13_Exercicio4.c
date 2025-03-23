#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *trocaJ (char *nome)
{
    int i, j, k, chRpt[strlen(nome)];
    for (i=0; i<strlen(nome); i++)
    {
        for (j=0; j<strlen(nome); j++)
        {
            if ( (i != j) && (nome[i] == nome[j]) )
            {
                chRpt[i] = nome[i];
                nome[j] = 'J';
            }
        }
    }

    for (k = 0; k<strlen(nome); k++)
    {
        if (nome[k] == chRpt[k])
            nome[k] = 'J';
    }
    return nome;
}

int main(void)
{
    char nm[] = "\0";
    printf("Digite uma palavra: ");
    scanf("%s", nm);
    printf("\nPalavra Antiga: %s", nm);
    printf("\nPalavra Nova: %s\n", trocaJ(nm));
}
