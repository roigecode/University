
/* 
 * File:   BinarySeachTree.h
 * Author: Roige
 *
 * Created on 8 de mayo de 2021, 22:33
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <vector>
#include <stdexcept>
#include <iostream>

#include "BinaryTreeNode.h"
using namespace std;

/*-----------------------------------------------------------------------------
 * COST TEORIC DELS FUNCIONS:
 * ----------------------------------------------------------------------------
 *  BinarySearchTree()  :=  O(1) 
 *  BinarySearchTree()  :=  O(n)
 *  ~BinarySearchTree() :=  O(n)
 * 
 *  isEmpty()           :=  O(1)
 *  size()              :=  O(1)
 *  sizeRecursiu()      :=  O(n)
 *  height()            :=  O(1)
 *  getRoot()           :=  O(1)
 *  add()               :=  O(MASTER)
 *  has()               :=  O(n)
 *  valuesOf()          :=  O(1)       
 *  showKeysPreorder()  :=  O(MASTER)
 *  showKeysInorder()   :=  O(MASTER)
 *  showKeysPostorder() :=  O(MASTER)
 *  printNodesNivell()  :=  O(MASTER)
 * 
 *  equals()            :=  O()
 *  getLeafs()          :=  O()
 *  find()              :=  O()
 *
 *  _find()             :=  O()
 *  equalsAux()         :=  O()
 *  sizeRec()           :=  O()
 *  printNodesNivell()  :=  O()
 *  getLeafsAux()       :=  O()
 * ----------------------------------------------------------------------------
 */

template <class K, class V>
class BinarySearchTree {
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree<K, V>& orig);
    virtual ~BinarySearchTree();

    bool isEmpty() const;
    int size() const;
    int sizeRecursiu() const;
    int getHeight() const;
    BinaryTreeNode<K, V>* getRoot() const;

    BinaryTreeNode<K, V>* add(const K& k, const V& value);
    bool has(const K& k) const;
    const std::vector<V>& valuesOf(const K& k) const;

    void showKeysPreorder(const BinaryTreeNode<K, V>* n = nullptr) const;
    void showKeysInorder(const BinaryTreeNode<K, V>* n = nullptr) const;
    void showKeysPostorder(const BinaryTreeNode<K, V>* n = nullptr) const;
    void printNodesNivell(const int& nivell) const;

    bool equals(const BinarySearchTree<K, V>& other) const;
    const std::vector<BinaryTreeNode<K, V>*>& getLeafs() const;

protected:
    BinaryTreeNode<K, V>* _root;
    BinaryTreeNode<K, V>* find(const K& k) const;
    BinaryTreeNode<K,V>* findIter(const K& k) const;

private:
    int _size;
    // M??tode AUXILIAR recursiu per iterar l'arbre i trobar un node:
    BinaryTreeNode <K, V>* _find(const K& key, BinaryTreeNode <K, V>* node) const;
    // M??tode AUXILIAR per a comprovar si dos arbres s??n id??ntics
    bool equalsAux(const BinaryTreeNode<K, V>* node, const BinaryTreeNode<K, V>* node2) const;
    // Sobrec??rrega del m??tode p??blic sizeRec()
    int sizeRec(const BinaryTreeNode <K, V>* node) const;
    // Sobrec??rrega del m??tode printNodesNivell
    void printNodesNivell(int nivell, const BinaryTreeNode <K, V>* node) const;
    // M??tode auxiliar per obtenir les fulles d'un arbre
    const std::vector<BinaryTreeNode<K, V>*>& getLeafsAux(BinaryTreeNode<K, V>* n) const;
    // Auxiliar per leafs
    void getLeafs_aux(vector<BinaryTreeNode<K,V>*>& leafs, BinaryTreeNode<K,V>* node);
};

template <class K, class V>
BinarySearchTree<K, V>::BinarySearchTree() {
    _size = 0;
    _root = nullptr;
    cout << "BST creat" << endl;
}

template <class K, class V>
BinarySearchTree<K, V>::BinarySearchTree(const BinarySearchTree<K, V>& orig) {
    _size = orig._size;
    _root = new BinaryTreeNode<K, V>(*orig.getRoot());
    cout << "Arbre binari de cerca copiat\n" << endl;
}

template <class K, class V>
BinarySearchTree<K, V>::~BinarySearchTree() {
    cout << "Destruint BST" << endl;
    // Hem implementat a BinaryTreeNode el detructor recursivament:
    delete _root;
    cout << "BST destruit\n" << endl;
}

template <class K, class V>
bool BinarySearchTree<K, V>::isEmpty() const {
    return _root == nullptr;
}

template <class K, class V>
int BinarySearchTree<K, V>::size() const {
    return _size;
}

template <class K, class V>
int BinarySearchTree<K, V>::sizeRec(const BinaryTreeNode<K, V>* node) const {
    if (node == nullptr)
        return 0;
    else
        return 1 + sizeRec(node->getLeft()) + sizeRec(node->getRight());
}

template <class K, class V>
int BinarySearchTree<K, V>::sizeRecursiu() const {
    return sizeRec(_root);
}

template <class K, class V>
BinaryTreeNode<K, V>* BinarySearchTree<K, V>::getRoot() const {
    if (isEmpty())
        throw out_of_range("BST buit\n");
    return _root;
}

template <class K, class V>
int BinarySearchTree<K, V>::getHeight() const {
    if (this->isEmpty())
        throw out_of_range("BST buit\n");
    return _root->getHeight();
}

template <class K, class V>
BinaryTreeNode<K, V>* BinarySearchTree<K, V>::add(const K& k, const V& value) {
    
    BinaryTreeNode <K, V>* pos;
    if (this->isEmpty()) {
        // Creem un nou arbre i fem de k l'arrel:
        this->_root = new BinaryTreeNode<K, V>(k);
        this->_root->addValue(value);
        _size++;
        cout << "Element amb key: " << k << " inserit al BST" << endl;
        return this->_root;
    } else {
        BinaryTreeNode <K, V>* aux = _root;
        BinaryTreeNode <K, V>* aux2;

        while (aux != nullptr) {
            aux2 = aux;

            if (k < aux->getKey())
                aux = aux->getLeft();
                // Element major
            else if (k > aux->getKey())
                aux = aux->getRight();
                //Element repetit
            else
                aux = nullptr;
        }

        // Si k ??s menor li asignem el new node com a fill esquerra
        if (k < aux2->getKey()) {
            pos = new BinaryTreeNode<K, V>(k);
            pos->addValue(value);
            aux2->setLeft(pos);
            pos->setParent(aux2);
            _size++;
        }// Si k ??s major, new node ??s fill dret
        else if (k > aux2->getKey()) {
            pos = new BinaryTreeNode<K, V>(k);
            pos->addValue(value);
            aux2->setRight(pos);
            pos->setParent(aux2);
            _size++;
        }// Si existeix un element amb la mateixa key, actualitzem values
        else {
            pos = aux2;
            pos->addValue(value);
        }

        cout << "Element amb key: " << k << " inserit al BST" << endl;
        return pos;
    }
}

template <class K, class V>
bool BinarySearchTree<K, V>::has(const K& k) const {
    if (isEmpty())
        throw out_of_range("BST buit\n");
    bool trobat = false;
    BinaryTreeNode<K, V>* aux = this->_root;

    while (aux != nullptr && !trobat) {
        if (k < aux->getKey())
            aux = aux->getLeft();
        else if (k > aux->getKey())
            aux = aux.getRight();
        else
            trobat = true;
    }
    return trobat;
}

template <class K, class V>
const std::vector<V>& BinarySearchTree<K, V>::valuesOf(const K& k) const {
    BinaryTreeNode<K, V>* aux = find(k); //Node amb key k

    if (aux == nullptr)
        throw out_of_range("No existeix cap element amb key: " + to_string(k) + ".\n");
    else {
        // Print per casos de prova - cal mirar cas array dins array per arrays tridimensionals:
        // for(const auto& i: aux->getValues())
        //      cout<<i<<" ";
        return aux->getValues();
    }
}

template <class K, class V>
void BinarySearchTree<K, V>::showKeysPreorder(const BinaryTreeNode<K, V>* n) const {
    if (this->isEmpty())
        throw out_of_range("BST buit\n");
    // Cas Base:
    if (n == nullptr)
        showKeysPreorder(this->_root);
    else {
        // Preorder: VLR
        cout << n->getKey() << " "; // V

        if (n->getLeft() != nullptr)
            showKeysPreorder(n->getLeft()); // L
        if (n->getRight() != nullptr)
            showKeysPreorder(n->getRight()); // R
    }
}

template <class K, class V>
void BinarySearchTree<K, V>::showKeysInorder(const BinaryTreeNode<K, V>* n) const {
    if (this->isEmpty())
        throw out_of_range("BST buit\n");
    if (n == nullptr)
        showKeysInorder(this->_root);
    else {
        //Inorder: LVR

        if (n->getLeft() != nullptr)
            showKeysInorder(n->getLeft()); // L

        cout << n->getKey() << " "; // V

        if (n->getRight() != nullptr)
            showKeysInorder(n->getRight()); // R

    }
}

template <class K, class V>
void BinarySearchTree<K, V>::showKeysPostorder(const BinaryTreeNode<K, V>* n) const {
    if (this->isEmpty())
        throw out_of_range("BST buit\n");
    if (n == nullptr)
        showKeysPostorder(_root);
    else {
        // Postorder: LRV
        if (n->getLeft() != nullptr)
            showKeysPostorder(n->getLeft()); // L
        if (n->getRight() != nullptr)
            showKeysPostorder(n->getRight()); // R

        cout << n->getKey() << " "; // V

    }
}

template <class K, class V>
bool BinarySearchTree<K, V>::equals(const BinarySearchTree<K, V>& other) const {
    // Si els tamanys s??n iguals procedim a comparar els seus fills
    if (this->size() == other.size())
        return equalsAux(_root, other._root);
        // Si tenen tamanys diferents ??s evident que no poden ser iguals
    else
        return false;
}

template <class K, class V>
bool BinarySearchTree<K, V>::equalsAux(const BinaryTreeNode<K, V>* node, const BinaryTreeNode<K, V>* node2) const {
    // Si els dos nodes s??n nuls aleshores s??n iguals
    if (node == nullptr && node2 == nullptr)
        return true;
    else if (node != nullptr && node2 != nullptr) {
        if (*node == *node2) {
            return equalsAux(node->getLeft(), node2->getLeft()) &&
                    equalsAux(node->getRight(), node2->getRight());
        }
    }
    //Si hem arribem aqu?? vol dir o b?? que un dels nodes no ??s null i l'altre 
    //ho ??s, o que el node diferent de node2, aleshores no s??n iguals:
    return false;
}

template <class K, class V>
const std::vector<BinaryTreeNode<K, V>*>& BinarySearchTree<K, V>::getLeafs() const {
    return getLeafsAux(this->_root);
}

template <class K, class V>
const std::vector<BinaryTreeNode<K, V>*>& BinarySearchTree<K, V>::getLeafsAux(BinaryTreeNode<K, V>* n) const {
    vector<BinaryTreeNode<K,V>*> leafs;
    getLeafs_aux(leafs, _root);
    return leafs;
}

template <class K, class V>
void BinarySearchTree<K,V>::getLeafs_aux(vector<BinaryTreeNode<K,V>*>& leafs, BinaryTreeNode<K,V>* node){
    if(node->isLeaf()){
        leafs.push_back(node);
    }
    else{
        if(node->hasRight()){
            getLeafs_aux(leafs, node->getRight());
        }
        if(node->hasLeft()){
            getLeafs_aux(leafs, node->getLeft());
        }        
    }
}


template <class K, class V>
BinaryTreeNode<K, V>* BinarySearchTree<K, V>::find(const K& k) const {
    return _find(k, this->_root);
}

template <class K, class V>
BinaryTreeNode<K, V>* BinarySearchTree<K, V>::_find(const K& k, BinaryTreeNode<K, V>* node) const {
    // Si _root es nullptr o b?? la clau del root ??s la que busquem, retornem el root; 
    if (node == nullptr || node->getKey() == k)
        return node;
        // Si key ??s menor que la key del node, mirem recursivament els seus fills esquerra;
    else if (k < node->getKey())
        return _find(k, node->getLeft());
        // Si key es major que la key del node, mirem recursivament els seus fills dreta;
    else
        return _find(k, node->getRight());
}

template <class K, class V>
BinaryTreeNode<K, V>* BinarySearchTree<K, V>::findIter(const K& k) const {
    
    BinaryTreeNode<K,V>* aux = _root;
    
    while (aux != nullptr && aux->getKey() != k){
        if (k < aux->getKey())
            aux = aux->getLeft();
        else
            aux = aux->getRight();       
    }
    return aux;   
}


template <class K, class V>
void BinarySearchTree<K, V>::printNodesNivell(const int& nivell) const {
    if (isEmpty()) {
        throw out_of_range("ERROR: BST buit");
    }
    printNodesNivell(nivell, _root);
}

template <class K, class V>
void BinarySearchTree<K, V>::printNodesNivell(int nivell, const BinaryTreeNode<K, V>* node) const {
    if (node == nullptr)
        return;
    if (nivell == 0)
        cout << node->getKey() << " ";
    else {
        printNodesNivell(nivell - 1, node->getLeft());
        printNodesNivell(nivell - 1, node->getRight());
    }
}


#endif // BINARYSEARCHTREE_H

