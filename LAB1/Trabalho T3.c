/*
Nome do aluno: Inácio Camargo Buemo
Turma SI1
*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool verificaInteiro(double x)
{
    int truncado = (int)x;
    return (x == truncado);
}

double XnaY (double x, double y)
{
    double resultado = x;
    int i = 1;
    
    if(verificaInteiro(y) == true)
    {
        if(y > 0)
        {
            for(i = 1; i < y; i++)
            {
                resultado *= x;
            }
        }
        else if(y < 0)
        {
            y *= (-1);
            for(i = 1; i < y; i++)
            {
                resultado *= x;
            }
            resultado = 1/resultado;
        }
        else if(y == 0)
        {
            resultado = 1;
        }
    }
    else
    {
        double ExpoenteFracionario();
        if(y > 0)
        {
            resultado = ExpoenteFracionario(x, y);
        }else
        {
            resultado = (1)/(ExpoenteFracionario(x, y));
        }
    }
    
    return resultado;
}

int main()
{
    double x = 2, y = -0.5;
    printf("%lf\n\n", pow(x, y));
    return 0;
}

/*
nessa função que calcula caso o expoente seja fracionário, 
o 'j' equivale ao denominador do expoente (radical) e 'i' equivale 
ao nominador do expoente fracionário. 
*/
double ExpoenteFracionario(double base, double valor)
{
    
    int i = 2;
    double j;
    
    /* 
    esse laço while verifica a fração que resulta no número
    não-inteiro recebido pelo parâmetro 'valor'. Fazendo isso, é possivel 
    calcular a partir do logaritmo o resultado de uma base elevada
    ao expoente fracionário. 
    */
    while(fmod(j, 10) != 0)
    {
        j = valor * i;
        if(fmod(j,10) != 0)
        {
            i++;
        }
    }
    
    //esses verificadores 'if' simplificam a fração caso necessário.
    if(j >= 10)
    {
        j = j/10;
    }
    if(i >= 10)
    {
        i = i/10;
    }  
    // retorna o valor base^(j/i), por meio da aplicação das propriedades dos logaritmos.
    return XnaY(i, (j/i) * (log(base)/log(i)));
}
