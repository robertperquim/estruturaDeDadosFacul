#include <stdio.h>


#define MAX_TAM 11
#define MIN_TAM 10 

int main (){

    int origin1[MIN_TAM] = {10,9,8,7,6,5,4,3,2,1};
    int origin2[MAX_TAM] = {0,1,4,9,16,25,36,49,64,81,100};
    int origin3[MIN_TAM] = {1,2,3,4,5,10,20,30,40,50};
    int origin4[MIN_TAM] = {3,4,7,12,19,28,39,52,67,84};
    
    int destination1[MIN_TAM], destination2[MAX_TAM], destination3[MIN_TAM], destination4[MIN_TAM];

    for (int i = 0; i < MAX_TAM; i++)
    {
        if (i < MIN_TAM)
        {
            destination1[i] = origin1[i];
            destination3[i] = origin3[i];
            destination4[i] = origin4[i];    
        }

        destination2[i]=origin2[i];
        
    }

    printf("ARRAY1\tARRAY2\tARRAY3\tARRA4\n");
    
     for (int i = 0; i < MAX_TAM; i++)
    {
        if (i <MIN_TAM)
        {
            printf("%d\t%d\t%d\t", destination1[i], destination3[i],destination4[i]);
        }else{
            if (i== MAX_TAM -1 )
            {
                printf("\t\t\t");
            }
            
        }
        

         printf("\t%d\n", destination2[i]);
        
    }




    return 0;
}