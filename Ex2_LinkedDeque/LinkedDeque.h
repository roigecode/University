
/* 
 * File:   DoubleNode.h
 * Author: Roige
 *
 * Created on 21 de marzo de 2021, 23:32
 */

#ifndef LINKEDDEQUE_H
#define LINKEDDEQUE_H

#include <iostream>
#include <stdexcept>
#include "DoubleNode.h"

using namespace std;

template <class Elem>
class LinkedDeque {
public:
    LinkedDeque();
    LinkedDeque(const LinkedDeque& orig);
    virtual ~LinkedDeque();
    void enqueueFront(Elem& elem);
    void enqueueBack(Elem& elem);
    void dequeueFront();
    void dequeueBack();
    const Elem& getFront();
    const Elem& getBack();
    bool isEmpty();
    int size();
    void print();
    // Mètode afegit per detectar si només hi ha un element
    // és útil ja que no s'implementen sentinelles:
    bool unic_Element();

private:
    int _size;
    DoubleNode<Elem>* _head;
    DoubleNode<Elem>* _rear;
};

template <class Elem>
LinkedDeque<Elem>::LinkedDeque() {
    this->_size = 0;
    this->_head = nullptr;
    this->_rear = nullptr;
    cout << "\n Estructura creada (mida: indefinida)\n" << endl;
}

template <class Elem>
LinkedDeque<Elem>::LinkedDeque(const LinkedDeque& orig) {

    // Caso 0: Copiar lista vacía:
    if (orig._head == nullptr) {
        _size = 0;
        _head = nullptr;
        _rear = nullptr;
    }        // Caso 1: Único elemento:
    else if (unic_Element()) {
        _head = new DoubleNode<Elem>(orig._head->getElement());
        _rear = new DoubleNode<Elem>(orig._rear->getElement());
        _head->setPrevious(nullptr);
        _head->setNext(_rear);
        _rear->setPrevious(_head);
        _rear->setNext(nullptr);
    }        // Caso n: Lista de 'n' elementos:
    else {
        _head = new DoubleNode<Elem>(orig._head->getElement());
        _rear = new DoubleNode<Elem>(orig._rear->getElement());
        _head->setPrevious(nullptr);
        _head->setNext(_rear);
        _rear->setPrevious(_head);
        _rear->setNext(nullptr);

        DoubleNode<Elem>* from = orig._head->getNext();
        DoubleNode<Elem>* to = _head;

        while (from != orig._rear) {
            to->setNext(new DoubleNode<Elem>(from->getElement()));
            to->getNext()->setPrevious(to);
            to->getNext()->setNext(_rear);
            _rear->setPrevious(to->getNext());
            from = from->getNext();
            to = to->getNext();
        }
    }
}

template <class Elem>
LinkedDeque<Elem>::~LinkedDeque() {
    cout << "       ...Destruint estructura..." << endl;
    DoubleNode<Elem>* temp;
    while (_head != nullptr && _head != _rear) {
        temp = _head;
        _head = _head->getNext();
        delete temp;
    }
    _head = nullptr;
    _rear = nullptr;
    _size = 0;

    cout << " >>> ¡Estructura destruida amb èxit! <<<" << endl;
}

template <class Elem>
bool LinkedDeque<Elem>::isEmpty() {
    return (_head == nullptr && _rear == nullptr);

}

template <class Elem>
bool LinkedDeque<Elem>::unic_Element() {
    return (_head == _rear && !isEmpty());
}

template <class Elem>
void LinkedDeque<Elem>::enqueueFront(Elem& elem) {
    DoubleNode<Elem>* node = new DoubleNode<Elem>(elem);

    if (isEmpty()) {
        node->setNext(nullptr);
        node->setPrevious(nullptr);
        _head = node;
        _rear = node;
    } else {
        node->setNext(_head);
        node->setPrevious(nullptr);
        _head->setPrevious(node);
        _head = node;
    }

    _size++;
    cout << "Element " << elem << " agregat\n" << endl;
}

template <class Elem>
void LinkedDeque<Elem>::enqueueBack(Elem& elem) {
    DoubleNode<Elem>* node = new DoubleNode<Elem>(elem);

    if (isEmpty()) {
        node->setNext(nullptr);
        node->setPrevious(nullptr);
        _head = node;
        _rear = node;
    } else {
        node->setNext(nullptr);
        node->setPrevious(_rear);
        _rear->setNext(node);
        _rear = node;

    }
    _size++;
    cout << "Element " << elem << " agregat\n" << endl;
}

template <class Elem>
void LinkedDeque<Elem>::dequeueFront() {
    if (isEmpty()) {
        throw out_of_range("EXCEPTION: L’estructura està buida");
    }

    // Creamos un pointer temporal para no dejar colgado a _head:
    DoubleNode<Elem>* temp = _head;
    Elem elem = temp->getElement();

    if (unic_Element()) {
        _head = nullptr;
        _rear = nullptr;
        delete temp;
    } else {
        _head = _head->getNext();
        _head->setPrevious(nullptr);
        delete temp;
    }

    _size--;
    cout << "Element " << elem << " eliminat\n" << endl;
}

template <class Elem>
void LinkedDeque<Elem>::dequeueBack() {
    if (isEmpty()) {
        throw out_of_range("EXCEPTION: L’estructura està buida");
    }

    // Creamos un pointer temporal para no dejar colgado a _rear:
    DoubleNode<Elem>* temp = _rear;
    Elem elem = temp->getElement();

    if (unic_Element()) {
        _head = nullptr;
        _rear = nullptr;
        delete temp;
    } else {
        _rear = _rear->getPrevious();
        _rear->setNext(nullptr);
        delete temp;
    }

    _size--;
    cout << "Element " << elem << " eliminat\n" << endl;
}

template<class Elem>
const Elem& LinkedDeque<Elem>::getFront() {
    if (_size != 0)
        return _head->getElement();
    else
        throw out_of_range("");
}

template<class Elem>
const Elem& LinkedDeque<Elem>::getBack() {
    if (_size != 0)
        return _rear->getElement();
    else
        throw out_of_range("");
}

template<class Elem>
int LinkedDeque<Elem>::size() {
    return _size;
}

template <class Elem>
void LinkedDeque<Elem>::print() {

    if (isEmpty())
        cout << "[]\n" << endl;
    else {
        cout << "[";
        DoubleNode<Elem>* aux = _head;
        while (aux->getNext() != nullptr) {
            cout << aux->getElement() << ",";
            aux = aux->getNext();
        }
        cout << aux->getElement() << "]\n" << endl;
    }
}


#endif /* LINKEDDEQUE_H */