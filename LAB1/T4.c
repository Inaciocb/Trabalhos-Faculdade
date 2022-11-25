#include <stdio.h>
#include <math.h>

int i = 0;
float j = 0;

void cor_texto(int vermelho, int verde, int azul)
{
    printf("\e[38;2;%d;%d;%dm", vermelho, verde, azul);
}

void cor_normal(void)
{
    printf("\e[m");
}
 void cor_fundo(int vermelho, int verde, int azul)
{
     printf("\e[48;2;%d;%d;%dm", vermelho, verde, azul);
}

int qual_maior(int tam, float v[tam])
{
    
    float maior = v[0];
    for(i = 0; i < tam; i++)
    {
        if(v[i] > maior)
            maior = v[i];
    }
    return maior;
}

void desenha_piramide(int t, float homens[t], float mulheres[t])
{
    printf("\n\n");
    
    for(i = 20; i >= 0; i--)     
    {     
        for(j = 0; j < 39 - homens[i]; j++)
        {     
            printf(" ");
        }
        for(j = 0; j < homens[i]/8; j+= 0.125)
        {
            cor_texto(10, 5, 200);
            printf("▏");
            cor_normal();
        }
        if(i == 20)
        {
            printf(" ++ ");
            cor_normal();
        }       
        else
        {
            if(i < 2)
                printf(" ");
            printf(" %d ", (5*i));
        }
        for(j = 0; j < mulheres[i]/8; j+= 0.125)
        {
            cor_texto(200,10,100);
            printf("▏");
            cor_normal();
        }
        for(j = 0; j < 39; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
}
int main()
{
    float homens[21] = { 200, 190, 180, 170, 160, 150, 140, 129, 120, 110, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0 };
    float  mulheres[21] = { 200, 190, 180, 170, 160, 150, 140, 129, 120, 115, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0 };

    float maior = qual_maior(21, homens);
    if(qual_maior(21, mulheres) > maior)
        maior = qual_maior(21, mulheres);

    for(i = 0; i < 21; i++)
    {
        homens[i] = round((35*homens[i])/maior);
        mulheres[i] = round((35*mulheres[i]))/ maior;
    }

    desenha_piramide(21, homens, mulheres);
    return 0;
}