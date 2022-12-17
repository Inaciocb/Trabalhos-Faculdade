#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void sorteia_cores(int tam, char cores[tam])
{
char coresPossiveis[7] = {'Y', 'O', 'R', 'G', 'B', 'P', 'V'};
char coresSorteadas[4] = {'\0'}; // inicializa a lista de cores sorteadas com caracteres nulos
int numCoresSorteadas = 0; // inicializa o contador de cores sorteadas

// inicializa a semente do gerador de números aleatórios com o horário atual
srand(time(0));

for (int i = 0; i < tam; i++)
{
    char cor = coresPossiveis[rand() % 7];

    // enquanto a cor sorteada já estiver na lista de cores sorteadas, sorteia outra cor
    while (numCoresSorteadas > 0 && coresSorteadas[numCoresSorteadas - 1] == cor)
    {
        cor = coresPossiveis[rand() % 7];
    }

    coresSorteadas[numCoresSorteadas] = cor; // adiciona a cor sorteada à lista de cores sorteadas
    cores[i] = cor; // adiciona a cor sorteada à lista de cores geradas
    numCoresSorteadas++;
}
}

int main()
{
char coresSorteadas[4], jogada[4];
int contador;

sorteia_cores(4, coresSorteadas);

printf("%s\n", coresSorteadas);
do
{
    printf("Digite sua jogada: ");
    scanf("%s", jogada);
    contador = 0; // reinicializa o contador de acertos
    for(int i = 0; i < 4; i++)
    {
        if(jogada[i] == coresSorteadas[i])
            contador++;
    }
    printf("Voce acertou uma sequencia de %d letras\n", contador);
} while(contador != 4);

printf("Parabens, voce acertou a sequência!\n");

return 0;
}
