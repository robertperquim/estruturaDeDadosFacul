/*
Escreva um programa que leia dados para uma matriz quadrada de inteiros. Ao final
da leitura o programa, deverá ser imprresso o número da linha que contém o menor
dentre todos os vaslores lidos.
*/


#include <iostream>

using namespace std;


int main(){
    int matriz[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Informe o valor da posicao " << i << j <<  endl;
            cin >> matriz[i][j];
        }
        
    }


    int menor = matriz[0][0];
    int linha = 0;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(matriz[i][j] < menor){
                menor = matriz[i][j];
                linha = i;
            }
        }
        
    }

    cout << "Linha do menor valor lido " << linha << " valor :" << menor << endl;

    

}
