#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

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
   char coresPossiveis[7] = {'Y', 'O', 'R', 'G', 'B', 'P', 'V'};
   char coresSorteadas[4] = {'\0'}; 
   int numCoresSorteadas = 0; 

   srand(time(0));
   do
   {
       numCoresSorteadas = 0;
       for (int i = 0; i < 4; i++)
       {
           char cor = coresPossiveis[rand() % 7];

           while (numCoresSorteadas > 0 && coresSorteadas[numCoresSorteadas - 1] == cor)
           {
               cor = coresPossiveis[rand() % 7];
           }
           coresSorteadas[numCoresSorteadas] = cor; 
           cores[i] = cor; 
           numCoresSorteadas++;
       }
   }while (verifica_repeticao(coresSorteadas) == true);
}

void jogadas(char coresSorteadas[4], char jogada[4])
{
    int contador = 0, numJogadas = 0;

    printf("%s\n", coresSorteadas);

    do
    {
        printf("Digite sua jogada: ");
        scanf("%s", jogada);
        for(int i = 0; i < 4; i++)
        {
            if(jogada[i] == coresSorteadas[i])
                contador++;
        }
        if(contador < 4)
        {
            printf("\nVocê acertou uma sequência de %d letras\n", contador);
            contador = 0;
        }
        numJogadas++;
    
    }while(contador != 4 && numJogadas < 10);
    
    if(contador == 4)
        printf("Parabéns, você acertou a sequência!\n");
    else
        printf("Você esgotou suas tentativas sem acertar a sequência.\n");
}

int main()
{
    char coresSorteadas[4], jogada[4];
    sorteia_cores(coresSorteadas);
    jogadas(coresSorteadas, jogada);

    return 0;
}
