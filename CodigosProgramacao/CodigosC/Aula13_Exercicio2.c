#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ultInd (char *nome, char caractere)
{
    int i, indice;
    for (i=0; i<strlen(nome); i++)
    {
        if (toupper(nome[i]) == caractere)
            indice = i;
    }
    return indice;
}

int main(void)
{
    char nm[30];
    char ch;
    printf("Digite uma palavra: ");
    scanf("%s", nm);
    printf("Digite um caractere: ");
    scanf(" %c", &ch);

    printf("\nPalavra: %s", nm);
    printf("\nUltimo indice do caractere '%c': %d\n", ch, ultInd(nm, ch));
}
