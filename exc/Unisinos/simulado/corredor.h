#ifndef CORREDOR_H
#define CORREDOR_H

#include "atleta.h"
#include "competicao.h"
#include <string>
using namespace std;
 
class Corredor : public Atleta
{
private:
    double peso;
    Competicao competicao;
public:
    Corredor(string nome, int idade, double peso, Competicao competicao);
    Corredor() = default;

    void setPeso(double peso);
    void setCompeticao(Competicao competicao);

    double getPeso();
    Competicao getCompeticao();

    void imprimeCompeticao();
    void imprimeInfo();
};

#endif