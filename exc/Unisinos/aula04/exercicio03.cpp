/*
Crie uma função capaz de somar os elementos das linhas L1 e L2 de uma matriz. O
resultado deve ser colocado na linha L2. Faça o mesmo com a multiplicação.

*/


#include <iostream>

using namespace std;


int main(){
    int matriz[2][2];
    

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Informe o valor da posicao " << i << j <<  endl;
            cin >> matriz[i][j];
        }

    }
    
    for (int i = 0; i < 2; i++)
    {
    
        matriz[1][i] = matriz[0][i] + matriz[1][i];
        
    }
    

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout <<  matriz[i][j];
        }

        cout << endl;

    }


}
