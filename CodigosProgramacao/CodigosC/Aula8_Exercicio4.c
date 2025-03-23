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
        printf("Digite o elemento de posicao [%d] do primeiro vetor: ", indiceA);
        scanf("%d", &vetorA[indiceA]);
    }

    printf("\n");
    for (indiceB = 0; indiceB < 7; indiceB++){
        printf("Digite o elemento de posicao [%d] segundo vetor: ", indiceB);
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

    printf("\nO vetor resultante da intercalacao do vetorA com o vetor B:\n");
    printf("[");
    for (indiceC = 0; indiceC < 14; indiceC++){

        if (indiceC < 13)
            printf("%d, ", vetorC[indiceC]);
        else
            printf("%d", vetorC[indiceC]);
    }
    printf("]\n");

    return 0;
}
