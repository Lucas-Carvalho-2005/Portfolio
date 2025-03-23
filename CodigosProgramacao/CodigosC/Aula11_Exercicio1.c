/*1. Usando o conceito de recursividade, implemente a função Potencia que devolve o valor de X^n.
*/

#include <stdlib.h>
#include <stdio.h>

int funcaoPot (int base, int exp)
{
    if (exp == 1)
        return base;

    else
        return base*funcaoPot(base, exp-1);
}

main ()
{
    int b, e;
    printf("Digite a base: ");
    scanf("%d", &b);
    printf("Digite o expoente: ");
    scanf("%d", &e);
    printf("O valor de b^e = %d", funcaoPot(b, e));
}
