#include "Atleta.h"
#include <iostream>

using namespace std;


Atleta::Atleta(string newNome, int newIdade) {
    nome = newNome;  
    idade = newIdade;
}

int Atleta::getIdade(){
    return idade;
}

void Atleta::setIdade(int idade) {
    idade = idade;
}

string Atleta::getNome(){
    return nome;
}

void Atleta::setNome(string nome) {
    nome = nome;
}

void Atleta::imprime_info(){
    cout << "Nome do atleta: " << nome << ", Idade: " << idade << endl;
}
