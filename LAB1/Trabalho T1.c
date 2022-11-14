/*
Inácio Camargo Buemo 
Turma: SI1 2022-2
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

void frescurinha()
{
    printf("\n[--============================================--]\n");
}

int main ()
{
  setlocale(LC_ALL, "portuguese");
  
  int chute, entrada, entrada1, i=0, max=0, min=0;
  
  srand (time (0));
  
  printf("O jogo terá qual valor máximo?\nDigite: ");
  scanf("%d", &max);
 
  
  printf("\tInstruções:\nPense em um valor entre 0 e %d.\n\nEscreva ' 0 ' caso o chute do programa esteja certo.\n" 
           "Escreva ' 1 ' caso o chute esteja abaixo do valor pensado. \nEscreva ' 2 ' caso o chute esteja acima.\n\t\n"
           "Para começar, qualquer número: ", max);
  scanf("%d", &entrada1);
    
    do
    {
        i++;
        chute = (rand () % (max+1-min))+min;
        printf("\nChute do programa: %d\n", chute);
        printf("\nEstá certo?\n0 = Sim\n1 = Está abaixo.\n2 = Está acima.\n Digite: ");
        scanf("%d", &entrada);
        
        switch(entrada)
        {
            case 1:
                min = chute+1;
                break;
            case 2:
                max = chute - 1;
                break;
            case 0:
                frescurinha();
                printf("  O programa acertou seu número em %d tentativas!", i);
                frescurinha();
                break;
            default:
                printf("\n\n\n\n");
                frescurinha();
                printf("\t    Digite um valor válido.");
                frescurinha();
                printf("\n");
                break;
        }
       
    }while(entrada!=0);
      
  printf("\nO programa acertou seu número em %d tentativas!", i);
  
  return 0;
}
