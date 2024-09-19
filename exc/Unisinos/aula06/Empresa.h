#ifndef EMPRESA_H
#define EMPRESA_H

#include "FuncionarioCaixa.h"
#include <string>

using namespace std;

class Empresa {
private:
    string nome;
    FuncionarioCaixa funcionario1;
    FuncionarioCaixa funcionario2;

public:
    Empresa(string newNome, FuncionarioCaixa& funcionario1, FuncionarioCaixa& funcionario2);

    
    string getNome();
    void setNome( string newNome);
    FuncionarioCaixa getFuncionario1();
    void setFuncionario1(FuncionarioCaixa& funcionario1);
    FuncionarioCaixa getFuncionario2();
    void setFuncionario2(FuncionarioCaixa& funcionario2);

   
    void imprime_info();
};

#endif 