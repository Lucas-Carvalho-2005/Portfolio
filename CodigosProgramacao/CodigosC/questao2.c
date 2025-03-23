/* MEMBROS DA EQUIPE:
   Ana Beatriz Maciel Nunes
   Fernando Luiz Da Silva Freire
   Lucas Carvalho Dos Santos
   Marcelo Heitor de Almeida Lira
   Marcio Alves Alho Junior
   Ryan Da Silva Marinho */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *Repete(char *string, int n) {

    int comprimentoOriginal = strlen(string);
    int comprimentoTotal = (comprimentoOriginal + 1) * n;
    char *novaString = (char *)malloc(comprimentoTotal);

    if (novaString == NULL) {
        fprintf(stderr, "Erro na alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    int posicao_atual = 0;
    for (int i = 0; i < n; i++) {
        strcpy(novaString + posicao_atual, string);
        posicao_atual += comprimentoOriginal;

        if (i < n - 1) {
            novaString[posicao_atual] = ' ';
            posicao_atual++;
        }
    }

    return novaString;
}

int main() {

    char *resultado = Repete("ola", 8);
    printf("%s\n", resultado);

    free(resultado);

    return 0;
}
