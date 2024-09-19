#ifndef FUNCIONARIOCAIXA_H
#define FUNCIONARIOCAIXA_H

#include "Calculadora.h"
#include <string>

using namespace std;

class FuncionarioCaixa {
private:
    string nome;
    string endereco;
    Calculadora calculadora;

public:
    FuncionarioCaixa(string newNome, string newEndereco,Calculadora& calculadora);

    
    string getNome();
    void setNome(string newNome);
    string getEndereco();
    void setEndereco(string newEndereco);
    Calculadora getCalculadora();
    void setCalculadora(Calculadora& calculadora);

    float soma(float a, float b);
    float subtrai(float a, float b);
    float multiplica(float a, float b);
    float divide(float a, float b);
    int eleva_ao_quadrado(int a);
    int eleva_ao_cubo(int a);

    void imprime_info();
};

#endif 