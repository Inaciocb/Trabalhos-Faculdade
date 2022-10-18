#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int i=0, entrada;
    float chute, min=0, max;
    srand(time(0));
    printf("\n\tQual será o valor máximo do programa? ");
    scanf("%f", &max);
    chute = fmod(rand(),(max))+1;
    printf("Pense em um número de 0 a %.3f\n", max);
    
    do
    {
        i++;
        printf("\nO chute do programa é %.3f", chute);
        printf("\n\tEstá certo?\n"
               "Digite \"0\" caso esteja certo.\n"
               "Digite \"1\" para caso o chute esteja abaixo do valor pensado.\n"
               "Digite \"2\" para caso o chute esteja acima do valor pensado.\n"
               "\n-> ");
        scanf("%d", &entrada);
        
        if(entrada==1)
        {
            min = chute +1;
            chute = fmod(rand(), (max -min))+min;
        }else if(entrada==2)
        {
            max = chute -1;
            chute = fmod(rand(), (max -min))+min;
        }
    }while(entrada!=0);
    
    printf("O programa acertou o seu número em %d tentativas!", i);
    return 0; 
}
