/*
Escreva um programa que leia uma matriz de tamanho 20x20 e um valor inteiro
qualquer. O programa deverá fazer uma busca por esse valor na matriz e, ao final,
escrever sua localização (linha e coluna) na matriz ou a mensagem de “Valor não
encontrado”.

*/



#include <iostream>

using namespace std;


int main(){
    int matriz[2][2];
    int valor;

    cout << "Informe um valor " << endl;
    cin >> valor;


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
        for (int j = 0; j < 2; j++)
        {
            if(valor == matriz[i][j]){
                cout << "Valor encontrado na posicao " << i << j << endl;
                return 0;
            }

        }

    }

    cout << "Valor nao encontrado" << endl;

    
    
    

}