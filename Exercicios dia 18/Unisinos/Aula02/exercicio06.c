/*Escreva um programa que leia duas strings (de tamanho máximo 40). Após a leitura,
o programa deve concatenar as informações lidas e mostrar o resultado na tela. Por
exemplo, se a primeira string lida for "Boa noite, " e a segunda string lida for
"turma!", então o resultado será: "Bo noite, turma!".*/

#include <stdio.h>
#include <string.h>



#define MAX_TAM 40

int main (){

    char string1[MAX_TAM], string2[MAX_TAM];

    printf("Deigite a primeira string ");
    gets(string1);
    
    printf("Deigite a primeira string ");
    gets(string2);

     
    printf("%s\n", strcat(string1, string2));
     

    return 0;
}