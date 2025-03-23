/* MEMBROS DA EQUIPE:
   Ana Beatriz Maciel Nunes
   Fernando Luiz Da Silva Freire
   Lucas Carvalho Dos Santos
   Marcelo Heitor de Almeida Lira
   Marcio Alves Alho Junior
   Ryan Da Silva Marinho */

#include <stdio.h>
#include <stdlib.h>

char *Metade(char *s)
{
    int i;

    for(i = 0; i < strlen(s); i++)
    {
        if(i < strlen(s)/2)
        {
            continue;
        }
        else
        {
            s[i] = '\0';
        }
    }

    return s;
}

main()
{
    char palavra[100];
    printf("Digite a palavra que deseja ter pela metade: ");
    scanf("%s", palavra);

    printf("\nPalavra: %s\n", palavra);

    printf("Metade da palavra: %s", Metade(palavra));
}
