#include <iostream>
#include "atleta.h"
#include "data.h"
#include "competicao.h"
#include "corredor.h"
#include "nadador.h"
#include "infoAtleta.h"


using namespace std;


int main(){

    Data data(24,11,2024);
    Competicao comp("Correr e show", data);
    cout << "Nome da competicao: " << comp.getNome()<< endl;
    comp.imprimeData();
    cout << "\n";


    Nadador nadador("Cielo", 34, "Borboleta");
    nadador.imprimeInfo();
    cout << "\n";

    Corredor corredor("Josenildo", 91, 68, comp);
    data.setDia(23);
    comp.setData(data);
    corredor.setCompeticao(comp);
    corredor.imprimeInfo();
    cout << "\n";

    Data dataSaoSilvestre(31,12,2024);
    Competicao saoSilvestre("Sao SIlvestre", dataSaoSilvestre);

    Corredor newCorredor("Petrolina", 60, 100, saoSilvestre);
    newCorredor.imprimeInfo();
    cout << "\n";

    Atleta* a;
    Nadador n;
    Corredor c;
    int opcao;
    string nome;
    int idade;

    cout << "Digite 1 para nadador e 2 para corredor" << endl;
    cin >> opcao;

    if (opcao == 1)
    {
        string categoria; 

        cout << "Cadastrando nadador" << endl;
        cout << "Informe o nome: " << endl;
        cin >> nome;

        cout << "Informe a idade: " << endl;
        cin >> idade;

        cout << "Informe a categoria : " << endl;
        cin >> categoria;

        n = Nadador(nome, idade, categoria);

        a = &n;
    }else
    {
        double peso; 

        cout << "Cadastrando corredor" << endl;
        cout << "Informe o nome: " << endl;
        cin >> nome;

        cout << "Informe a idade: " << endl;
        cin >> idade;

        cout << "Informe a peso: " << endl;
        cin >> peso;

        c = Corredor(nome, idade, peso, saoSilvestre);
        a = &c;
    }

    InfoAtleta info;

    cout << "\n";
    info.imprimeInfoExclusivoAtleta(a);
    info.imprimeInfoAtleta(a);

    if(Nadador* nTemp = dynamic_cast<Nadador*>(a)){
        nTemp->setCategoria("Livre");
    }else if (Corredor* cTemp = dynamic_cast<Corredor*>(a)){
        cTemp->setPeso(89);
    }
    cout << "\n";
    info.imprimeInfoAtleta(a);

    return 0;
}
