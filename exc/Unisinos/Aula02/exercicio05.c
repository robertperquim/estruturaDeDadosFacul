#include <stdio.h>
#include <string.h>



#define MAX_TAM 20

int main (){

    char string1[MAX_TAM], string2[MAX_TAM];

    printf("Deigite a primeira string ");
    gets(string1);
    
    printf("Deigite a primeira string ");
    gets(string2);

     if (strcmp(string1, string2) == 0)
     {
        printf("String iguais");
     }else{
        printf("%s", strcat(string1, string2));
     }

    return 0;
}