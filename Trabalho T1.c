/*
Inácio Camargo Buemo 
Turma: SI1 2022-2
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

int main ()
{
 
  setlocale(LC_ALL, "portuguese");
  int segredo, chute, entrada, entrada1, i=0, max=0, min=0;
  srand (time (0));
  printf("O jogo terá qual valor máximo?\nDigite: ");
  scanf("%d", &max);
  chute = (rand () % (max+1)) ;
  printf("Instruções:\nPense em um valor entre 0 e %d.\n\nEscreva ' 0 ' caso o chute do programa esteja certo.", max);
  printf("\nEscreva ' 1 ' caso o chute esteja abaixo do valor pensado. \nEscreva ' 2 ' caso o chute esteja acima.\n\t");
  printf("\nPara começar, digite 0: ");
  scanf("%d", &entrada1);
    
    do
    {
        i++;
        printf("\nChute do programa: %d\n", chute);
        printf("\nEstá certo?\n0 = Sim\n1 = Está abaixo.\n2 = Está acima.\n Digite: ");
        scanf("%d", &entrada);
        
        if(entrada==2)
        {
            max = chute;
            chute=(rand() % (max-min+1))+min;
        
        }
        
        else if(entrada==1)
        {
            min = chute;
            chute = (rand() % (max-min+1))+min;
        }
       
    }while(entrada1==0 && entrada!=0);
      
  printf("\nO programa acertou seu número em %d tentativas!\n", i);
  
  return 0;
}
