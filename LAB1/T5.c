#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

int i = 0;

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

bool verifica_repeticao(char coresSorteadas[4])
{
    for(int i = 1; i < 4; i++)
    {
        if(coresSorteadas[i] != coresSorteadas[0])
            return false;
    }
    return true;
}

void sorteia_cores(char cores[4])
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

void resultado(int contador, char jogada[4], char coresSorteadas[4])
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

void faz_jogada(char jogada[4])
{
    printf("Digite sua jogada: ");
    scanf("%s", jogada);
}

void jogadas(char coresSorteadas[4], char jogada[4])
{
    int contador = 0, numJogadas = 0;
    printf("%s\n", coresSorteadas);
    do
    {
        faz_jogada(jogada);
        resultado(contador, jogada, coresSorteadas);
        numJogadas++;
    }while(contador != 4 && numJogadas < 10);
    resultado(contador, jogada, coresSorteadas);
}

int main()
{
    char coresSorteadas[4], jogada[4]; 
    sorteia_cores(coresSorteadas);
    jogadas(coresSorteadas, jogada);

    return 0;
}
