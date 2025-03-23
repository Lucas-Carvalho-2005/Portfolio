#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *Ascii_create (int tam, char inic)
{
    int i;
    char *pstr;
    pstr = (char *) malloc(tam+1);

    if (pstr == NULL)
        printf("Problema ao alocar memória.");

    else
        for (i = 0; i < tam; i++)
            pstr[i] = inic + i;

    pstr[i] = '\0';
    return pstr;
}

int main(void)
{
    char ch;
    int tm;
    printf("Digite um caractere: ");
    scanf(" %c", &ch);
    printf("Digite um numero: ");
    scanf("%d", &tm);
    printf("\nString criada dinamicamente: %s\n", Ascii_create(tm, ch));

}
