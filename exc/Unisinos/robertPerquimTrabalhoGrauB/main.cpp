//ROBERT PERQUIM Eu não encontrei uma dupla sora

#include <iostream>
#include "doublyLinkedList.h"

using namespace std;

int main() {
    int default_code = -1;
    int& result = default_code;

    DoublyLinkedList<int> lista;

    
    lista.insertFirst(10);
    cout << "Apos insertFirst(10):" << endl;
    lista.printDetailedList();

    cout << endl;

    lista.insertFirst(8);
    cout << "Apos insertFirst(8):" << endl;
    lista.printDetailedList();

    cout << endl;

    lista.insertLast(20);
    cout << "Apos insertLast(20):" << endl;
    lista.printDetailedList();

    cout << endl;

    lista.insertLast(12);
    cout << "Apos insertLast(12):" << endl;
    lista.printDetailedList();

    cout << endl;

    lista.insert(15, 1);
    cout << "Apos insert(15, 1):" << endl;
    lista.printDetailedList();

    cout << endl;

    lista.insert(15, 3);
    cout << "Apos insert(15, 3):" << endl;
    lista.printDetailedList();

    cout << endl;
   
    int pos = lista.search(15);
    cout << "Posição do elemento 15: " << pos << endl;

    cout << endl;
    
    int elemento;
    lista.get(1, elemento);
    cout << "Elemento na posição 1: " << elemento << endl;

    cout << endl;
    
    lista.removeFirst(elemento);
    cout << "Elemento removido do início: " << elemento << endl;
    cout << "Apos removeFirst:" << endl;
    lista.printDetailedList();

    cout << endl;

    lista.removeLast(elemento);
    cout << "Elemento removido do final: " << elemento << endl;
    cout << "Apos removeLast:" << endl;
    lista.printDetailedList();

    cout << endl;

    lista.remove(0, elemento);
    cout << "Elemento removido da posição 0: " << elemento << endl;
    cout << "Apos remove(0):" << endl;
    lista.printDetailedList();

    return 0;
}