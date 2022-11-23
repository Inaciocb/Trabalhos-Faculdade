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

void preenche_vetor(int tam, long int v[tam])
{
    for(int i = 21; i >= 0; i--)
    {
        printf("População de %d a %d: ");
        scanf("%d", &v[i]);
    }
}

int main()
{
    srand(time(0));
    long int homens[21], mulheres[21], maiorH;
    
    printf("Informe os valores da população masculina:\n\n");
    preenche_vetor(21, homens);
    
    printf("Informe os valores da população feminina:\n\n");
    preenche_vetor(21, mulheres);

    for(int i = 0; i < 21; i++)
    {
        for(int j=0; j < 74; j++)
        {
            if(j == 36 && i > 0 )
            {
                if(i > 18)
                    printf(".");
                printf("%d", 100 - (5*i));
                
            }else 
            if(j == 36 && i == 0)
            {
                printf("++");
            }
            if(j < 35 && j >= 35 - homens[i])
                printf("x");
            else if(j > 36 && j <= 74 - mulheres[i])
                printf("x");    
            else
            {
                printf(".");
            }


            

        }
        printf("\n");
    }
    printf("\n\n%d e %d\n\n%d\n%d\n", mulheres[2], homens[2], homens[10], homens[1]);
    return 0;
}
