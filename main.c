#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>

void pause(float);
void exibe(char matriz[3][3]);
void preenche(char matriz[3][3]);
char intToChar(int algarismo);
void loading();
int verificaPosicao(char matriz[3][3], int);
int linha1(char matriz[3][3]);

int main()
{

    char matriz[3][3];
    char jogador1[30], jogador2[30];
    int posicao;
    preenche(matriz);
    printf("Nome do jogador 1: ");
    scanf("%s", &jogador1);
    setbuf(stdin, NULL);
    printf("Nome do jogador 2: ");
    scanf("%s", &jogador2);
    setbuf(stdin, NULL);
    loading();
    do{
        exibe(matriz);
        printf("Em que posição deseja jogar, %s?\n", jogador1);
        scanf("%d", &posicao);
    }while(linha1(matriz) != 1);
    return 0;
}

int linha1(char matriz[3][3])
{
    if(matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2])
        return 1;
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
    return caractere;
}

void loading()
{
    system("clear");
    printf ("Loading.\n");
    pause (1);
    system("clear");
    printf ("Loading..\n");
    pause (1);
    system("clear");
    printf("Loading...\n");
    pause (1);
    system("clear");
    printf ("Loading....\n");
    pause (1);
    system("clear");
    printf ("Loading.....\n");
    pause (1);
    system("clear");
}

void pause(float delay1)
{
   if(delay1 < 0.001)
    return; // pode ser ajustado e/ou evita-se valores negativos.
   float inst1 = 0, inst2 = 0;
   inst1 = (float)clock() / (float)CLOCKS_PER_SEC;
   while (inst2 - inst1 < delay1) inst2 = (float)clock() / (float)CLOCKS_PER_SEC;
   return;
}

int verificaPosicao(char matriz[3][3], int posicao)
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




