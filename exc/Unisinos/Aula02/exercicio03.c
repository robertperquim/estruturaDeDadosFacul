#include <stdio.h>


#define MAX_TAM 10
 

int main (){

    int values[MAX_TAM] = {10,9,8,7,6,5,4,3,2,1};

    int cont = 0 ;

    for (int i = 0; i < MAX_TAM; i++)
    {
        if(values[i] < 0){
            cont++;
        }
        
    }
    
    printf("Qty negativos %d", cont);


    return 0;
}