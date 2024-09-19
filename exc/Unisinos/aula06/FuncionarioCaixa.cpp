#include "FuncionarioCaixa.h"
#include <iostream>

using namespace std;

FuncionarioCaixa::FuncionarioCaixa(string newNome, string newEndereco, Calculadora& newCalculadora) :
 calculadora(newCalculadora) {
    nome = newNome;
    endereco = newEndereco;
}
string FuncionarioCaixa::getNome(){
    return nome;
}
void FuncionarioCaixa::setNome(string newNome) {
    nome = newNome;
}
string FuncionarioCaixa::getEndereco(){
    return endereco;
}
void FuncionarioCaixa::setEndereco(string newEndereco) {
    endereco = newEndereco;
}
Calculadora FuncionarioCaixa::getCalculadora(){
    return calculadora;
}
void FuncionarioCaixa::setCalculadora(Calculadora& newCalculadora) {
    calculadora = calculadora;
}
float FuncionarioCaixa::soma(float a, float b) {
    return calculadora.soma(a, b);
}

float FuncionarioCaixa::subtrai(float a, float b) {
    return calculadora.subtrai(a, b);
}
float FuncionarioCaixa::multiplica(float a, float b) {
    return calculadora.multiplica(a, b);
}
float FuncionarioCaixa::divide(float a, float b) {
    return calculadora.divide(a, b);
}
int FuncionarioCaixa::eleva_ao_quadrado(int a) {
    return calculadora.eleva_ao_quadrado(a);
}
int FuncionarioCaixa::eleva_ao_cubo(int a) {
    return calculadora.eleva_ao_cubo(a);
}
void FuncionarioCaixa::imprime_info(){
    cout << "Nome: " << nome << ", Endereço: " << endereco << endl;
    calculadora.imprime_info();
}
