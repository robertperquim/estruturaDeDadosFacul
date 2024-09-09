#include <stdio.h>


#define MAX_TAM 10
 

int main (){

    int values[MAX_TAM];

    for (int i = 0; i < MAX_TAM; i++)
    {
        printf("Deigite o valor %d ", i + 1);
        scanf("%d", &values[i]);
        
    }

    int search, count = 0;

    printf("Deigite o valor para pesquisar ");
    scanf("%d", &search);
    


     for (int i = 0; i < MAX_TAM; i++)
    {
        if (values[i] == search){
            count++;
        }
    }
    

    printf("O valor aparece %d vezes", count);

    return 0;
}