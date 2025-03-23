#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1;
    float num2;
    float soma;

    printf("Digite um numero: ");
    scanf("%f", &num1);
    printf("Digite outro numero: ");
    scanf("%f", &num2);

    soma = num1 + num2;

    if (soma > 0){
        printf("\nA soma dos numeros resulta num numero positivo.\n");
    }
    else if (soma < 0){
        printf("\nA soma dos numeros resulta num numero negativo.\n");
    }
    else{
        printf("\nA soma dos numeros resulta em 0.\n");
    }
}
