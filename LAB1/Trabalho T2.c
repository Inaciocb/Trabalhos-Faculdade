/*
	Aluno: Inácio Camargo Buemo 
	Turma: SI 1 
	Lab 1 2022/2;
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

void Intervalos()
{
    int i = 0, numint, tamint, min, max, menor;
    
    do
    {
        printf("Informe qual será a quantidade de intervalos: ");
        scanf("%d", &numint);
        printf("\nInforme qual será o tamanho desses intervalos: ");
        scanf("%d", &tamint);
        menor = contaprimos(i, tamint+i-1);
        if(numint<=0 || tamint <=0)
        {
            printf("\n\n Informe intervalos válidos! \n\n");
        }
    }while(numint<=0 || tamint <=0);
        for(i=1; i < (tamint * numint); i += tamint)
        {
            PrimosIntervalo(i, i+tamint-1);
            if(contaprimos(i, i+tamint-1)< menor)
            {
                menor = contaprimos(i, i+tamint-1), min = i, max = i+tamint-1;
            }
        }i=0;
   
    printf("\n\nO intervalo com menos primos é de %d até %d, ", min, max);
   
    if(menor>1)
    {
        printf("que tem %d primos.\n", menor);
    }else if(menor==0)
    {
        printf("que não tem primos.\n");
    }else
    {
        printf("que tem %d primo.\n", menor);
    }
}

int main()
{
    Intervalos();
	return 0;
}
