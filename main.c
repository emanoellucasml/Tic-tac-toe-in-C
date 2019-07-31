#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"
#ifdef __unix__
    #include <unistd.h>
    #include <stdlib.h>

#elif defined(_WIN32) || defined(WIN32)

   #define OS_Windows

   #include <windows.h>
#endif
int main()
{
    char matriz[3][3], jogador1[30], jogador2[30];
    preenche(matriz);
    int posicao;
    printf("Nome do jogador 1: ");
    scanf("%s", &jogador1);
    setbuf(stdin, NULL);
    printf("Nome do jogador 2: ");
    scanf("%s", &jogador2);
    setbuf(stdin, NULL);
    loading();
    do{
        limpaTela();
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
            limpaTela();
            exibe(matriz);
            break;
        }
        limpaTela();
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
