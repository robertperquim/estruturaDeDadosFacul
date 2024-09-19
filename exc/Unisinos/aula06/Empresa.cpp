#include "Empresa.h"
#include <iostream>

using namespace std;

Empresa::Empresa(string newNome, FuncionarioCaixa& funcionario1, FuncionarioCaixa& funcionario2)
    : nome(nome), funcionario1(funcionario1), funcionario2(funcionario2) {
        nome = newNome;
    }

string Empresa::getNome() {
    return nome;
}

void Empresa::setNome(string newNome) {
    nome = newNome;
}

FuncionarioCaixa Empresa::getFuncionario1(){
    return funcionario1;
}

void Empresa::setFuncionario1(FuncionarioCaixa& funcionario1) {
    funcionario1 = funcionario1;
}

FuncionarioCaixa Empresa::getFuncionario2(){
    return funcionario2;
}

void Empresa::setFuncionario2(FuncionarioCaixa& funcionario2) {
    funcionario2 = funcionario2;
}

void Empresa::imprime_info(){
    cout << "Nome da Empresa: " << nome << endl;
    cout << "Informações do Funcionário 1:" << endl;
    funcionario1.imprime_info();
    cout << "Informações do Funcionário 2:" << endl;
    funcionario2.imprime_info();
}