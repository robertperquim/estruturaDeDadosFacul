/* Implementação de uma lista linear com armazenamento estático 
 * usando vetor (array unidimensional).
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include <iostream>
#include "list.h"

using namespace std;

template <typename T>
class StaticList: public List<T> {
    protected:
        // Array que armazena as referências para os elementos
        T* elements;

        // Tamanho da lista
        int size;

        // Quantidade de elementos armazenados na lista
        int num_elements;
    public:
        /**
         * Constrói uma lista com tamanho máximo.
         */
        StaticList(int max_size);

        int numElements();
        bool isEmpty();
        bool isFull();
        int insert(T element, int pos);
        int remove(int pos, T& result);
        int get(int pos, T& result);
        int search(const T& element);
        int dedup();
        int remove_interval(int begin, int end);
};

template <typename T>
StaticList<T>::StaticList(int max_size) {
    elements = new T[max_size];
    size = max_size;
    num_elements = 0;
}

template <typename T>
int StaticList<T>::numElements() {
    return num_elements;
}

template <typename T>
bool StaticList<T>::isEmpty() {
    return num_elements == 0;
}

template <typename T>
bool StaticList<T>::isFull() {
    return num_elements == size;
}

/**
 * Retorna 0 se o elemento foi inserido na lista.
 * Retorna 1 se a posição informada não está correta.
 * Retorna 2 se a lista estiver cheia.
 */
template <typename T>
int StaticList<T>::insert(T element, int pos) {
    if(isFull())
        return 2;
    else {
        if(pos < 0 || pos > num_elements)
            return 1;
                
        for(int i = num_elements - 1; i >= pos; i--)
            elements[i+1] = elements[i];

        elements[pos] = element;
        num_elements++;

        return 0;
    }
}

/**
 * Retorna 0 se o elemento foi removido da lista.
 * Retorna 1 se a posição informada não está correta.
 * Retorna 3 se a lista estiver vazia.
 */
template <typename T>
int StaticList<T>::remove(int pos, T& result) {
    if(isEmpty())
        return 3;
    else {
        if(pos < 0 || pos >= num_elements)
            return 1;
        else {
            result = elements[pos];

            for(int i = pos; i < num_elements - 1; i++)
                elements[i] = elements[i+1];

            num_elements--;

            return 0;
        }
    }
}


/**
 * Retorna 0 se o elemento existe na lista.
 * Retorna 1 se a posição informada não está correta.
 * Retorna 3 se a lista estiver vazia.
 */
template <typename T>
int StaticList<T>::get(int pos, T& result) {
    if(isEmpty())
        return 3;
    else {
        if(pos < 0 || pos >= num_elements)
            return 1;
        else {
            result = elements[pos];
            return 0;
        }
    }
}


/**
 * Implementação funciona para os tipos: int, float, double, char e string
 */
template <typename T>
int StaticList<T>::search(const T& element) {
    for(int i = 0; i < num_elements; i++)
        if(element == elements[i])
            return i;

    return -1;
}

/**
 * Exercício 1
 * Remove ocorrências múltiplas de elementos na lista.
 * Retorna 0 se removeu pelo menos um elemento repetido.
 * Retorna -1 se não há elemenos repetidos.
 */
template <typename T>
int StaticList<T>::dedup(){
    bool removed = false;

    if (!isEmpty())
    {
        T result;
        for (int i = 0; i < num_elements; i++)
        {
            for (int j = i + 1; j < num_elements; j++)
            {
                if (elements[i] == elements[j])
                {
                    if (remove(j, result) == 0 )
                    {
                        cout << "Removed element: " << result << endl;
                        removed = true;
                        j--;
                    }
                    
                }
                
            }
            
        }
        
    }

    if (removed)
    {
        return 0;
    }else
    {
        return -1;
    }
    
}


template <typename T>
int StaticList<T>::remove_interval(int begin, int end){
    if(isEmpty())
    {
        return 3;
    }else{
        if (begin < 0 || end >= num_elements || begin > end)
        {
            return 1;
        }
        
        T result ;

        int defferece = end - begin + 1;
        int count = 0;

        while (count < defferece)
        {
            remove(begin, result);
            cout << "Removed element: " << endl;
            count++;
        }
        
        return 0; 
    }

}



#endif
