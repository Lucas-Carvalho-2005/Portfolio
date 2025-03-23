#include <stdlib.h> //ABC ACB BAC BCA CAB CBA
#include <stdio.h>

int ValorDoMeio(int num1, int num2, int num3)
{
    if ( ((num2>num1) && (num2<num3)) || ((num2>num3) && (num2<num1)) )
        return num2;

    else if ( ((num3>num1) && (num3<num2)) || ((num3>num2) && (num3<num1)) )
        return num3;

    else if ( ((num1>num2) && (num1<num3)) || ((num1>num3) && (num1<num2)) )
        return num1;

    return 1;
}

int main(void)
{
    int x, y, z;
    printf("Digite o primeiro numero: ");
    scanf("%d", &x);
    printf("Digite o segundo numero: ");
    scanf("%d", &y);
    printf("Digite o terceiro numero: ");
    scanf("%d", &z);

    printf("\nO valor medio: %d", ValorDoMeio(x, y, z));
}
