
/* 
 * File:   BinaryTreeNode
 * Author: Roige
 *
 * Created on 8 de mayo de 2021, 22:33
 */

#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
#include <vector>
using namespace std;

/*-----------------------------------------------------------------------------
 * COST TEORIC DELS FUNCIONS:
 * ----------------------------------------------------------------------------
 * Position(constructor amb paràmetre):= O(1)
 * Position(constructor copia)        := O(n) on n = nombre d'elements a orig
 * ~Position                          := O(n) on n = nombre d'elements a l'arbre
 * depth                              := O(n) worst case, O(log(n)) casos normals
 * height                             := O(n) worst case, O(log(n)) casos normals
 * getKey                             := O(1)
 * getValues                          := O(1)
 * parent                             := O(1)
 * left                               := O(1)
 * right                              := O(1)
 * setParent                          := O(1)
 * setLeft                            := O(1)
 * setRight                           := O(1)
 * isRoot                             := O(1)
 * isLeaf                             := O(1)
 * addValue                           := O(1)
 * operator==                         := O(1)
 * ----------------------------------------------------------------------------
 */

template <class K, class V>
class BinaryTreeNode {
public:
    BinaryTreeNode(const K& key);
    BinaryTreeNode(const BinaryTreeNode<K, V>& orig);
    virtual ~BinaryTreeNode();

    /* Modificadors */
    // Declareu-hi aquí els modificadors (setters) dels atributs que manquen
    void setKey(K& key);
    void setValues(vector<V> values);
    void setParent(BinaryTreeNode<K, V>* parent);
    void setRight(BinaryTreeNode<K, V>* right);
    void setLeft(BinaryTreeNode<K, V>* left);

    /* Consultors */
    const K& getKey() const;
    const vector<V>& getValues() const;
    // Declareu-hi aquí els consultors (getters) dels atributs que manquen
     BinaryTreeNode* getParent() const;
     BinaryTreeNode* getRight() const;
     BinaryTreeNode* getLeft() const;

    /* Operacions */
    bool isRoot() const;
    bool hasLeft() const;
    bool hasRight() const;
    bool isLeaf() const;

    void addValue(const V& v);
    int depth() const;
    int height() const; // uses auxiliary attribute
    bool operator==(const BinaryTreeNode<K, V>& node) const;

private:
    K _key;
    vector<V> _values;
    // Afegiu-hi aquí els atributs que manquen
    BinaryTreeNode* _parent;
    BinaryTreeNode* _right;
    BinaryTreeNode* _left;
};


// Constructor con parámetros
template <class K, class V>
BinaryTreeNode<K,V>::BinaryTreeNode(const K& key) {
    this->_key = key;
    this->_parent = nullptr;
    this->_right = nullptr;
    this->_left = nullptr;
}

// Constructor copia
template <class K, class V>
BinaryTreeNode<K,V>::BinaryTreeNode(const BinaryTreeNode<K, V>& orig):BinaryTreeNode(orig._key) {
    // Copiem key (cridem al constructor) i value
    this->_values = orig._values;
    // Si té fill esquerra fem crida recursiva del constructor copia
    if (orig._left != nullptr) {
        this->_left = new BinaryTreeNode<K, V>(*orig._left);
        this->_left->setParent(this);
    }
    // Si té fill dret fem crida recursiva del constructor copia
    if (orig._right != nullptr) {
        this->_right = new BinaryTreeNode<K, V>(*orig._right);
        this->_right->setParent(this);
    }
}

//Destructor
template <class K, class V>
BinaryTreeNode<K,V>::~BinaryTreeNode() {
cout << "Destruint " << this->_key << "\n";
     // Eliminem els fills, d'aquesta manera a BST podrem fer 'delete root'
    delete _left;
    delete _right;
}

/*Modificadors*/
template <class K, class V>
void BinaryTreeNode<K,V>::setKey(K& key) {
    this->_key = key;
}

template <class K, class V>
void BinaryTreeNode<K,V>::setValues(vector<V> values) {
    // Vector té asignat l'operador '=' per copies
    this->_values = values;
}

template <class K, class V>
void BinaryTreeNode<K,V>::setParent(BinaryTreeNode<K, V>* parent) {
    this->_parent = parent;
}

template <class K, class V>
void BinaryTreeNode<K,V>::setRight(BinaryTreeNode<K, V>* right) {
    this->_right = right;
}

template <class K, class V>
void BinaryTreeNode<K,V>::setLeft(BinaryTreeNode<K, V>* left) {
    this->_left = left;
}

/*Consultors*/
template <class K, class V>
const K& BinaryTreeNode<K,V>::getKey() const {
    return this->_key;
}

template <class K, class V>
const vector<V>& BinaryTreeNode<K,V>::getValues() const {
    return _values;
}

template <class K, class V>
 BinaryTreeNode<K,V>* BinaryTreeNode<K,V>::getParent() const {
    return _parent;
}

template <class K, class V>
 BinaryTreeNode<K,V>* BinaryTreeNode<K,V>::getRight() const {
    return _right;
}

template <class K, class V>
 BinaryTreeNode<K,V>* BinaryTreeNode<K,V>::getLeft() const {
    return _left;
}

/*Operacions*/
template <class K, class V>
bool BinaryTreeNode<K,V>::isRoot()const {
    return this->_parent = nullptr;
}

template <class K, class V>
bool BinaryTreeNode<K,V>::hasLeft() const {
    return this->_left == nullptr;
}

template <class K, class V>
bool BinaryTreeNode<K,V>::hasRight() const {
    return this->_right == nullptr;
}

template <class K, class V>
bool BinaryTreeNode<K,V>::isLeaf() const {
    return (this->_right == nullptr && this->_left==nullptr);
}

template <class K, class V>
void BinaryTreeNode<K,V>::addValue(const V& v) {
    this->_values.push_back(v);
}

template <class K, class V>
int BinaryTreeNode<K,V>::depth() const {
    // Cas Base
    if (this->isRoot())
        return 0;
    else
        return 1 + _parent->depth();
}

template <class K, class V>
int BinaryTreeNode<K,V>::height() const {
    // Cas 0 - Base: un node fulla té height = 1
    if (this->isLeaf())
        return 1;
    //Cas 1: Té dos fills: calculem l'alçada màxima dels dos fills + 1
    else if (_left != nullptr && _right != nullptr)
        return 1 + max(_left->height(), _right->height());
    //Cas 2: Només té fill dret:
    else if (_left == nullptr) 
        return _right->height() + 1;    
    //Cas 3: Només té fill esquerra
    else
        return _left->height() + 1;
}

template <class K, class V>
bool BinaryTreeNode <K, V>::operator ==(const BinaryTreeNode<K,V>& node) const{
    // Dos nodes són iguals sii la seva key i els seus values son iguals
    return this->_key == node._key && this->_values == node._values;
}

#endif	// BINARYTREENODE_H

