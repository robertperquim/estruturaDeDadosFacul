/*
Crie a classe Competicao, que possui um nome e uma data (objeto do tipo Data).
No construtor, receba os parâmetros necessários para inicializar todos os atributos.
Crie os métodos de acesso para os atributos. Crie o método imprime_data que
imprime a data da competição.*/

#ifndef COMPETICAO_H
#define COMPETICAO_H

#include <string>
#include "Data.h"

using namespace std;

class Competicao {
private:
    string nome;
    Data data;
   

public:
    Competicao(string nome,Data& data);

    string getNome();
    void setNome(string nome);
    Data getData();
    void setData(Data& data);

    void imprime_data();
};

#endif 