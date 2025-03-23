/* MEMBROS DA EQUIPE:
   Ana Beatriz Maciel Nunes
   Fernando Luiz Da Silva Freire
   Lucas Carvalho Dos Santos
   Marcelo Heitor de Almeida Lira
   Marcio Alves Alho Junior
   Ryan Da Silva Marinho */

#include <stdio.h>
#include <stdlib.h>

char *Inverte(char *s)
{
    int i, j, aux;

    for(i = 0, j = strlen(s)-1; i < j; i++, j--)
    {
        aux = s[i];
        s[i] = s[j];
        s[j] = aux;
    }
    return s;
}

main()
{
    char palavra[100];
    printf("Digite a palavra que deseja inverter: ");
    scanf("%s", palavra);

    printf("Palavra: %s \n", palavra);

    printf("Palavra invertida: %s", Inverte(palavra));
}
