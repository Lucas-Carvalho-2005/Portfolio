#include <stdlib.h>
#include <stdio.h>

char *First_Vogal (char *s)
{
    char *endVog = NULL;
    char *Vogais = "AEIOUaeiou";


    while ( (*s != '\0') && (endVog == NULL) )
    {
        while (*Vogais != '\0')
        {
            if (*s == *Vogais)
            {
                endVog = s;
                break;
            }

            else
                Vogais++;
        }
    s++;
    Vogais = "AEIOUaeiou";
    }
    return endVog;

}

int main(void)
{
    char nm[] = "\0";
    printf("Digite um nome: ");
    gets(nm);
    printf("\nEndereco da Primeira Vogal de '%s': %p\n", nm, First_Vogal(nm));
}
