#ifndef NADADOR_H
#define NADADOR_H

#include "atleta.h"

using namespace std;

class Nadador : public Atleta
{
private:
    string categoria;
public:
    Nadador(string nome, int idade, string categoria);
    Nadador() = default;
    
    void setCategoria(string categoria);
    string getCategoria();
    void imprimeInfo();
};

#endif