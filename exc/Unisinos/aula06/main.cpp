#include "Empresa.h"
#include <iostream>
using namespace std;
int main() {
  
    Calculadora calc1("Vermelha");
    Calculadora calc2("Azul");

    
    FuncionarioCaixa func1("Joao", "Rua A, 123", calc1);
    FuncionarioCaixa func2("Maria", "Rua B, 456", calc2);

    
    cout << "Operacoes com a calculadora do primeiro funcionrio:" << endl;
    cout << "2 + 2 = " << func1.soma(2, 2) << endl;
    cout << "5 - 4 = " << func1.subtrai(5, 4) << endl;
    cout << "2 x 3 = " << func1.multiplica(2, 3) << endl;

   
    cout << "Operacoes com a calculadora do segundo funcionario:" << endl;
    cout << "6 / 3 = " << func2.divide(6, 3) << endl;
    cout << "7 + 2 = " << func2.soma(7, 2) << endl;
    cout << "8 x 3 = " << func2.multiplica(8, 3) << endl;

   
    Empresa empresa("Minha Empresa", func1, func2);

    
    cout << "Informacoes da Empresa:" << endl;
    empresa.imprime_info();

    return 0;
}