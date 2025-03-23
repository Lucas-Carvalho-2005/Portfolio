/*Aula 10 - 2. Criar uma função para receber três valores reais passados por
parâmetro, multiplicar e mostrar o resultado.
*/


#include <stdio.h>
#include <stdlib.h>

float multiplicacao (float x, float y, float z)
{
    return x*y*z;
}

int main ()
{
    float num1, num2, num3;

    printf("Digite o valor 1: ");
    scanf("%f", &num1);

    printf("Digite o valor 2: ");
    scanf("%f", &num2);

    printf("Digite o valor 3: ");
    scanf("%f", &num3);

    printf("\nMultiplicacao = %.2f", multiplicacao(num1, num2, num3));
}

