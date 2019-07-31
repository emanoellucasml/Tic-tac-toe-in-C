#include "jogo.h"
#include <time.h>

int linha1(char matriz[][3])
{
    if(matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2])
        return 1;
    return 0;
}

int linha2(char matriz[][3])
{
    if(matriz[1][0] == matriz[1][1] && matriz[1][0] == matriz[1][2])
        return 1;
    return 0;
}

int linha3(char matriz[][3])
{
    if(matriz[2][0] == matriz[2][1] && matriz[2][0] == matriz[0][2])
        return 1;
    return 0;
}

int coluna1(char matriz[][3])
{
    if(matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2])
        return 1;
    return 0;
}

int coluna2(char matriz[][3])
{
    if(matriz[1][0] == matriz[0][1] && matriz[1][0] == matriz[0][2])
        return 1;
    return 0;
}

int coluna3(char matriz[][3])
{
    if(matriz[2][0] == matriz[2][1] && matriz[2][0] == matriz[2][2])
        return 1;
    return 0;
}

int diagonalPrimaria(char matriz[][3])
{
    if(matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2])
        return 1;
    return 0;
}

int diagonalSecundaria(char matriz[][3])
{
    if(matriz[0][2] == matriz[1][1] && matriz[0][2] == matriz[2][0])
        return 1;
    return 0;
}

int verificaEmpate(char matriz[][3])
{
    int i, j, k = 0;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(matriz[i][j] == 'X' || matriz[i][j] == 'O')
                k++;
        }
    }
    if(k == 9){
        return 1;
    }else{
        return 0;
    }
}

int verificaFim(char matriz[][3])
{
    if(linha1(matriz) || linha2(matriz) || linha3(matriz) || coluna1(matriz) || coluna2(matriz) || coluna3(matriz) || diagonalPrimaria(matriz) || diagonalSecundaria(matriz))
        return 1;
}

void preenche(char matriz[][3])
{
    int i, j, k = 1;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            matriz[i][j] = intToChar(k++);
        }
    }
}

void exibe(char matriz[][3])
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
    return caractere;
}

void loading()
{
    system("clear");
    printf ("Loading.\n");
    pausar (1);
    system("clear");
    printf ("Loading..\n");
    pausar (1);
    system("clear");
    printf("Loading...\n");
    pausar (1);
    system("clear");
    printf ("Loading....\n");
    pausar (1);
    system("clear");
    printf ("Loading.....\n");
    pausar (1);
    system("clear");
}

void pausar(float delay1)
{
   if(delay1 < 0.001)
    return; // pode ser ajustado e/ou evita-se valores negativos.
   float inst1 = 0, inst2 = 0;
   inst1 = (float)clock() / (float)CLOCKS_PER_SEC;
   while (inst2 - inst1 < delay1) inst2 = (float)clock() / (float)CLOCKS_PER_SEC;
   return;
}

int verificaPosicao(char matriz[][3], int posicao)
{
    //retorna -1 caso o usuário digite uma posicao inválida ou 0 caso a posição esteja ocupada. Retorna 1 caso seja uma posição válida e livre.
    switch(posicao){
        case 1:
            if(matriz[0][0] == 'X' || matriz[0][0] == 'O')
                return 0;
            else
                return 1;
        break;
        case 2:
            if(matriz[0][1] == 'X' || matriz[0][1] == 'O')
                return 0;
            else
                return 1;
        break;
        case 3:
            if(matriz[0][2] == 'X' || matriz[0][2] == 'O')
                return 0;
            else
                return 1;
        break;
        case 4:
            if(matriz[1][0] == 'X' || matriz[1][0] == 'O')
                return 0;
            else
                return 1;
        break;
        case 5:
            if(matriz[1][1] == 'X' || matriz[1][1] == 'O')
                return 0;
            else
                return 1;
        break;
        case 6:
            if(matriz[1][2] == 'X' || matriz[1][2] == 'O')
                return 0;
            else
                return 1;
        break;
        case 7:
            if(matriz[2][0] == 'X' || matriz[2][0] == 'O')
                return 0;
            else
                return 1;
        break;
        case 8:
            if(matriz[2][1] == 'X' || matriz[2][1] == 'O')
                return 0;
            else
                return 1;
        break;
        case 9:
            if(matriz[2][2] == 'X' || matriz[2][2] == 'O')
                return 0;
            else
                return 1;
        break;
        default:
            return -1;
    }
}

void realizaJogada(char matriz[3][3], int posicao, char caractere)
{
     switch(posicao){
        case 1:
            matriz[0][0] = caractere;
        break;
        case 2:
            matriz[0][1] = caractere;
        break;
        case 3:
            matriz[0][2] = caractere;
        break;
        case 4:
            matriz[1][0] = caractere;
        break;
        case 5:
            matriz[1][1] = caractere;
        break;
        case 6:
            matriz[1][2] = caractere;
        break;
        case 7:
            matriz[2][0] = caractere;
        break;
        case 8:
            matriz[2][1] = caractere;
        break;
        case 9:
            matriz[2][2] = caractere;
        break;
    }
}

void loading2()
{
    system("clear");
    printf("1%..");
    pausar(1);
    system("clear");
    printf("30%...");
    pausar(1);
    printf("60%...");
    pausar(1);
    system("clear");
    printf("90%...");
    pausar(1);
    printf("100%...");
    pausargi(1);
    system("clear");
}




