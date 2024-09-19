/*
Crie uma classe chamada Retângulo. Um retângulo possui uma base e uma altura.
Crie as funções necessárias para que o usuário possa obter informações sobre a
base, a altura e a área do retângulo.
*/

#include <iostream>

using namespace std;

class Retangulo{
    public:
    void setBase(int newBase);
    void setAltura(int newAltura);
    int getBase();
    int getAltura();
    int getArea();
    private:
    int base;
    int altura;
};

void Retangulo::setBase(int newBase){
    base = newBase;
}

void Retangulo::setAltura(int newAltura){
    altura = newAltura;
}
int Retangulo::getBase(){
    return base;
}
int Retangulo::getAltura(){
    return altura;
}
int Retangulo::getArea(){
    return base * altura;
}

int main(){
    
    Retangulo retangulo; 

    retangulo.setBase(2);
    retangulo.setAltura(2);
    

     cout << "Base:  " << retangulo.getBase() << endl;
     cout << "Altura:  " << retangulo.getAltura() << endl;
     cout << "Area:  " << retangulo.getArea() << endl;

}
