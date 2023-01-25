#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define nCORES 4

#define Y 255, 210, 45
#define O 200, 100, 100
#define R 255, 50, 0  
#define G 30, 255, 20
#define B 30, 40, 255
#define P 255, 60, 120
#define V 160, 60, 255

#define W 255, 255 ,255
#define BL 0, 0 , 0

int i = 0, j = 0;



void coresjogadas(char cor)
{
    int r, g, b;
    cor_fundo(255, 50, 0);
    printf("     \n  %c  \n     \n", cor);
    cor_normal();
}


void cor_texto(int vermelho, int verde, int azul)
{
    printf("\e[38;2;%d;%d;%dm", vermelho, verde, azul);
}

void cor_fundo(int vermelho, int verde, int azul)
{
    printf("\e[48;2;%d;%d;%dm", vermelho, verde, azul);
}

void cor_normal(void)
{
    printf("\e[m");
}

void cor_fundo1(char cor)
{
    switch(cor)
    {
        case 'Y':
            cor_fundo(Y);
            break;
        case 'O':
            cor_fundo(O);
            break;
        case 'R':
            cor_fundo(R);
            break;
        case 'G':
            cor_fundo(G);
            break;
        case 'B':
            cor_fundo(B);
            break;
        case 'P':
            cor_fundo(P);
            break;
        case 'V':
            cor_fundo(V);
            break;
        default:
            cor_fundo(W);
            break;
    }
}


void cores_tutorial()
{
    int linha = 0;
    char cor[7] = {'Y', 'O', 'R', 'G', 'B', 'P', 'V'};
    
    for(linha = 0; linha < 3; linha++)
    {
        for(i = 0; i < 7; i++)
        {
            cor_fundo1(cor[i]);
            if(linha != 1)
                printf("   ");
            else 
                printf(" %c ", cor[i]);
            cor_normal();
            printf(" ");
            cor_normal();
        }
        printf("\n");
    }
    printf(" ");
}

void tutorial()
{
    cor_fundo(50 , 30 , 210);
    cor_texto(0 , 0 , 0);
    printf("BEM-VINDO AO MINDMASTER!");
    cor_normal();
    cor_fundo(W);
    printf("\n\n\tTUTORIAL:\n\nPara ganhar o jogo, você deve acertar a sequência aleatória de cores gerada pelo "
           "computador.\nVocê tem 9 tentativas, ao máximo, para vencer.\nAs cores possíveis para a sequência são as "
           "seguintes:\n\n");
    cor_normal();
    cores_tutorial();
    cor_normal();
}


bool verifica_repeticao(char coresSorteadas[nCORES])
{
    for(int i = 1; i < 4; i++)
    {
        if(coresSorteadas[i] != coresSorteadas[0])
            return false;
    }
    return true;
}

void sorteia_cores(char cores[nCORES])
{
   char coresPossiveis[7] = {'Y', 'O', 'R', 'G', 'B', 'P', 'V'}, coresSorteadas[4] = {'\0'}; ;
   int numCoresSorteadas = 0; 
   srand(time(0));
   do
   {
       numCoresSorteadas = 0;
       for (int i = 0; i < 4; i++)
       {
           char cor = coresPossiveis[rand() % 7];

           while(numCoresSorteadas > 0 && coresSorteadas[numCoresSorteadas - 1] == cor)
           {
               cor = coresPossiveis[rand() % 7];
           }
           coresSorteadas[numCoresSorteadas] = cor; 
           cores[i] = cor; 
           numCoresSorteadas++;
       }
   }while (verifica_repeticao(coresSorteadas) == true);
}

char converte_minusculas(char letra)
{
    switch(letra)
    {
        case 'y':
            return 'Y';
        case 'o':
            return 'O';
        case 'r':
            return 'R';
        case 'g':
            return 'G';
        case 'b':
            return 'B';
        case 'p':
            return 'P';
        case 'v':
            return 'V';
        default:
            return letra;
    }
}

void resultado(int contador, char jogada[nCORES], char coresSorteadas[nCORES])
{
    for(i  = 0; i < 4; i++)
    {
        jogada [i] = converte_minusculas(jogada[i]);
    }
    
    for(int i = 0; i < 4; i++)
    {
        if(jogada[i] == coresSorteadas[i])
        contador++;
    }
    if(contador < 4)
    {
        if (contador > 0)
            printf("\nVocê acertou uma sequência de %d letras\n", contador);
        else
            printf("Você não acertou nenhuma das cores na sequência :(\n");
        contador = 0;
    }
    if (contador == 4)
        printf("Parabéns, você acertou a sequência!\n");
    else
        printf("Você esgotou suas tentativas sem acertar a sequência.\n");
}    

void faz_jogada(char jogada[nCORES])
{
    printf("Digite sua jogada: ");
    scanf("%s", jogada);
}

void jogadas(char coresSorteadas[nCORES], char jogada[nCORES])
{
    int contador = 0, numJogadas = 0;
    printf("%s\n", coresSorteadas);
    faz_jogada(jogada);
    resultado(contador, jogada, coresSorteadas);
}

int main()
{
    int querJogar = 1;
    tutorial();
    char coresSorteadas[nCORES], jogada[nCORES]; 
    do
    {
        sorteia_cores(coresSorteadas);
        jogadas(coresSorteadas, jogada);
        printf("\n\nQuer continuar jogando?\n\n1 para sim, 0 para não: ");
        scanf("%d", &querJogar);
    }while(querJogar == 1);
    printf("Obrigado por jogar! :)\n")
    return 0;
}
