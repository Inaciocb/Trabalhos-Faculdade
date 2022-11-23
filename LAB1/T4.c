#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int qual_maior(int tam, int v[tam])
{
    int maior = 0;
    for(int i = 0; i < tam; i++)
    {
        if(v[i] > v[maior])
            maior = i;
    }
}

void preenche_vetor(int tam, int v[tam])
{
    for(int i = 0; i< 21; i++)
    {
        v[i] = (rand()%27)+1; 
    }
}

int main()
{
    srand(time(0));
    long int homens[21], mulheres[21], maiorH;
   
    preenche_vetor(21, homens);
    preenche_vetor(21, mulheres);

    for(int i = 0; i < 21; i++)
    {
        for(int j=0; j < 74; j++)
        {
            if(j == 37 && i>0)
                printf("%d", 100 - (5*i));
            else if(j == 37)
            printf("++");
            
            if(j < 36 && j >= 35 - homens[i])
            {
                printf("x");
            }
            else
            {
                printf(" ");
            }

        }
        printf("\n");
    }

    return 0;
}
