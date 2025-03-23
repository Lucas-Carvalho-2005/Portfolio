#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{ //Exercícios de Revisão:
    //Sabendo que A = 7, B = 2, C = 1 e D = 4, informe se as expressões abaixo são verdadeiras ou falsas:
    //a) ( ( (A >= C) && (C <= D) ) || (D==C+B) )
    //b) ((A-B) < 6) || (A+D) == (C+B))
    //c) (D =! B) && (A <= C)

    int A = 7;
    int B = 2;
    int C = 1;
    int D = 4;


    //letra a)
    bool letraA = (  ( (A >= C) && (C <= D) )  ||  (D == C + B) );

    //letra b)
    bool letraB = ( (A - B) < 6 )  ||  ( (A + D) == (C + B) );

    //letra c)
    bool letraC = ( (D = !B) && (A <= C) ); // atribue falso para D, já que B é verdadeiro e assim nãoB é falso.

    printf("O valor logico da expressao: %d\n", letraA);
    printf("O valor logico da expressao: %d\n", letraB);
    printf("O valor logico da expressao: %d\n", letraC);

    return 0;



}
