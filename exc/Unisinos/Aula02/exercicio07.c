/*Escreva um programa que leia uma matriz M de tamanho 5x5, conte e escreva
quantos valores maiores que 10 ela possui.*/

#include <stdio.h>


#define MAX_TAM 5
 

int main (){

    int values[MAX_TAM][MAX_TAM] = {{0}};

    int cont = 0;

    for (int i = 0; i < MAX_TAM; i++)
    {
        for (int j = 0; j < MAX_TAM; j++)
        {
            
            
            printf("digite o valor %d %d ", i, j);
            scanf("%d", &values[i][j]);
            
            
        }
        
    }

    for (int i = 0; i < MAX_TAM; i++)
    {
        for (int j = 0; j < MAX_TAM; j++)
        {
            if (values[i][j] > 10)
            {
                cont++;
            }
            
        }
        
    }
    
    printf("Qty maiores que 10  %d", cont);


    return 0;
}