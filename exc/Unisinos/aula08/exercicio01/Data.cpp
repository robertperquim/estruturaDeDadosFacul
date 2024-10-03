#include "Data.h"
#include <iostream>

using namespace std;



Data::Data(int dia, int mes, int ano) {
    dia = dia;  
    mes = mes;
    ano = ano;
}

void Data::imprime_data(){
    cout << dia << "/" << mes << "/" << ano << endl;
}
