#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;

    printf("Digite um numero de 0 a 6: ");
    scanf("%d", &num);

    switch (num){
        case 0:
            printf("\nNumero por extenso: Zero.\n");
            break;

        case 1:
            printf("\nNumero por extenso: Um.\n");
            break;

        case 2:
            printf("\nNumero por extenso: Dois.\n");
            break;

        case 3:
            printf("\nNumero por extenso: Três.\n");
            break;

        case 4:
            printf("\nNumero por extenso: Quatro.\n");
            break;

        case 5:
            printf("\nNumero por extenso: Cinco.\n");
            break;

        case 6:
            printf("\nNumero por extenso: Seis.\n");
            break;

        default:
            printf("\nNumero fora do intervalo ou reposta invalida.\n");
    }

    return 0;

}
