#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A;
    int B;
    int C;

    printf("Digite o primeiro numero: ");    // A B C         A C B         B A C       B C A            C A B            C B A
    scanf("%d", &A);
    printf("Digite o segundo numero: ");
    scanf("%d", &B);
    printf("Digite o terceiro numero: ");
    scanf("%d", &C);

    if ((A > B) && (B > C)){ // C B A
        printf("%d\n", A);
        printf("%d\n", B);
        printf("%d\n", C);}

    if ((A > C) && (C > B)){ //B A C
        printf("%d\n", A);
        printf("%d\n", C);
        printf("%d\n", B);}

    if ((B > A) && (A > C)){
        printf("%d\n", B);
        printf("%d\n", A);
        printf("%d\n", C);}

    if ((B > C) && (C > A)){
        printf("%d\n", B);
        printf("%d\n", C);
        printf("%d\n", A);}

    if ((C > A) && (A > B)){
        printf("%d\n", C);
        printf("%d\n", A);
        printf("%d\n", B);}

    if ((C > B) && (B > A)){
        printf("%d\n", C);
        printf("%d\n", B);
        printf("%d\n", A);}

    return 0;
}
