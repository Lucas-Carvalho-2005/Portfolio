#include <stdio.h>
#include <stdlib.h>

int main()
{

    float num1;
    float num2;

    printf("Digite um numero: ");
    scanf("%f", &num1);
    printf("Digite outro numero: ");
    scanf("%f", &num2);

    if (num1 != num2){

        if (num1 > num2){
            printf("\nOs numeros na ordem crescente sao:");
            printf("\n%.2f\n", num1);
            printf("%.2f\n", num2);
        }

        else{
            printf("\nOs numeros na ordem crescente sao: ");
            printf("\n%.2f\n", num2);
            printf("%.2f\n", num1);
        }
    }

    else {
        printf("\nOs numeros sao iguais.\n");
    }

    return 0;
}
