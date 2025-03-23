#include <stdio.h>
#include <stdlib.h>

int main() {

    int num1;
    int num2;

    printf("Digite um numero: ");
    scanf("%d", &num1);

    printf("Digite outro numero: ");
    scanf("%d", &num2);

    if (num2 != 0)
    {
        if (num1 % num2 == 0){
            printf("%d divide %d.\n", num2, num1);}

        else{
            printf("%d nao divide %d.\n", num2, num1);}
    }

    else{
        printf("Divisao por zero invalida.\n");}
}
