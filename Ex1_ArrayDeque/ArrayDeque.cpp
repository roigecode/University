
/* 
 * File:   ArrayDeque.cpp
 * Author: Roige
 *
 * Created on 14 de marzo de 2021, 20:19
 */

#include <cstdlib>
#include <iostream>
#include "ArrayDeque.h"
#include <vector>

using namespace std;

ArrayDeque::ArrayDeque(const int mida) {
    _max_size = mida;
    this->_front = 0;
    this->_rear = 0;
    this->_size = 0;
    this->_data.resize(_max_size);
    cout << "\n Estructura creada (mida: "<<mida <<")" << endl << endl;
}

void ArrayDeque::enqueueBack(const int key) {
    if (!isFull()) {
        _rear = (_rear + 1) % _max_size;
        _data[_rear] = key;
        _size++;
//        this->print();
        cout << "Element " << key << " agregat" << endl << endl;
    } else {
        throw out_of_range("EXCEPTION: L'estructura està buida!\n\n");
    }
}

void ArrayDeque::enqueueFront(const int key) {
    if (isFull())
        throw out_of_range("EXCEPTION: L'estructura està plena!\n\n");
    _data[_front] = key;
    _size++;
    _front--;
    /**
     * La instrucción _front = (_front-1) % _max_size; me da error ya que no sé 
     * porque la operación (-1 % 3) que deberia dar 2, me da -1:
     */
    if (_front == -1)
        _front = _max_size - 1;

    cout << "Element " << key << " agregat" << endl << endl;
//    this->print();
}

void ArrayDeque::dequeueFront() {
    if (isEmpty()) {
        throw out_of_range("EXCEPTION: L'estructura està buida!\n\n");
    } else {
        cout << "Element " << _data[(_front + 1) % _max_size] << " eliminat" << endl << endl;
        _data[(_front + 1) % _max_size] = 0; // NO necessari però més net.
        _front = (_front + 1) % _max_size;
        _size--;
    }
//    this->print();
}

void ArrayDeque::dequeueBack() {
    if (isEmpty()) {
        throw out_of_range("EXCEPTION: L'estructura està buida!\n\n");
    } else {
        cout << "Element " << _data[_rear] << " eliminat" << endl << endl;
        _data[_rear] = 0; // NO necessari però més net.
        _rear--;
        _size--;

        // Idem, error con el modulo -1%3 da -1 y no 2:
        if (_rear == -1)
            _rear = _max_size - 1;
    }
//    this->print();
}

const int ArrayDeque::getFront() {
    if (isEmpty()) {
        throw out_of_range("EXCEPTION: L'estructura està buida!\n\n");
    } else {
        return _data[(_front + 1) % _max_size];
    }
}

const int ArrayDeque::getBack() {
    if (isEmpty()) {
        throw out_of_range("EXCEPTION: L'estructura està buida!\n\n");
    } else {
        return _data[_rear];
    }
}

bool ArrayDeque::isFull() {
    return _size == _max_size;
}

bool ArrayDeque::isEmpty() {
    return _size == 0;
}

void ArrayDeque::print() {

//    cout << "Array NO circular: ";
//    for (unsigned i = 0; i < _max_size; i++) {
//        cout << _data[i] << " ";
//    }
//    cout << "Front: " << _front;
//    cout << " Rear: " << _rear;
//    cout << " Size: " << _size;
//    cout << " Front+1 % 3 = " << ((_front + 1) % 3);
//    cout << "\n";

    int coma = 0;
    if (isEmpty()) {
        cout << "[]\n\n";
    } else {
        cout << "[";
        
        //        CASOS RAROS CUANDO _front=2 y _max_size=3
        //        ya que solo imprime un elemento porque hace 1 iteracion
        //
        //        int coma = 0;
        //        for (unsigned i = (_front + 1) % _max_size; i <= _max_size; i++) {
        //            if (_data[i] != 0 && coma != 0) {
        //                cout << "," << _data[i];
        //            } else {
        //                if (_data[i] != 0) {
        //                    cout << _data[i];
        //                }
        //                coma++;
        //            }
        //        }

        
        // SEPARADO POR CASOS SECUENCIALES, NO ANIDADOS:
        
        for (unsigned i = _front+1; i < _max_size; i++) {
            if (_data[i] != 0 && coma != 0) {
                        cout << "," << _data[i];
                    } else {
                        if (_data[i] != 0) {
                            cout << _data[i];
                        }
                        coma++;
                    }
        }
        
        for(unsigned i = 0; i<=_front;i++){
            if (_data[i] != 0 && coma != 0) {
                        cout << "," << _data[i];
                    } else {
                        if (_data[i] != 0) {
                            cout << _data[i];
                        }
                        coma++;
                    }
        }
        cout << "]\n\n";
    }


}

