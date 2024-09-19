/*
Crie uma classe chamada Retângulo. Um retângulo possui uma base e uma altura.
Crie as funções necessárias para que o usuário possa obter informações sobre a
base, a altura e a área do retângulo.
*/

#include <iostream>

using namespace std;

class Veiculo{
    public:
    Veiculo(int newAno,string newModelo, string newMarca);
    void setAno(int newAno);
    void setModelo(string newModelo);
    void setMarca(string newMarca);
    int getAno();
    string getMarca();
    string getModelo();
    private:
    string modelo;
    int ano;
    string marca;
};
 Veiculo::Veiculo(int newAno,string newModelo, string newMarca){
    ano = newAno;
    modelo = newModelo;
    marca = newMarca;
}


void Veiculo::setAno(int newAno){
    ano = newAno;
}

void Veiculo::setModelo(string newModelo){
    modelo = newModelo;
}
void Veiculo::setMarca(string newMarca){
    marca = newMarca;
}
int Veiculo::getAno(){
    return ano;
}
string Veiculo::getMarca(){
    return marca;
}
string Veiculo::getModelo(){
    return modelo;
}

int main(){
    
    Veiculo carro(2024, "carro  slaoq", "bmw"); 
    Veiculo moto(2024, "moto slaoq", "bmw"); 


    cout << "Carro:  " << endl;
    cout << "Ano:  " << carro.getAno() << endl;
    cout << "Marca  "  << carro.getMarca() << endl;
    cout << "Modelo  "  << carro.getModelo() << endl;

    cout << "Moto:  " << endl;
    cout << "Ano:  " << moto.getAno() << endl;
    cout << "Marca  "  << moto.getMarca() << endl;
    cout << "Modelo  "  << moto.getModelo() << endl;

}
