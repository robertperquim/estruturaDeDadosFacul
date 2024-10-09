#include "nadador.h"
#include <iostream>

using namespace std;

Nadador::Nadador(string nome, int idade, string categoria) : Atleta(nome, idade){
    this-> categoria = categoria;
}

void Nadador::setCategoria(string categoria){
    this->categoria = categoria;
}

string Nadador::getCategoria(){
    return this->categoria;
}

void Nadador::imprimeInfo(){
    Atleta::imprimeInfo();
    cout << "Categoria: " << categoria << endl;

}
