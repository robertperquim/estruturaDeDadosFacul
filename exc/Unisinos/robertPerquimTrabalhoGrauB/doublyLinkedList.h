//ROBERT PERQUIM Eu não encontrei uma dupla sora

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <iostream>
#include <iomanip>
#include "list.h"
#include "dNode.h"
using namespace std;
template <typename T>
class DoublyLinkedList: public List<T> {
    protected:
        DNode<T>* inicio;
        DNode<T>* fim;
        int num_elementos;
    public:
        DoublyLinkedList();
        int numElements();
        bool isEmpty();
        bool isFull();
        void insertFirst(T elemento);
        void insertLast(T elemento);
        int insert(T elemento, int pos);
        int removeFirst(T& resultado);
        int removeLast(T& resultado);
        int remove(int pos, T& resultado);
        int get(int pos, T& resultado);
        int search(const T& elemento);
        void printDetailedList() const; // sora adicionei este novo metodo para visualizar o encademento da lista de forma visual.
};


template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    inicio = nullptr;
    fim = nullptr;
    num_elementos = 0;
}

template <typename T>
int DoublyLinkedList<T>::get(int pos, T& resultado) {
    if (pos < 0 || pos >= num_elementos)
        return 1;
    DNode<T>* atual = inicio;
    for (int i = 0; i < pos; i++)
        atual = atual->getNext();
    resultado = atual->getElement();
    return 0;
}

template <typename T>
int DoublyLinkedList<T>::search(const T& elemento) {
    DNode<T>* atual = inicio;
    int i = 0;
    while (atual != nullptr) {
        if (elemento == atual->getElement())
            return i;
        i++;
        atual = atual->getNext();
    }
    return -1;
}

template <typename T>
int DoublyLinkedList<T>::numElements() {
    return num_elementos;
}


template <typename T>
bool DoublyLinkedList<T>::isEmpty() {
    return num_elementos == 0;
}


template <typename T>
bool DoublyLinkedList<T>::isFull() {
    return false;
}

template <typename T>
int DoublyLinkedList<T>::insert(T elemento, int pos) {
    if (pos < 0 || pos > num_elementos)
        return 1;
    if (pos == 0) // se for 0 sera uma insercao no inicio 
        insertFirst(elemento);
    else if (pos == num_elementos) // se for igual ao num de elementos sera uma isercao no fim 
        insertLast(elemento);
    else { // se chegar aqui sera uma insercao no moeio de dois elementos 
        DNode<T>* novo_no = new DNode<T>(elemento); // crio um novo no para o novo elemento 

        DNode<T>* atual = inicio; // criamos um novo no e atribuimos o inicio para ele 

        for (int i = 0; i < pos; i++)
            atual = atual->getNext(); // interamos na lista ate chegar antes da posicao que queremos inserir pq o proximo do atual e onde queremos inserir 

        novo_no->setNext(atual); //seta o proximo do novo no para o atual 
        novo_no->setPrevious(atual->getPrevious()); // seta o anterior do novo no com o anterior do atual 
        atual->getPrevious()->setNext(novo_no); // seta o proximo do anterior do atual com o novo no 
        atual->setPrevious(novo_no); // seta o anteriro do atual com o novo no 
        num_elementos++; // atualiza o num de elementos 
    }
    return 0;
}



template <typename T>
void DoublyLinkedList<T>::insertLast(T elemento) {
    // crio um novo no 
    DNode<T>* novo_no = new DNode<T>(elemento);
    // se a lista estiver vazia essa nova inserção sera o inico da lista 
    if (isEmpty()) {
        inicio = novo_no;
        fim = novo_no;
    } else { 
        //atualiza o proximo do fim para o novo 
        fim->setNext(novo_no);
        // seta o anteriror do novo no para o fim atual
        novo_no->setPrevious(fim);
        // atualiza o fim com o novo no 
        fim = novo_no;
    }
    //incrementamos o contador de elementos 
    num_elementos++;
}


template <typename T>
void DoublyLinkedList<T>::insertFirst(T elemento) {
    //crio um novo no 
    DNode<T>* novo_no = new DNode<T>(elemento);
    // se a lista estiver vazia essa nova inserção sera o inico da lista 
    if (isEmpty()) {
        inicio = novo_no;
        fim = novo_no;
    } else { // se nao 
        //atualizo o proximo do novo no para o incio da lista 
        novo_no->setNext(inicio);
        //atulizo o anterior do inicio para o novo no que esta sendo inserido 
        inicio->setPrevious(novo_no);
        //atualizo o inicio da lista com o novo no 
        inicio = novo_no;
    }
    //incrementamos o contador de elementos 
    num_elementos++;
}

template <typename T>
int DoublyLinkedList<T>::removeLast(T& resultado) {
    if (isEmpty())
        return 3;

    resultado = fim->getElement(); //guarda a referencia do no que qer ser removiddo 
    
    if (inicio == fim) {
        inicio = nullptr;
        fim = nullptr;
    } else {

        fim = fim->getPrevious(); // novo fim passa a ser o anterir do fim 
        fim->setNext(nullptr); // proximo do novo fim passa a ser null 
    }
    
    num_elementos--; // decrementa o num de elementos 
    return 0;
}



template <typename T>
int DoublyLinkedList<T>::removeFirst(T& resultado) {
    if (isEmpty())
        return 3;

    resultado = inicio->getElement(); // guarda a referencia do que vai ser removido 

    if (inicio == fim) { // se o a lista tiver apenas um elemento removemos ele com incio e fim igual a null 
        inicio = nullptr;
        fim = nullptr;
    } else {
        inicio = inicio->getNext(); // incio pssa a ser o proximo 
        inicio->setPrevious(nullptr); // anterior do novo incio passa a ser nil
    }
    num_elementos--; // atualiza o tamanho da lista 
    return 0;
}





template <typename T>
int DoublyLinkedList<T>::remove(int pos, T& resultado) {
    if (pos < 0 || pos >= num_elementos)
        return 1;

    if (pos == 0) // se a pos for zero sera uma remocao no inico 
        return removeFirst(resultado);

    else if (pos == num_elementos - 1) // sera uma remocao no fim 
        return removeLast(resultado);
    else {
        // aqui sera  uma remocao no meio de dois elementos 
        // criamos um no auxiliar e interamos ante antes da posicao que quremos remover 
        DNode<T>* atual = inicio;
        for (int i = 0; i < pos; i++)
            atual = atual->getNext();

        resultado = atual->getElement();  // guardamos a referencia do que sera removido 
        atual->getPrevious()->setNext(atual->getNext()); // atualizamos o proximo do anterior do atual para o proximo do atual 
        atual->getNext()->setPrevious(atual->getPrevious()); // atualizamos o anterior do proximo do atual com o anterior do atual 
        num_elementos--; // decrementamos o numero de elementos 
        return 0;
    }
}


// Adicionei esse novo metodo sora para visualizar o encademmento da lista de forma viasual 
template <typename T>
void DoublyLinkedList<T>::printDetailedList() const {
    DNode<T>* atual = inicio;
    cout << left << setw(10) << "Anterior" << " | " << setw(10) << "Atual" << " | " << setw(10) << "Próximo" << endl;
    cout << "----------------------------------------" << endl;
    while (atual != nullptr) { // percorro todo a lista ate o atual for null 
        if (atual->getPrevious() != nullptr)  // se o anterior do atual for diferente de null 
            cout << left << setw(10) << atual->getPrevious()->getElement() << " | "; //imprime o anterior do atual 
        else
            cout << left << setw(10) << "nullptr" << " | "; // se nao imprime null 
        cout << left << setw(10) << atual->getElement() << " | "; // imprime o atual 
        if (atual->getNext() != nullptr) // se o proximo do atual for diferente de null 
            cout << left << setw(10) << atual->getNext()->getElement(); // imprime o proximo do atual 
        else
            cout << left << setw(10) << "nullptr"; // se nao imprime null 
        cout << endl;
        atual = atual->getNext(); //atualiza o atual 
    }
    cout << endl;
}
#endif