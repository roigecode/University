
/* 
 * File:   ArrayDeque.h
 * Author: Roige
 *
 * Created on 14 de marzo de 2021, 20:06
 */

#ifndef ARRAYDEQUE_H
#define ARRAYDEQUE_H

#include <vector>

class ArrayDeque {
public:
    ArrayDeque(const int);
    void enqueueBack(const int);
    void enqueueFront(const int);
    void dequeueFront();
    void dequeueBack();
    const int getFront();
    const int getBack();
    bool isFull();
    bool isEmpty();
    void print();
private:
    int _front;
    int _rear;
    int _max_size;
    int _size;
    std::vector<int> _data;
};

#endif /* ARRAYDEQUE_H */

