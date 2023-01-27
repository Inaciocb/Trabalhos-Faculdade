#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define nCORES 4
#define nCORES1 7
#define nTENTATIVAS 9

#define Y 255, 210, 45
#define O 255, 165, 0
#define R 255, 50, 0  
#define G 30, 255, 20
#define B 30, 40, 255
#define P 255, 60, 120
#define V 160, 60, 255

#define W 255, 255 ,255
#define BL 0, 0 , 0

int i = 0, j = 0;

void cor_fundo(int r, int g, int b)
{
    printf("\033[48;2;%d;%d;%dm", r, g, b);
}

void cor_texto(int r, int g, int b)
{
    printf("\033[38;2;%d;%d;%dm", r, g, b);
}

void cor_normal()
{
    printf("\033[0m");
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
            {
                printf("     ");
                
            }else 
            {
                printf("  %c  ", cor[i]);
            }cor_normal();
            printf(" ");
            cor_normal();
        }
        cor_normal();
        printf("\n");
    }
    printf(" ");
    cor_normal();
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

void tutorial()
{
    cor_fundo(50 , 30 , 210);
    cor_texto(0 , 0 , 0);
    printf("BEM-VINDO AO MASTERMIND!");
    cor_normal();
    cor_fundo(W);
    printf("\n\n\tTUTORIAL:\n\nPara ganhar o jogo, você deve acertar a sequência aleatória de cores gerada pelo "
           "computador.\nSe você acertar uma cor na posição correta, você verá um quadrado preto ao lado das suas jogadas,\n"
           "se você acertar uma cor na posição errada, você verá um quadrado branco ao lado das suas jogadas."
           "\nSe você não acertar nenhuma cor, não aparecerá nada ao lado das suas jogadas.\n\n"
           "\nVocê tem 9 tentativas, ao máximo, para vencer.\nAs cores possíveis para a sequência são as "
           "seguintes:");
    cor_normal();
    printf("\n\n");
    cores_tutorial();
    cor_normal();
}

void sorteia_cores(char *coresSorteadas)
{
    srand(time(NULL));
    char cor[7] = {'Y', 'O', 'R', 'G', 'B', 'P', 'V'};
    int i, j, indiceAleatorio;
    for(i = 0; i < nCORES; i++)
    {
        do
        {
            indiceAleatorio = rand() % 7;
            for(j = 0; j < i; j++)
            {
                if(coresSorteadas[j] == cor[indiceAleatorio])
                {
                    break;
                }
            }
        } while(j != i);
        coresSorteadas[i] = cor[indiceAleatorio];
    }
}

void printa_jogadas(char *coresJogadas, int acertos, int quase)
{
    for(i = 0; i < nCORES; i++)
    {
        cor_fundo1(coresJogadas[i]);
        printf("  ");
        cor_normal();
        printf(" ");
    }
    for(i = 0; i < acertos; i++)
    {
        cor_fundo(BL);
        printf("  ");
        cor_normal();
        printf(" ");
    }
    for(i = 0; i < quase; i++)
    {
        cor_fundo(W);
        printf("  ");
        cor_normal();
        printf(" ");
    }
    printf("\n");
}

bool partida(char *coresSorteadas)
{
    char coresJogadas[nCORES];
    int tentativaAtual = 0;
    int acertos = 0, quase = 0;

    for (tentativaAtual = 0; tentativaAtual < nTENTATIVAS; tentativaAtual++)
    {
        acertos = 0, quase = 0;
        printf("\nTentativa %d/%d\n", tentativaAtual + 1, nTENTATIVAS);
        for (i = 0; i < nCORES; i++)
        {
            printf("Digite a cor %d: ", i + 1);
            scanf(" %c", &coresJogadas[i]);
            coresJogadas[i] = converte_minusculas(coresJogadas[i]);
        }
        
        for (i = 0; i < nCORES; i++)
        {
            if (coresJogadas[i] == coresSorteadas[i])
            {
                acertos++;
            }
        }

        for(i = 0; i < nCORES; i++)
        {
            for(j = 0; j < nCORES; j++)
            {
                if(coresJogadas[i] == coresSorteadas[j])
                {
                    if(i != j)
                   {
                        quase++;
                        break;
                   }
                }
            }
        }

        if (acertos == nCORES)
        {
            printf("\n\n\n");
            cor_fundo(G);
            printf("Você venceu em %d tentativas!!", tentativaAtual + 1);
            cor_normal();
            printf("\n\n");
            return true;
        }
        else
        {
            printa_jogadas(coresJogadas, acertos, quase);
        }
    }
    printf("\n\n\n");
    cor_fundo(R);
    printf("Você perdeu! (esgotou suas 9 tentativas)\nA sequência correta era:");
    cor_normal();
    printf("\n\n");
    for (i = 0; i < nCORES; i++)
    {
        cor_fundo1(coresSorteadas[i]);
        printf("  ");
        cor_normal();
    }
    printf("\n");
    return false;
}

int jogo()
{
    int tentativas = 0, rodadas = 0, pontos = 0;
    char coresSorteadas[nCORES], coresJogadas[nCORES];
    
    sorteia_cores(coresSorteadas);
    printf("\n%s\n", coresSorteadas); 
    if(partida(coresSorteadas))
    {
        pontos += 1000;
    }
    else
    {
        pontos -= 1000;
    }
    return pontos;
}

bool querJogar()
{
    char resposta;
    printf("\nDeseja jogar uma partida? (S/N): ");
    scanf(" %c", &resposta);
    switch(resposta)
    {
        case 's':
        case 'S':
            return true;
        case 'n':
        case 'N':
            return false;
        default:
            printf("Resposta inválida!\n");
            return querJogar();
    }
}



int main()
{
    int pontos = 0;
    tutorial();
    do
    {
        pontos += jogo();
        printf("\n\nPontuação: %d\n", pontos);
    }while(querJogar());
    
    printf("\n-------------------\nObrigado por jogar!\n-------------------\n");
    return 0; 
}
