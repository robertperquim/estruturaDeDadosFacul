#include "Competicao.h"
#include <iostream>

using namespace std;


Competicao::Competicao(string newNome, Data& data): 
data(data){
    nome = newNome;
}

Data Competicao::getData(){
    return data;
}

void Competicao::setData(Data& data) {
    data = data;
}

string Competicao::getNome(){
    return nome;
}

void Competicao::setNome(string nome) {
    nome = nome;
}

void Competicao::imprime_data(){
    data.imprime_data();
}
