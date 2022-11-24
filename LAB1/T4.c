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
    int j = 1;
    for(int i = 20; i >= 0; i--)
    {
        printf("População de %d a %d: ", (j-1)*5, j*5);
        scanf("%d", &v[i]);
        j++;
    }
}

void desenha_piramide(int t, long int homens[t], long int mulheres[t])
{
    int i = 0, j = 0;
    
    for(i = 0; i < 21; i++)
    {
        
        for(j = 0; j < 39 - homens[i]; j++)
        {     
            printf(".");
        }
        for(j = 0; j < homens[i]; j++)
        {
            printf("x");
        }
        if(i == 0)
            printf(" ++ ");
        else
        {
            if(i > 18)
                printf(" ");
            printf(" %d ", 100 - (5*i));
        }
        for(j = 0; j < mulheres[i]; j++)
        {
            printf("x");
        }
        for(j = 0; j < 39 - mulheres[i]; j++)
        {
            printf(".");
        }
        printf("\n");
    }
}
int main()
{
    srand(time(0));
    long int homens[21], mulheres[21], maiorH;
    int j=0, i=0;
    
    printf("Informe os valores da população masculina:\n");
    preenche_vetor(21, homens);
    
    printf("Informe os valores da população feminina:\n");
    preenche_vetor(21, mulheres);
    
    /*
    for(int m=0; m<21; m++)
    {
        homens[m] = m+1;
        mulheres[m] = m+1;
    }
    */
    desenha_piramide(21, homens, mulheres);

    return 0;
}

