/**
 * Exercícios sobre listas encadeadas:
 * SinglyLinkedList e DoublyLinkedList
 */

#include <iostream>
#include <limits.h>
#include "node.h"
#include "singlyLinkedList.h"
#include "doublyLinkedList.h"

using namespace std;

/**
 * Exercício 1
 */

int convertToInt(SinglyLinkedList<int> list){
    Node<int>* prev;

    prev = list.head;

    string aux;
    string s = "";

    while (prev != nullptr)
    {
      aux = to_string(prev->getElement());
      s.append(aux);
      prev = prev->getNext();
    }

    int number = stoi(s);

    return number;
    
}


/**
 * Exercício 2
 */

int recursiveSum(SinglyLinkedList<int> list, int pos, int value){
    if (pos == list.numElements())
    {
        return 0;
    }else{
        list.get(pos, value);
        return value + recursiveSum(list, pos + 1, value);
    }    
}

int recursiveSum(SinglyLinkedList<int> list){
    if (list.isEmpty())
    {
        return INT_MAX;
    }else{
        int value = 0;
        return recursiveSum(list, 0, value);
    }
    
}


/**
 * Exercício 5
 */

bool isSorted(DoublyLinkedList<int> list) {
    int r1, r2;
    for(int i = 0; i < list.numElements() - 1; i++) {
        list.get(i, r1);
        list.get(i + 1, r2);
        if(r1 > r2)
            return false;
    }

    return true;
}

int main() {
    SinglyLinkedList<int> sl;  // Cria uma lista encadeada de tipo int

    /**
     * Insere os elementos 5, 6, 7, 8 e 9 em sequência na lista.
     */
    sl.insert(5, 0);
    sl.insert(6, 1);
    sl.insert(7, 2);
    sl.insert(8, 3);
    sl.insert(9, 4);
    
    int number = convertToInt(sl);
    cout << "Converted number: " << number << endl;

    int sum = recursiveSum(sl);
    if(sum == INT_MAX){
        cout << "List is empty!" << endl;
    }else {
        cout << "valor: " << sum << endl;
    }
   
    
    SinglyLinkedList<int> nl;
    sl.split(7, nl);
    int r1;
    // Imprime os elementos da nova lista: 
    cout << "==== ELEMENTOS DA NOVA LISTA ====" << endl;
    int num_elements = nl.numElements();
    for(int i = 0; i < num_elements; i++) {
        if(nl.get(i, r1) == 0)
            cout << r1 << " "; 
    }
    cout << "\n";
    
    // Imprime os elementos da primeira lista (lista corrente): 
    cout << "==== ELEMENTOS DA LISTA CORRENTE ====" << endl;
    num_elements = sl.numElements();
    for(int i = 0; i < num_elements; i++) {
        if(sl.get(i, r1) == 0)
            cout << r1 << " "; 
    }
    cout << "\n";


    DoublyLinkedList<int> dl; // Cria uma lista duplamente encadeada de tipo
                              // int
    dl.insert(1, 0);
    dl.insert(2, 1);
    dl.insert(3, 2);
    dl.insert(4, 3);
    dl.insert(5, 4);
    dl.insert(6, 5);

    // Imprime os elementos da lista dl antes de trocar os elementos: 
    cout << "==== ELEMENTOS DA LISTA DUPLAMENTE ENCADEADA ORIGINAL ====" << endl;
    num_elements = dl.numElements();
    int r2;
    for(int i = 0; i < num_elements; i++) {
        if(dl.get(i, r2) == 0)
            cout << r2 << " "; 
    }
    cout << "\n";

    dl.swap(1, 4); // Troca os elementos das posições 1 e 4

    // Imprime os elementos da lista dl depois de trocar os elementos: 
    cout << "==== ELEMENTOS DA LISTA DUPLAMENTE ENCADEADA DEPOIS DA TROCA ====" << endl;
    num_elements = dl.numElements();
    for(int i = 0; i < num_elements; i++) {
        if(dl.get(i, r2) == 0)
            cout << r2 << " "; 
    }
    cout << "\n\n";

    cout << "A lista está ordenada? ";
    if(isSorted(dl)) 
        cout << "Sim";
    else
        cout << "Não";
    cout << "\n";

    return 0;
}
