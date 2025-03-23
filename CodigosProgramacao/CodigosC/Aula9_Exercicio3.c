#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetorA[7];
    int vetorB[7];
    int vetorC[14];
    int indiceA;
    int indiceB;
    int indiceC;
    int contadorA = 0;
    int contadorB = 0;

    for (indiceA = 0; indiceA < 7; indiceA++){
        printf("Digite um numero para o primeiro vetor: ");
        scanf("%d", &vetorA[indiceA]);
    }

    printf("\n");
    for (indiceB = 0; indiceB < 7; indiceB++){
        printf("Digite um numero para o segundo vetor: ");
        scanf("%d", &vetorB[indiceB]);
    }

    for (indiceC = 0; indiceC < 14; indiceC++){

            if (indiceC % 2 == 0){
                vetorC[indiceC] = vetorA[contadorA];
                contadorA++;
            }

            else{
                vetorC[indiceC] = vetorB[contadorB];
                contadorB++;
            }
    }


    printf("\n");
    for (indiceA = 0; indiceA < 7; indiceA++){
        printf("%d, ", vetorA[indiceA]);
    }


    printf("\n");
    for (indiceB = 0; indiceB < 7; indiceB++){
        printf("%d, ", vetorB[indiceB]);
    }


    printf("\n");
    for (indiceC = 0; indiceC < 14; indiceC++){
        printf("%d, ", vetorC[indiceC]);
    }

    return 0;
}
