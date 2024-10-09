#include "corredor.h"
#include <iostream>
using namespace std;

Corredor::Corredor(string nome, int idade, double peso, Competicao Competicao) : Atleta(nome, idade), competicao(Competicao){
    this->peso = peso;
}

void Corredor::setPeso(double peso){
    this->peso=peso;
}

void Corredor::setCompeticao(Competicao competicao){
    this->competicao=competicao;
}

double Corredor::getPeso(){
    return this->peso;
}

Competicao Corredor::getCompeticao(){
    return this->competicao;
}

void Corredor::imprimeCompeticao(){
    cout << "Competicao: " << competicao.getNome() << endl;
    competicao.imprimeData();
}

void Corredor::imprimeInfo(){
    Atleta::imprimeInfo();
    cout << "peso: " << peso << endl;
    imprimeCompeticao();
}