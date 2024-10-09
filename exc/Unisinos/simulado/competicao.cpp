#include "competicao.h"
#include <iostream>

using namespace std;

Competicao::Competicao(string nome, Data data) : data(data){
    this->nome = nome;
}

void Competicao::setNome(string nome){
    this->nome = nome;
}

void Competicao::setData(Data data){
    this->data=data;
}

Data Competicao::getData(){
    return this->data;
}

string Competicao::getNome(){
    return this->nome;
}

void Competicao::imprimeData(){
    data.imprimeData();
}