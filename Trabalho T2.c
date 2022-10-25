/*
Faça um programa que pede ao usuário o tamanho e o número de intervalos a considerar e imprime o 
intervalo que contém menos primos e o número de primos nesse intervalo. Deve-se usar as funções 
acima que consederar pertinentes. Esse é o T2. Por exemplo, se a entrada for 10 3, a saída deve 
dizer que é o intervalo 21-30, com 2 primos. Os primeiros 3 intervalos com 10 números têm os seguintes
 primos:
*/
/*
Passo 1. pegar o n de intervalos


Passo 2. criar vetor que armazene 2 numeros para cada intervalo.


Passo 3. pegar os valores de min e max e
atribuir aos intervalos.

*/

/*
Faça um programa que pede ao usuário o tamanho e o número de intervalos a considerar e imprime o 
intervalo que contém menos primos e o número de primos nesse intervalo. Deve-se usar as funções 
acima que consederar pertinentes. Esse é o T2. Por exemplo, se a entrada for 10 3, a saída deve 
dizer que é o intervalo 21-30, com 2 primos. Os primeiros 3 intervalos com 10 números têm os seguintes
 primos:
*/
#include <stdio.h>
#include <stdbool.h>

bool verifprimo(int num)
{
    int i = 1, cont = 0;
    for (i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            cont++;
        }
    }
    if (cont == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void PrimosIntervalo(int min, int max)
{
    int i = min;
    printf("Os primos nesse intervalo são:\n");

    for (i = min; i <= max; i++)
    {
        if (verifprimo(i) == true)
        {
            printf("\t %d", i);
        }
    }
    printf("\n");
}


int main()
{
    
    int numint, v[(numint*2)], i=0;
    do
    { 
         printf("Informe o número de intervalos a serem considerados: ");
         scanf("%d", &numint);
  
    }while(numint<0);

    printf("Agora, informe os mínimos e máximos para cada intervalo:\n\n")

    for(i=0, i<=numint, i++)
    {
        printf("Valor minimo do intervalo %d: ", i+1);
        scanf("%d", &v[i]);
        printf("Valor máximo: ");
        scanf("%d", &v[i+1]);
    }

    printf("")
    
    return 0;
}
