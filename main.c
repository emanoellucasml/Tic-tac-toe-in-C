#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

int main()
{
    char matriz[3][3], jogador1[30], jogador2[30];
    preenche(matriz);
    int posicao;
    printf("Jogo da Velha\n");
    printf("Nome do jogador 1 : ");
    scanf("%s", &jogador1);
    setbuf(stdin, NULL);
    printf("Nome do jogador 2: ");
    scanf("%s", &jogador2);
    setbuf(stdin, NULL);
    loading2();
    do{
        system("clear");
        exibe(matriz);
        printf("Em que posição deseja jogar o X, %s?\n", jogador1);
        scanf("%d", &posicao);
        if(verificaPosicao(matriz, posicao) != 1){
            while(verificaPosicao(matriz, posicao) != 1){
                printf("Digite uma posicao valida: ");
                scanf("%d", &posicao);
            }
        }
        realizaJogada(matriz, posicao, 'X');
        if(verificaFim(matriz) || verificaEmpate(matriz)){
            system("clear");
            exibe(matriz);
            break;
        }
        system("clear");
        exibe(matriz);
        printf("Em que posição deseja jogar O, %s?\n", jogador2);
        scanf("%d", &posicao);
        if(verificaPosicao(matriz, posicao)){
            while(verificaPosicao(matriz, posicao) != 1){
                printf("Digite uma posicao válida: ");
                scanf("%d", &posicao);
            }
        }
        realizaJogada(matriz, posicao, 'O');
    }while(!verificaFim(matriz) && !verificaEmpate(matriz));
    if(verificaEmpate(matriz))
        printf("Velha!");
    return 0;
}
