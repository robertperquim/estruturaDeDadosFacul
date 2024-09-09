/*
Escreva um programa que pede 5 números inteiros pelo teclado e imprime as
seguintes informações:
• a soma de todos os números
• o produto de todos os números
*/

#include <stdio.h>


int main(){

    int numbers[5]; 

    for (int i = 0; i < 5; i++)
    {
        printf("Digite o numero: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    int soma = numbers[0], multi = numbers[0];

    for (int i = 1; i < 5; i++)
    {
        soma = soma + numbers[i];
        multi = multi + numbers[i];

    }

    printf("%d", numbers[5]);
    
    printf("\nsoma %d", soma);
    printf("\nmulti %d", multi);


    return 0;
}