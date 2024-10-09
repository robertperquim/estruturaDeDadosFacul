#include "atleta.h"
#include <iostream>

using namespace std;


Atleta::Atleta(string nome, int idade){
    this->nome = nome;
    this->idade = idade;
}

string Atleta::getNome(){
    return this->nome;
}

int Atleta::getIdade(){
    return this->idade;
}

void Atleta::setNome(string nome){
    this->nome = nome;
}

void Atleta::setIdade(int idade){
    this->idade = idade;
}

void Atleta::imprimeInfo(){
    cout << "Iformacoes do atleta" << endl;
    cout << "Nome :" << nome << endl;
    cout << "Idade: " << idade << endl;
}