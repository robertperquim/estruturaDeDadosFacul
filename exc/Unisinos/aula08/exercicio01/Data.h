/* Crie a classe Data, que possui um dia, um mês e um ano. Crie um construtor que
recebe todos os parâmetros para inicializar os atributos e o método imprime_data,
que imprime a data no formato “DD/MM/AAAA”. Crie os métodos de acesso para os
atributos.*/


#ifndef DATA_H
#define DATA_H

#include <string>

using namespace std;

class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    Data(int dia, int mes, int ano);

    void imprime_data();
};

#endif 