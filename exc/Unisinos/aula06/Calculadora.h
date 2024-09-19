
#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <string>

using namespace std;

class Calculadora {
private:
    float memoria;
    string cor;

public:
    Calculadora(string cor);

    float getMemoria();
    void setMemoria(float memoria);
    string getCor();
    void setCor(string cor);

    float soma(float a, float b);
    float subtrai(float a, float b);
    float multiplica(float a, float b);
    float divide(float a, float b);
    int eleva_ao_quadrado(int a);
    int eleva_ao_cubo(int a);

    void imprime_info();
};

#endif 