#include <stdio.h>
#include <stdlib.h>

void exibe(char matriz[3][3]);
void preenche(char matriz[3][3]);
char intToChar(int algarismo);

int main()
{
    char matriz[3][3];
    preenche(matriz);
    exibe(matriz);

    return 0;
}

void preenche(char matriz[3][3])
{
    int i, j, k = 1;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            matriz[i][j] = intToChar(k++);
        }
    }
}

void exibe(char matriz[3][3])
{
    int i, j;
    for(i = 0; i < 3; i++){
        printf("+-+-+-+-+-+\n");
        for(j = 0; j < 3; j++){
            printf("|%c| ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("+-+-+-+-+-+\n");
}

char intToChar(int algarismo)
{
    if(algarismo > 9 || algarismo < 0)
        exit(0);
    char caractere = algarismo+'0';
}


