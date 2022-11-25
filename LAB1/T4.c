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
    int j = 0;
    for(int i = tam-1; i >= 0; i--)
    {
        if(i == 0)
            printf("População com mais de 100 anos: ");
        else
        printf("População entre %d e %d anos: ", j*5, (j+1)*5);
        scanf("%ld", &v[i]);
        j++;
    }
}

void desenha_piramide(int t, long int homens[t], long int mulheres[t])
{
    int i = 0, j = 0;
    printf("\n\n");
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

   ///* 
    printf("Informe os valores da população masculina:\n");
    preenche_vetor(21, homens);
    
    printf("\n\nInforme os valores da população feminina:\n");
    preenche_vetor(21, mulheres);
    
   // */
   /* 
    for(int m=0; m<21; m++)
    {
        homens[m] = m+1;
        mulheres[m] = m+1;
    }
    */
    int j=0, i=0;
    desenha_piramide(21, homens, mulheres);

    return 0;
}

/*
                                     X ++ XX
                                    XX 95 XX
                                    XX 90 XXX
                                   XXX 85 XXX
                                  XXXX 80 XXXX
                                 XXXXX 75 XXXXX
                                 XXXXX 70 XXXXXX
                                XXXXXX 65 XXXXXX
                                XXXXXX 60 XXXXXX
                               XXXXXXX 55 XXXXXXX
                             XXXXXXXXX 50 XXXXXXXXXXXX
                          XXXXXXXXXXXX 45 XXXXXXXXXXXXXXX
                       XXXXXXXXXXXXXXX 40 XXXXXXXXXXXXXXXXXX
                    XXXXXXXXXXXXXXXXXX 35 XXXXXXXXXXXXXXXXXXXXXXXXXXX
               XXXXXXXXXXXXXXXXXXXXXXX 30 XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
          XXXXXXXXXXXXXXXXXXXXXXXXXXXX 25 XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX 20 XXXXXXXXXXXXXXXXXXXXXXXXXXXXX
            XXXXXXXXXXXXXXXXXXXXXXXXXX 15 XXXXXXXXXXXXXXXXXXXXXXXXX
                   XXXXXXXXXXXXXXXXXXX 10 XXXXXXXXXXXXXXXXXXX
                         XXXXXXXXXXXXX  5 XXXXXXXXXXXX
                         XXXXXXXXXXXXX  0 XXXXXXXXXXXX

População de 0 a 5 anos: 1
População de 5 a 10 anos: 1
População de 10 a 15 anos: 1
População de 15 a 20 anos: 1
População de 20 a 25 anos: 1
População de 25 a 30 anos: 1
População de 30 a 35 anos: 1
População de 35 a 40 anos: 1
População de 40 a 45 anos: 1
População de 45 a 50 anos: 1
População de 50 a 55 anos: 1
População de 55 a 60 anos: 1
População de 60 a 65 anos: 1
População de 65 a 70 anos: 1
População de 70 a 75 anos: 1
População de 75 a 80 anos: 1
População de 80 a 85 anos: 1
População de 85 a 90 anos: 1
População de 90 a 95 anos: 1
População de 95 a 100 anos: 1
População de 100 anos ou mais1


*/