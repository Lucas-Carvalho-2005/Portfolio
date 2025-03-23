/*3. Faça uma função que recebe a média final de um aluno por parâmetro e
retorna o seu conceito, conforme a tabela abaixo:

Nota | Conceito
De 9,0 a 10,0 | A
De 7,0 a 8,9  | B
De 5,0 a 6,9  | C
De 0,0 a 4,9  | D
*/


#include <stdio.h>
#include <stdlib.h>

char retornaConceito (float mediaFinal)
{

    if ( (mediaFinal >= 9.0) && (mediaFinal <= 10) )
        return 'A';

    if ( (mediaFinal >= 7.0) && (mediaFinal <= 8.9) )
        return 'B';

    if ( (mediaFinal >= 5.0) && (mediaFinal <= 6.9) )
        return 'C';

    if ( (mediaFinal >= 0.0) && (mediaFinal <= 4.0) )
        return 'D';

    else
        return 'X';
}

int main ()
{
    float mediaFinal;

    printf("Digite a media final do aluno: ");
    scanf("%f", &mediaFinal);
    printf("O conceito do aluno: %c", retornaConceito(mediaFinal));
}
