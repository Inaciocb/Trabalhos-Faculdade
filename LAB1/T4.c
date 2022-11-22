#include <stdio.h>
#include <time.h>

int qual_maior(int tam, v[tam])
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
        v[i] = rand()%35; 
    }
}

int main()
{
    srand(time(0));
    long int homens[21], mulheres[21], maiorH;
   
    preenche_vetor(21, homens);
    preenche_vetor(21, mulheres);

    maiorH = qual_maior(21, homens);

    return 0;
}
