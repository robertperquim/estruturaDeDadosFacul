#include <stdio.h>


#define MAX_TAM 10
 

int main (){

    float values[MAX_TAM];

    for (int i = 0; i < MAX_TAM; i++)
    {
        printf("Deigite o valor %d", i + 1);
        scanf("%f", &values[i]);
        
    }
    
     for (int i = 0; i < MAX_TAM; i++)
    {
        printf("%.2f ", values[i]);
    }


    return 0;
}