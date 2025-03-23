#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    char operacao;
    int resultado;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    printf("Digite qual operacao aritmetica tradicional gostaria de fazer com os numeros (+, -, *, ou /): ");
    scanf(" %c", &operacao);

    switch (operacao) {
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
            printf("Operacao inserida invalida. Saindo do programa.");
            return 1;
    }
    printf("O resultado da operacao foi: %d\n", resultado);
}
