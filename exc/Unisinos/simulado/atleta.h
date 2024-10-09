#ifndef ATLETA_H
#define ATLETA_H

#include <string>

using namespace std;

class Atleta {
private: 
    string nome;
    int idade;
public:
    Atleta(string nome, int idade);
    Atleta() = default;

    string getNome();
    void setNome(string nome);
    int getIdade();
    void setIdade(int idade);
    virtual void imprimeInfo();

};

#endif