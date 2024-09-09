/*
Escreva um programa que leia uma matriz M de tamanho 6x6 e um valor A.
Multiplique os elementos da matriz M pelo valor A armazenando o resultado das
multiplicações em um vetor V de tamanho 36. Imprima na tela os valores
armazenados em V.

*/



#include <iostream>

using namespace std;


int main(){
    int matriz[2][2];
    int vetor[4];
    int valor;

    cout << "Informe um valor " << endl;
    cin >> valor;

    int countVetor = 0;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Informe o valor da posicao " << i << j <<  endl;
            cin >> matriz[i][j];

            vetor[countVetor] = matriz[i][j] * valor;
            countVetor++;
        }

    }
    
    for (int i = 0; i < countVetor; i++)
    {
        cout << vetor[i] << endl;
        
    }
    

}