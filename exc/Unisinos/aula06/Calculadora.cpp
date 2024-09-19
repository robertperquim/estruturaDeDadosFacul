#include "Calculadora.h"
#include <iostream>

using namespace std;

Calculadora::Calculadora(string newCor) {
    memoria = 0;  
    cor = newCor;
}

float Calculadora::getMemoria(){
    return memoria;
}

void Calculadora::setMemoria(float memoria) {
    memoria = memoria;
}

string Calculadora::getCor(){
    return cor;
}

void Calculadora::setCor(string newCor) {
    cor = newCor;
}

float Calculadora::soma(float a, float b) {
    return a + b;
}

float Calculadora::subtrai(float a, float b) {
    return a - b;
}

float Calculadora::multiplica(float a, float b) {
    return a * b;
}

float Calculadora::divide(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        cerr << "Erro: Divisão por zero!" << endl;
        return 0;
    }
}

int Calculadora::eleva_ao_quadrado(int a) {
    return a * a;
}

int Calculadora::eleva_ao_cubo(int a) {
    return a * a * a;
}

void Calculadora::imprime_info(){
    cout << "Calculadora de cor: " << cor << ", Memória: " << memoria << endl;
}