/**
 * Implementação de uma lista linear com armazenamento dinâmico, baseado em nós
 * com encadeamento nos dois sentidos (duplamente encadeado).
 */

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include "list.h"
#include "dnode.h"

using namespace std;

template <typename T>
class DoublyLinkedList: public List<T> {
    public:
        DNode<T>* head;
        DNode<T>* tail;
        int num_elements;

        DoublyLinkedList();
        int numElements();
        bool isEmpty();
        bool isFull();
        void insertFirst(T element);
        void insertLast(T element);
        int insert(T element, int pos);
        int removeFirst(T& result);
        int removeLast(T& result);
        int remove(int pos, T& result);
        int get(int pos, T& result);
        int search(const T& element);
        int swap(int pos1, int pos2); // Exercício 4
};

/**
 * Constrói uma lista inicialmente vazia.
 */
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    num_elements = 0;
}

template <typename T>
int DoublyLinkedList<T>::numElements() {
    return num_elements;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() {
    return num_elements == 0;
}

template <typename T>
bool DoublyLinkedList<T>::isFull() {
    // Uma lista com alocação dinâmica nunca está cheia.
    return false;
}

/**
 * Insere um novo elemento na posição inicial da lista.
 */
template <typename T>
void DoublyLinkedList<T>::insertFirst(T element) {
    // Cria um novo nó e o torna o novo "head"
    DNode<T>* new_node = new DNode<T>(element);
    
    if(isEmpty()) {
        head = new_node;
        tail = new_node;
    }
    else {
        new_node->setNext(head);
        head->setPrevious(new_node);
        head = new_node;
    }

    // Ajusta o total de elementos
    num_elements++;
}

/**
 * Insere um novo elemento no final da lista.
 */
template <typename T>
void DoublyLinkedList<T>::insertLast(T element) {
    //Cria um novo nó e o torna o "tail"
    DNode<T>* new_node = new DNode<T>(element);
    
    if(isEmpty()) {
        head = new_node;
        tail = new_node;
    }
    else {
        tail->setNext(new_node);
        new_node->setPrevious(tail);
        tail = new_node;
    }

    // Ajusta o total de elementos
    num_elements++;
}

/**
 * Retorna 1 se a posição informada não está correta.
 */
template <typename T>
int DoublyLinkedList<T>::insert(T element, int pos) {
    // Verifica se a posição lida é válida
    if(pos < 0 || pos > num_elements)
        return 1;

    // Casos especiais: inserção no início
    if(pos == 0)
        insertFirst(element);
    else { 
        if(pos == num_elements) // Inserção no final
            insertLast(element);
        else { // Inserção no meio da lista
            // Localiza o nó imediatamente anterior à posição onde o novo nó
            // será inserido
            DNode<T>* prev = head;
            for(int i = 0; i < pos - 1; i++)
                prev = prev->getNext();

            // Cria um novo nó e o posiciona logo após "prev", ajustando os
            // apontamentos e o total de elementos
            DNode<T>* new_node = new DNode<T>(element);
            new_node->setPrevious(prev);
            new_node->setNext(prev->getNext());
            prev->getNext()->setPrevious(new_node);
            prev->setNext(new_node);
            num_elements++;
        }
    }

    return 0;
}

/**
 * Remove o primeiro elemento da lista.
 * Retorna 0 se o elemento existir na lista.
 * Retorna 3 se a lista estiver vazia.
 */
template <typename T>
int DoublyLinkedList<T>::removeFirst(T& result) {
    if(isEmpty())
        return 3;

    // Guarda a referência do elemento sendo removido
    result = head->getElement();

    // Se a lista possui um único elemento: head e tail = nullptr
    if(head == tail) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        // Senão, o segundo elemento será o head
        head = head->getNext();
        head->setPrevious(nullptr);
    }

    // Ajusta o total de elementos
    num_elements--;
    return 0;
}

/**
 * Remove o último elemento da lista.
 * Retorna 0 se o elemento existir na lista.
 * Retorna 3 se a lista estiver vazia.
 */
template <typename T>
int DoublyLinkedList<T>::removeLast(T& result) {
    if(isEmpty())
        return 3;

    // Guarda uma referência do elemento sendo removido
    result = tail->getElement();

    // Se a lista possui um único elemento: head e tail = nullptr
    if(head == tail) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        // Senão, o penúltimo elemento passa a ser o "tail"
        tail = tail->getPrevious();
        tail->setNext(nullptr);
    }

    // Ajusta o total de elementos
    num_elements--;
    return 0;
}


/**
 * Remove um elemento de uma posição específica da lista.
 * Retorna 0 indicando a remoção do elemento da lista.
 * Retorna 1 se a posição informada não estiver correta.
 */
template <typename T>
int DoublyLinkedList<T>::remove(int pos, T& result) {
    if(pos < 0 || pos >= num_elements)
        return 1;

    if(pos == 0)
        removeFirst(result);
    else {
        if(pos == num_elements - 1)
            removeLast(result);
        else { // Remoção do meio da lista
            // Localiza o nós imediatamente anterior à posição de onde o
            // elemento será removido
            DNode<T>* prev = head;
            for(int i = 0; i < pos - 1; i++)
                prev = prev->getNext();

            // Guarda uma referência do elemento que será removido
            result = prev->getNext()->getElement();

            // Ajusta o encadeamento "pulando" o nó removido
            prev->setNext(prev->getNext()->getNext());
            prev->getNext()->setPrevious(prev);

            // Ajusta o total de elementos
            num_elements--;
        }
    }

    return 0;
}

/**
 * Busca um elemento de uma posição específica da lista.
 * Retorna 0 indicando a obtenção do elemento da lista.
 * Retorna 1 se a posição informada não estiver correta.
 */
template <typename T>
int DoublyLinkedList<T>::get(int pos, T& result) {
    if(pos < 0 || pos >= num_elements)
        return 1;

    DNode<T>* current = head;
    for(int i = 0; i < pos; i++)
        current = current->getNext();

    result = current->getElement();

    return 0;
}

template <typename T>
int DoublyLinkedList<T>::search(const T& element) {
    // Percorre o encadeamento até encontrar o elemento
    DNode<T>* current = head;
    
    int i = 0;
    while(current != nullptr) {
        if(element == current->getElement())
            return i;
        i++;
        current = current->getNext();
    }

    // Se chegar até aqui, o elemento não foi encontrado
    return -1;
}

template <typename T>
int DoublyLinkedList<T>::swap(int pos1, int pos2) {
    T r1, r2;
    
    if(pos2 < pos1 || pos2 >= num_elements || pos1 < 0)
        return 1;

    remove(pos1, r1);
    remove(pos2 - 1, r2);
    insert(r2, pos1);
    insert(r1, pos2);

    return 0;
}



#endif
