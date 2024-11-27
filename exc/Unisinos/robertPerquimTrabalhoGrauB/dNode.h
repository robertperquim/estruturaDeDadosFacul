//ROBERT PERQUIM Eu não encontrei uma dupla sora
#ifndef DNODE_H
#define DNODE_H

#include <iostream>

using namespace std;

template <typename T>
class DNode {
    protected:
        T elemento;
        DNode<T>* proximo;
        DNode<T>* anterior;
    public:
        DNode(T elemento);
        T getElement() const;
        void setElement(T elemento);
        DNode<T>* getNext() const;
        void setNext(DNode<T>* proximo);
        DNode<T>* getPrevious() const;
        void setPrevious(DNode<T>* anterior);
};

template <typename T>
DNode<T>::DNode(T elemento) {
    this->elemento = elemento;
    proximo = nullptr;
    anterior = nullptr;
}

template <typename T>
T DNode<T>::getElement() const {
    return elemento;
}

template <typename T>
void DNode<T>::setElement(T elemento) {
    this->elemento = elemento;
}

template <typename T>
DNode<T>* DNode<T>::getNext() const {
    return proximo;
}

template <typename T>
void DNode<T>::setNext(DNode<T>* proximo) {
    this->proximo = proximo;
}

template <typename T>
DNode<T>* DNode<T>::getPrevious() const {
    return anterior;
}

template <typename T>
void DNode<T>::setPrevious(DNode<T>* anterior) {
    this->anterior = anterior;
}

#endif