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
	
	int numint, i=0, j=0, menor, intervalo;
	do
	{ 
	
		printf("Informe o número de intervalos a serem considerados: ");
		scanf("%d", &numint);
		if(numint<0)
		{
			printf("Informe um número válido.\n");
		}
  
	}while(numint<0);

	int qtdprimos[numint*2-1];
    int intervalos[(numint*2)-1];
	int contador=0;

	printf("\nAgora, informe os mínimos e máximos para cada intervalo:\n\n");

	
	//pede os intervalos
	for(contador = 0; contador < numint; contador++)
	{
		printf("\nValor mínimo do intervalo %d: ", contador+1);
		scanf("%d", &intervalos[i]);
		printf("\nValor máximo do intervalo %d: ", contador+1);
		scanf("%d", &intervalos[(i+1)]);
		
		if(intervalos[i] >= intervalos[(i+1)])
		{
			printf("\nInforme um intervalo válido.\n");
			i--;
		}
		i=i+2;
	}
    
	i = 0, j=0; 
	for(j = 0; j < numint; j++)
	{
		PrimosIntervalo(intervalos[i], intervalos[i+1]);
		i = i + 2;
	}
   
    //Essa parte do programa atribui as quantidades de primos de cada intervalo aos seus respectivos valores.
	j=0;
	for(j = 0; j < numint; j++)
	{
    	qtdprimos[j] = contaprimos(intervalos[j], intervalos[j+1]);
	}
	
//Essa parte procura o intervalo com a menor quantidade de primos e armazena (qual o intervalo) na variável 'menor'
	j=0, menor = qtdprimos[j];
	for( j=0; j <= numint+1; j++)
	{
    	if(qtdprimos[j] < menor)
    	{
    		menor = qtdprimos[j];
        	intervalo = j+1;
		}    
	}

	printf("\n\nA menor quantidade de primos está no intervalo %d (de %d até %d) que "
       "tem %d primos\n",  intervalo-2, intervalos[intervalo-1], intervalos[intervalo], menor);

  
	return 0;
}


