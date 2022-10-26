/*
Faça um programa que pede ao usuário o tamanho e o número de intervalos a considerar e imprime o 
intervalo que contém menos primos e o número de primos nesse intervalo. Deve-se usar as funções 
acima que consederar pertinentes. Esse é o T2. Por exemplo, se a entrada for 10 3, a saída deve 
dizer que é o intervalo 21-30, com 2 primos. Os primeiros 3 intervalos com 10 números têm os seguintes
 primos:
*/
/*
[X]Passo 1. pegar o n de intervalos


[X]Passo 2. criar vetor que armazene 2 numeros para cada intervalo.


[X]Passo 3. pegar os valores de min e max e
atribuir aos intervalos.

Passo 4. Imprimir qual intervalo tem menos primos.
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
    printf("\nOs primos no intervalo de %d e %d são:\n\n", min, max);

    for (i = min; i <= max; i++)
    {
        if (verifprimo(i) == true)
        {
            printf("\t %d", i);
        }
    }
    printf("\n");
}

int contaprimos(int min, int max)
{
    int i = min, contador = 0;
    
    for (i = min; i <= max; i++)
    {
        if (verifprimo(i) == true)
        {
            contador++;
        }
    }
    return contador;
}



int main()
{
    
    int numint, i=0, j=0;
    do
    { 
    
        printf("Informe o número de intervalos a serem considerados: ");
        scanf("%d", &numint);
    
        if(numint<0)
        {
            printf("Informe um número válido.\n");
        }
  
    }while(numint<0);

    int v[(numint*2)-1];
    int contador=0;

    printf("\nAgora, informe os mínimos e máximos para cada intervalo:\n\n");

    
    //pede os intervalos
    for(contador==0; contador < numint; contador++)
        {
            printf("\nValor mínimo do intervalo %d: ", contador+1);
            scanf("%d", &v[i]);
            printf("\nValor máximo do intervalo %d: ", contador+1);
            scanf("%d", &v[(i+1)]);
        
            if(v[i] >= v[(i+1)])
            {
                printf("\nInforme um intervalo válido.\n");
                i--;
            }
            
            i=i+2;
        }
    
    int qtdprimos[numint], menorqtd; //numero do intervalo 1;
    
    i=0, j=0;
    for(j=0; j<=numint; j++)
    {
        qtdprimos[j] = contaprimos(v[i], v[i+1]);
        if(qtdprimos[j+1] < qtdprimos[j] )
        {
            menorqtd = j+1;
        }else
        {
            menorqtd = j;
        }
    i+=2;
    }

    
    //informa qual tem menos primos
    for(j == 0; j < numint; j++)
    {
            i=
            printf("\nO intervalo com menor quantidade de primos é o intervalo de %d até %d,"
                   "ele possui %d primos", v[i], v[i+1], contaprimos(v[menorqtd-1], v[menorqtd]));
    }
   
   
    //Pega os intervalos e informa quantos primos há em cada.
    i = 0, j=0; 
    for(j == 0; j < numint; j++)
    {
        PrimosIntervalo(v[i], v[i+1]);
        i = i + 2;
    }
    j=0, i=0;
  
    return 0;
}

/*
intervalo x = i+1;
max e min desse intervalo: v[i] e v[i+1]


j=0, i=0;
for(j=0; j<=numint; j++)
{
    contaprimos(v[i], v[i+1]) = qtdprimos[j];
  
}

*/

