/**
 * Implementação de uma lista linear com armazenamento dinâmico, baseado em nós
 * com encadeamento em um único sentido (simplesmente encadeado).
 */

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>
#include "list.h"
#include "node.h"

using namespace std;

template <typename T>
class SinglyLinkedList: public List<T> {
    protected:
        Node<T>* head;
        Node<T>* tail;
        int num_elements;
    public:
        SinglyLinkedList();
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
};

/**
 * Constrói uma lista inicialmente vazia.
 */
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
    head = nullptr;
    tail = nullptr;
    num_elements = 0;
}

template <typename T>
int SinglyLinkedList<T>::numElements() {
    return num_elements;
}

template <typename T>
bool SinglyLinkedList<T>::isEmpty() {
    return num_elements == 0;
}

template <typename T>
bool SinglyLinkedList<T>::isFull() {
    // Uma lista com alocação dinâmica nunca está cheia.
    return false;
}

/**
 * Insere um novo elemento na posição inicial da lista.
 */
template <typename T>
void SinglyLinkedList<T>::insertFirst(T element) {
    // Cria um novo nó e o torna o novo "head"
    Node<T>* new_node = new Node<T>(element);
    
    if(isEmpty()) {
        head = new_node;
        tail = new_node;
    }
    else {
        new_node->setNext(head);
        head = new_node;
    }

    // Ajusta o total de elementos
    num_elements++;
}

/**
 * Insere um novo elemento no final da lista.
 */
template <typename T>
void SinglyLinkedList<T>::insertLast(T element) {
    //Cria um novo nó e o torna o "tail"
    Node<T>* new_node = new Node<T>(element);
    
    if(isEmpty()) {
        head = new_node;
        tail = new_node;
    }
    else {
        tail->setNext(new_node);
        tail = new_node;
    }

    // Ajusta o total de elementos
    num_elements++;
}

/**
 * Retorna 1 se a posição informada não está correta.
 */
template <typename T>
int SinglyLinkedList<T>::insert(T element, int pos) {
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
            Node<T>* prev = head;
            for(int i = 0; i < pos - 1; i++)
                prev = prev->getNext();

            // Cria um novo nó e o posiciona logo após "prev", ajustando os
            // apontamentos e o total de elementos
            Node<T>* new_node = new Node<T>(element);
            new_node->setNext(prev->getNext());
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
int SinglyLinkedList<T>::removeFirst(T& result) {
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
    }

    // Ajusta o total de elementos e retorna o removido
    num_elements--;
    return 0;
}

/**
 * Remove o último elemento da lista.
 * Retorna 0 se o elemento existir na lista.
 * Retorna 3 se a lista estiver vazia.
 */
template <typename T>
int SinglyLinkedList<T>::removeLast(T& result) {
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
        // Senão, necessário percorrer o encadeamento até chegar ao nó
        // imediatamente anterior ao último
        Node<T>* prev = head;
        while(prev->getNext() != tail)
            prev = prev->getNext();

        // Atualiza tail
        tail = prev;
        prev->setNext(nullptr);
    }

    // Ajusta o total de elementos e retorna o removido
    num_elements--;
    return 0;
}


/**
 * Remove um elemento de uma posição específica da lista.
 * Retorna 0 indicando a remoção do elemento da lista.
 * Retorna 1 se a posição informada não estiver correta.
 */
template <typename T>
int SinglyLinkedList<T>::remove(int pos, T& result) {
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
            Node<T>* prev = head;
            for(int i = 0; i < pos - 1; i++)
                prev = prev->getNext();

            // Guarda uma referência do elemento que será removido
            result = prev->getNext()->getElement();

            // Ajusta o encadeamento "pulando" o nó removido
            prev->setNext(prev->getNext()->getNext());

            // Ajusta o total de elementos e retorna o elemento removido
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
int SinglyLinkedList<T>::get(int pos, T& result) {
    if(pos < 0 || pos >= num_elements)
        return 1;

    Node<T>* current = head;
    for(int i = 0; i < pos; i++)
        current = current->getNext();

    result = current->getElement();

    return 0;
}

template <typename T>
int SinglyLinkedList<T>::search(const T& element) {
    // Percorre o encadeamento até encontrar o elemento
    Node<T>* current = head;
    
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

#endif
