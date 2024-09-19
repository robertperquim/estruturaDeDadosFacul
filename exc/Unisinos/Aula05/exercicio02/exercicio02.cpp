/*
Crie uma classe chamada Pessoa. Uma pessoa possui nome, idade, altura,
quantidade de irmãos e endereço. Na classe Pessoa:
• crie uma função chamada imprime_info, que imprime na tela as informações
da pessoa, de maneira organizada.
• crie uma função chamada is_filho_unico, que retorna verdadeiro caso a
pessoa seja filha única e falso caso contrário.
Na função main() faça o que se pede:
• crie 3 pessoas informando todos os dados.
• imprima as informações de todas as pessoas, de forma legível e organizada.
• imprima na tela a frase “Filho(a) único(a)” para as pessoas que forem filhas
únicas, e a frase “Não é filho(a) único(a)” para as pessoas que não forem filhas
únicas.

*/

/*
Crie uma classe chamada Retângulo. Um retângulo possui uma base e uma altura.
Crie as funções necessárias para que o usuário possa obter informações sobre a
base, a altura e a área do retângulo.
*/

#include <iostream>

using namespace std;

class Endereco {
    private:
    string rua;
    int numero;

    public:
    Endereco(int num, string rua);
    void setRua(string rua);
    void setNumero(int n);
    string getRua();
    int getNumero();
    
};


Endereco::Endereco(int num, string rua){
    numero = num;
    rua = rua;
}

  
void Endereco::setRua(string r) {
        rua = r;
    }

void Endereco::setNumero(int n) {
        numero = n;
    }


string Endereco::getRua(){
        return rua;
    }

int Endereco::getNumero(){
        return numero;
    }

class Pessoa {
private:
    string nome;
    int idade;
    float altura;
    int quantidadeIrmaos;
    Endereco endereco;

public:
    
    Pessoa(string n, int i, int a, int q, Endereco e);

    
    void setNome(string n);
    void setIdade(int i);
    void setAltura(float a);
    void setQuantidadeIrmaos(int q);
    void setEndereco(Endereco e);

   
    string getNome();
    int getIdade();
    int getAltura();
    int getQuantidadeIrmaos();
    Endereco getEndereco();
    void imprimeInfo(); 
    bool isFilhoUnico();
    
};

Pessoa::Pessoa(string n, int i, int a, int q, Endereco e) 
    : endereco(e) {
    nome = n;
    idade = i;
    altura = a;
    quantidadeIrmaos = q;
    
}

void Pessoa::setNome(string n) {
    nome = n;
}

void Pessoa::setIdade(int i) {
    idade = i;
}

void Pessoa::setAltura(float a) {
    altura = a;
}

void Pessoa::setQuantidadeIrmaos(int q) {
    quantidadeIrmaos = q;
}

void Pessoa::setEndereco(Endereco e) {
    endereco = e;
}

string Pessoa::getNome() {
    return nome;
}

int Pessoa::getIdade() {
    return idade;
}

int Pessoa::getAltura() {
    return altura;
}

int Pessoa::getQuantidadeIrmaos() {
    return quantidadeIrmaos;
}

Endereco Pessoa::getEndereco() {
    return endereco;
}

void Pessoa::imprimeInfo() {
    cout << "Informações da Pessoa:" << endl;
    cout << "Nome: " << getNome() << endl;
    cout << "Idade: " << getIdade() << endl;
    cout << "Altura: " << getAltura() << endl;
    cout << "Quantidade de Irmãos: " << getQuantidadeIrmaos() << endl;
    cout << "Endereço: " << getEndereco().getRua() << ", " << getEndereco().getNumero() << endl;
}

bool Pessoa::isFilhoUnico() {
    return quantidadeIrmaos == 0;
}

int main() {
    Endereco endPessoa1(300, "Rua do sla");
    Endereco endPessoa2(330, "Rua do slasla");
    Endereco endPessoa3(350, "Rua do slaslaslasal");
    Pessoa pessoa1("João", 30, 1.75, 2, endPessoa1);
    Pessoa pessoa2("Maria", 25, 1.65, 0, endPessoa2);
    Pessoa pessoa3("Carlos", 40, 1.80, 1, endPessoa3);

    
    Pessoa pessoas[] = {pessoa1, pessoa2, pessoa3};

    
    for (int i = 0; i < 3; ++i) {
        pessoas[i].imprimeInfo();
        if (pessoas[i].isFilhoUnico()) {
            cout << "Filho único" << endl;
        } else {
            cout << "Não é filho único" << endl;
        }
        cout << "------------------------" << endl;
    }

    return 0;
}