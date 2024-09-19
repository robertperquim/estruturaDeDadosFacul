/*
Escreva um programa que apresenta a seguinte saída, perguntando ao usuário o
número máximo (no exemplo, 9). Este número deve ser sempre ímpar.
1 2 3 4 5 6 7 8 9
 2 3 4 5 6 7 8
 3 4 5 6 7
 4 5 6
 5

  
*/


// pensar na solucao 

#include <iostream>
#include <iomanip>

using namespace std;


int main(){

    int valor;

    cout << "Informe um valor impar " << endl;
    cin >> valor;

    while (valor %2 == 0 )
    {
        cout << "O valor deve ser impar " << endl;
        cin >> valor;
    }
    

    for (int i = 0; i < valor; i++)
    {   if(i != 0 ){
         cout << setw(i + 1);
     }
        
        for (int j = i + 1; j <= valor - i; j++)
        {
            cout << j  ;
        }
        cout << endl;
    }

}
