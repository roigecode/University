/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AVL.h
 * Author: Roige
 *
 * Created on 13 de mayo de 2021, 22:58
 */

#ifndef AVL_H
#define AVL_H
#include "BinarySearchTree.h"

using namespace std;

template <class K, class V>
class AVL : public BinarySearchTree<K, V> {
public:
    AVL();
    AVL(const AVL& orig);
    virtual ~AVL();
    BinaryTreeNode<K, V>* add(const K& k, const V& value);
private:
    void right_rotation(BinaryTreeNode<K, V> * n);
    void left_rotation(BinaryTreeNode<K, V> * n);
    void update(BinaryTreeNode<K, V>* n);
    void check_status_rotations(BinaryTreeNode<K, V>* n);
};

template <class K, class V>
AVL<K, V>::AVL() {

}

template <class K, class V>
AVL<K, V>::AVL(const AVL& orig) {

}

template <class K, class V>
AVL<K, V>::~AVL() {

}

//     n                               x
//    / \     Right Rotation          /  \
//   x   T3   - - - - - - - >        T1   n 
//  / \       < - - - - - - -            / \
// T1  T2     Left Rotation            T2  T3

template <class K, class V>
void AVL<K, V>::right_rotation(BinaryTreeNode<K, V> * n) {

    //cout << "RR:" <<n->getKey()<<endl;

    if (!n->isRoot()) {
        if (n->getParent()->getLeft() == n)
            n->getParent()->setLeft(n->getLeft());
        else
            n->getParent()->setRight(n->getLeft());
    } else
        this->_root = n->getLeft();
    n->getLeft()->setParent(n->getParent());
    n->setParent(n->getLeft());
    n->setLeft(n->getLeft()->getRight());
    if (n->getLeft() != nullptr)
        n->getLeft()->setParent(n);
    n->getParent()->setRight(n);

    //    OLD TRY NO FER CAS ERROR PUNTERS NO PARENT UPDATE:
    //
    //    BinaryTreeNode<K, V> *x;
    //    BinaryTreeNode<K, V> *T2;
    //
    //    if (n->hasLeft())
    //        x = n->getLeft();
    //    else
    //        x = nullptr;
    //
    //    if (x->hasRight())
    //        T2 = x->getRight();
    //    else
    //        T2 = nullptr;
    //
    //    // Rotem:
    //    if (n->getParent() != nullptr)
    //        x->setParent(n->getParent());
    //    else
    //        x->setParent(nullptr);
    //
    //    if (n != nullptr)
    //        x->setRight(n);
    //    else
    //        x->setRight(nullptr);
    //
    //    n->setParent(x);
    //    n->setLeft(T2);
    //
    //    //Actualitzem heights:
    //    n->setHeight(1 + max(n->getLeft()->getHeight(), n->getRight()->getHeight()));
    //    x->setHeight(1 + max(x->getLeft()->getHeight(), x->getRight()->getHeight()));
    //
    //    // Retornem el nou root:
    //    return x;
}

//   z                                y
//  /  \                            /   \ 
// T1   y     Left Rotate(z)       z      x
//     /  \   - - - - - - - ->    / \    / \
//    T2   x                     T1  T2 T3  T4
//        / \
//      T3  T4

template <class K, class V>
void AVL<K, V>::left_rotation(BinaryTreeNode<K, V>* n) {

    //cout<<"LR: "<<n->getKey()<<endl;
    
    if (!n->isRoot()) {
        if (n->getParent()->getLeft() == n)
            n->getParent()->setLeft(n->getRight());
        else
            n->getParent()->setRight(n->getRight());
    } else
        this->_root = n->getRight();
    n->getRight()->setParent(n->getParent());
    n->setParent(n->getRight());
    n->setRight(n->getRight()->getLeft());
    if (n->getRight() != nullptr)
        n->getRight()->setParent(n);
    n->getParent()->setLeft(n);

    // OLD TRY NO FER CAS ERROR PUNTERS NO PARENT UPDATE:
    //    BinaryTreeNode<K, V>* y = x->getRight();
    //    BinaryTreeNode<K, V>* T2 = y->getLeft();
    //
    //    //Rotem:
    //    y->setLeft(x);
    //    x->setRight(T2);
    //
    //    // Actualitzem heights:
    //    x->setHeight(1 + max(x->getLeft()->getHeight(), x->getRight()->getHeight()));
    //    y->setHeight(1 + max(y->getLeft()->getHeight(), y->getRight()->getHeight()));
    //
    //    // Retornem el nou root:
    //    return y;
}

template <class K, class V>
void AVL<K, V>::update(BinaryTreeNode<K, V>* n) {
    
    //cout << "UPDATE: " << n->getKey() << endl;
    
    if (n->hasLeft() && n->hasRight()) {
        n->setHeight(max(n->getLeft()->getHeight(), n->getRight()->getHeight()) + 1);
        n->setFDB(n->getLeft()->getHeight() - n->getRight()->getHeight());
    } else if (n->hasLeft()) {
        n->setHeight(n->getLeft()->getHeight() + 1);
        n->setFDB(n->getLeft()->getHeight());
    } else if (n->hasRight()) {
        n->setHeight(n->getRight()->getHeight() + 1);
        n->setFDB(-n->getRight()->getHeight());
    } else {
        n->setHeight(1);
        n->setFDB(0);
    }
    if (n->getFDB() == -2) {
        if (n->getRight()->getFDB() == 1) {
            right_rotation(n->getRight());
        }
        left_rotation(n);
        check_status_rotations(this->_root);
    } else if (n->getFDB() == 2) {
        if (n->getLeft()->getFDB() == -1) {
            left_rotation(n->getLeft());
        }
        right_rotation(n);
        check_status_rotations(this->_root);
    }
    if (!n->isRoot())
        update(n->getParent());


    //    OLD TRY NO FER CAS ERROR PUNTERS NO PARENT UPDATE:
    //    int fdb;
    //    // 2. Actualitzem el height :
    //
    //    if (n->hasLeft() && n->hasRight()) {
    //        n->setHeight(1 + max(n->getLeft()->getHeight(), n->getRight()->getHeight()));
    //        fdb = n->getFDB();
    //    } else if (n->hasLeft()) {
    //        n->setHeight(1 + n->getLeft()->getHeight());
    //        fdb = n->getLeft()->getHeight();
    //    } else if (n->hasRight()) {
    //        n->setHeight(n->getRight()->getHeight() + 1);
    //        fdb = (-n->getRight()->getHeight());
    //    } else {
    //        n->setHeight(1);
    //        fdb = 0;
    //    }
    //
    //
    //    // 4. Si existeix desbalanceig només hi ha 4 casos:
    //
    //    // 4.1: Left Left Case:
    //    if (fdb > 1 && key > n->getRight()->getKey())
    //        return right_rotation(n);
    //
    //    // 4.2: Right Right Case:
    //    if (fdb < -1 && key > n->getRight()->getKey())
    //        return left_rotation(n);
    //
    //    // 4.3: Left Right Case:
    //    if (fdb > 1 && key > n->getLeft()->getKey()) {
    //        n->setLeft(left_rotation(n->getLeft()));
    //        return right_rotation(n);
    //    }
    //
    //    // 4.4: Right Left Case:
    //    if (fdb < -1 && key < n->getRight()->getKey()) {
    //        n->setRight(right_rotation(n->getRight()));
    //        return left_rotation(n);
    //    }
    //
    //    // Retornem el punter (sense modificar) de node
    //    if (!n->isRoot())
    //        update(n->getParent(), n->getParent()->getKey());
    //    return n;
}

template <class K, class V>
void AVL<K, V>::check_status_rotations(BinaryTreeNode<K, V> * n) {
    
    //cout<<"CER:"<<n->getKey()<<endl;
    
    if (n->hasLeft()) {
        check_status_rotations(n->getLeft());
    }
    if (n->hasRight()) {
        check_status_rotations(n->getRight());
    }
    if (n->isLeaf()) {
        n->setHeight(1);
        n->setFDB(0);
    } else {
        if (n->hasLeft() && n->hasRight()) {
            n->setHeight(max(n->getLeft()->getHeight(), n->getRight()->getHeight()) + 1);
            n->setFDB(n->getLeft()->getHeight() - n->getRight()->getHeight());
        } else if (n->hasLeft()) {
            n->setHeight(n->getLeft()->getHeight() + 1);
            n->setFDB(n->getLeft()->getHeight());
        } else if (n->hasRight()) {
            n->setHeight(n->getRight()->getHeight() + 1);
            n->setFDB(-n->getRight()->getHeight());
        }
    }
}

template <class K, class V>
BinaryTreeNode<K, V>* AVL<K, V>::add(const K& k, const V& value) {
    // 1.- Afegim com a un BST normal:
    BinaryTreeNode<K, V>* n = BinarySearchTree<K, V>::add(k, value);
    // Actualitzem l'estat del AVL:
    update(n);
    return n;
}

#endif /* AVL_H */