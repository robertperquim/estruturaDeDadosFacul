#ifndef COMPETICAO_H
#define COMPETICAO_H
#include <string>
#include "data.h"

using namespace std;

class Competicao
{
private:
    string nome;
    Data data;
public:
    Competicao(string nome, Data data);
    Competicao()= default;

    void setNome(string nome);
    void setData(Data data);

    string getNome();
    Data getData();

    void imprimeData();
};




#endif