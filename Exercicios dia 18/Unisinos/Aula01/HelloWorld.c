#include <stdio.h>
#include <unistd.h>



int main(){ 

    char name[50], name2[20];

    printf("Enter your name: ");
    fgets(name, 50, stdin);

    printf("Enter your name: ");
    scanf("%s", &name2[0]);

    printf("Hello, %s!\n", name);

   return 0;
    
}