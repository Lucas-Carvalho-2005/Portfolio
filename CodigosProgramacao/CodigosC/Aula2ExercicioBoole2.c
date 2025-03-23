#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{ //Exercícios em Grupo:
    //Sendo A = V e B = F, qual o resultado das expressões abaixo:
    //a) (naoA e B) ou (A e nao B)
    //b)  nao(nao(A ou B)) e (A ou B)
    //c) (A ou B) e ((naoA) ou (naoB)
    //d) (A ou B) e ((naoA) ou (nao B))

    bool A = true;
    bool B = false;

    bool letraA = (!A && B) || (A && !B);
    bool letraB = !(!(A || B)) && (A || B);
    bool letraC = (A || B) && ((!A) && (!B));
    bool letraD = (A || B) && ((!A) || (!B));

    printf("O valor logico da expressao a): %d\n", letraA);
    printf("O valor logico da expressao b): %d\n", letraB);
    printf("O valor logico da expressao c): %d\n", letraC);
    printf("O valor logico da expressao d): %d\n", letraD);
}
