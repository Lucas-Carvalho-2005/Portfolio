#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *strrch (char *s, char ch)
{
    char *endUlt = NULL;
    while (*s != '\0')
    {
        if (*s == ch)
            endUlt = s;
        s++;
    }
    return endUlt;
}

int main(void)
{
    char nm[] = "\0";
    char chc;
    printf("Digite uma palavra: ");
    gets(nm);
    printf("Digite um caractere: ");
    scanf(" %c", &chc);

    printf("Endereço do nome: %p\n", &nm[0]);
    printf("\nEndereco da Ultima Ocorrencia de '%c': %p\n", chc, strrch(nm, chc));
}
