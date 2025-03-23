#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *trocaLetra (char *palavra)
{
    palavra[strlen(palavra)/2] = 'X';
    return palavra;
}

int main(void)
{
    char plvr[] = "\0";
    do
    {
        printf("Digite uma palavra: ");
        scanf("%s", plvr);
    }
    while (strlen(plvr) % 2 == 0);

    printf("\nPalavra Antiga: %s", plvr);
    printf("\nPalavra Nova: %s\n", trocaLetra(plvr));
}
