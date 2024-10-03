/*Crie uma classe Atleta, que possui um nome e uma idade. No construtor de
Atleta, receba todos os parâmetros necessários para inicializar os atributos. Crie
os métodos de acesso para os atributos e o método imprime_info, que não
recebe parâmetros e imprime as informações do Atleta.
*/



#ifndef ATLETA_H
#define ATLETA_H

#include <string>

using namespace std;

class Atleta {
private:
    int idade;
    string nome;

public:
    Atleta(string nome, int idade);

    int getIdade();
    void setIdade(int idade);
    string getNome();
    void setNome(string nome);

    void imprime_info();
};

#endif 