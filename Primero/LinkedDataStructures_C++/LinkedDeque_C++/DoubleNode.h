/* 
 * File:   DoubleNode.h
 * Author: Roige
 *
 * Created on 21 de marzo de 2021, 23:32
 */

#ifndef DOUBLENODE_H
#define DOUBLENODE_H

template <class Elem>
class DoubleNode {
private:
    Elem _elem;
    DoubleNode<Elem>* _next;
    DoubleNode<Elem>* _prev;

public:
    DoubleNode();
    DoubleNode(Elem element);
    const Elem& getElement() const;
    void setElement(Elem elem);
    DoubleNode<Elem>* getNext() const;
    void setNext(DoubleNode<Elem>* node);
    DoubleNode<Elem>* getPrevious() const;
    void setPrevious(DoubleNode<Elem>* node);
};

template <class Elem>
DoubleNode<Elem>::DoubleNode() {
}

template <class Elem>
DoubleNode<Elem>::DoubleNode(Elem elem) {
    this->_elem = elem;
}

template <class Elem>
const Elem& DoubleNode<Elem>::getElement() const {
    return this->_elem;
}

template <class Elem>
void DoubleNode<Elem>::setElement(Elem elem) {
    this->_elem = elem;
}

template <class Elem>
DoubleNode<Elem>* DoubleNode<Elem>::getNext() const {
    return this->_next;
}

template <class Elem>
void DoubleNode<Elem>::setNext(DoubleNode<Elem>* node) {
    this->_next = node;
}

template <class Elem>
DoubleNode<Elem>* DoubleNode<Elem>::getPrevious() const {
    return this->_prev;
}

template <class Elem>
void DoubleNode<Elem>::setPrevious(DoubleNode<Elem>* node) {
    this->_prev = node;
}

#endif /* DOUBLENODE_H */