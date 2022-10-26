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
