#include <stdlib.h>
#include <stdio.h>

int SomaEnesima (int numero)
{
    if (numero == 1)
        return 1;

    else
        return (numero + SomaEnesima(numero-1));
}


main ()
{
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    printf("Soma Enesima: %d", SomaEnesima(num));
}
