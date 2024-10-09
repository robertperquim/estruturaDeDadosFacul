#include "infoAtleta.h"
#include <iostream>
#include "nadador.h"
#include "corredor.h"

using namespace std;


void InfoAtleta::imprimeInfoExclusivoAtleta(Atleta* atleta){
    if (Nadador* n = dynamic_cast<Nadador*>(atleta))
    {
        cout << "É um nadador, e sua categoria  é " << n->getCategoria() << endl;

    }else if(Corredor* c = dynamic_cast<Corredor*>(atleta)) {
        cout << "É um corredor, e seu peso é " << c->getPeso() << endl;
    }
}

void InfoAtleta::imprimeInfoAtleta(Atleta* atleta){
    if (Nadador* n = dynamic_cast<Nadador*>(atleta))
    {
        n->imprimeInfo();
    }else if (Corredor* c = dynamic_cast<Corredor*>(atleta)){
        c->imprimeInfo();
    }
    

}