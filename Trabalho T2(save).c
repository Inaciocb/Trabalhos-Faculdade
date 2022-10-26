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
            printf("  %d", i);
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
    
    for(j=0; j<=numint;j++)
    {    
        qtdprimos[j] = contaprimos(v[i], v[i+1]);
        i += 2;
    }
    //procura o intervalo com menos primos.
    
    menorqtd = qtdprimos[j], j=0, i=0, contador=0;
for(j=0; j<=numint; j++)
{
        if(qtdprimos[j] < qtdprimos[j+1])
        {
            menorqtd = qtdprimos[j];
            contador = j;
        }
        i+=2;
    }

    //informa qual tem menos primos
    printf("\nA menor quantidade de primos é %d e está no intervalo %d (%d até %d)", menorqtd, contador+1, v[contador], v[+1]);
   
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
criar um vinculo entre o numero do intervalo, sua correspondencia(min e max) e quantos primos ele tem.

verifprimo() -> verifica se o número é primo e retorna true ou false de acordo com a resposta
contaprimos() -> Conta a quantidade de primos em um dado intervalo cedido pelos nos parâmetros.
PrimosIntervalo() -> Imprime os primos que estão em um dado intervalo cedido nos parâmetros.

-pegar quantidade de intervalos.
int numint = (informado pelo usuario)

-Pegar o vetor de intervalos v[] que o usuário informa. em que intervalo[i] é o mínimo e intervalo[i+1] é o máximo para todo intervalo i+1.
Para isso, declara-se o vetor como 
"int v[(numero de intervalos) *2] para que haja capacidade de armazenar todos os minimos e máximos.

-verifica a quantidade de primos que há em cada intervalo.

j=0, i=0;
for(j=0; j<=numint;j++)
{    
    int qtdprimos[j] = contaprimos(intervalo[i], intervalo[i+1]);
    i += 2;
}

nesse caso, o vetor qtdprimos[i] corresponde ao intervalo i+1 (qtdprimos[0] é a quantidade de primos no 
intervalo 1.)
qtdprimos j = intervalo[i+1] e intervalo[i+2] 
qtd primos j+1 = intervalo[i+3] e intervalor [i+4];

-procura o intervalo com  menor numero de primos.

j=0, i=0 
int menor;
for(j=0; j<= numint;j++)
{
    if(qtdprimos[i+1]< qtdprimos[i])
    {
        menor = i+1 ;       
    }
}
*/
