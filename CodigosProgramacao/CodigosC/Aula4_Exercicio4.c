#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1;
    float num2;
    char operacao;
    float resultado;

    printf("Digite um numero: ");
    scanf("%f", &num1);
    printf("Digite outro numero: ");
    scanf("%f", &num2);

    printf("Digite a operacao matematica (+, -, * ou /): ");
    scanf(" %c", &operacao);

    if (num2 == 0 && operacao == '/') {
        printf("\nDivisao por zero indeterminada.\n");
    }

    else{

        switch (operacao){

            case '+':
                resultado = num1 + num2;
                break;

            case '-':
                resultado = num1 - num2;
                break;

            case '*':
                resultado = num1 * num2;
                break;

            case '/':
                resultado = num1 / num2;
                break;

            default:
                printf("\nOperacao invalida.\n");
                return 1;
        }

    printf("\nO resultado da operacao: %.2f\n", resultado);

    }

    return 0;
}
