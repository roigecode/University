
/* 
 * File:   TransactionManager.h
 * Author: Roige
 *
 * Created on 12 de mayo de 2021, 0:18
 */

#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<cstring>
#include "Transaction.h"
#include "BinarySearchTree.h"

using namespace std;

class TransactionManager : protected BinarySearchTree<string, Transaction> {
public:
    TransactionManager(float buyingFee = 0.02, float sellingFee = 0.03);
    TransactionManager(string file_path, float buyingFee = 0.02, float sellingFee = 0.03);
    virtual ~TransactionManager();

    void loadFromFile(string file_path);
    void showAll(int n) const;
    void showAllReverse(int n) const;
    void showOldest() const;
    void showNewest() const;

    float feesInTotal() const;
    float feesSinceTime(string date) const;
    float feesInTimeInterval(pair<string, string> interval) const;

    // Mètodes Auxiliars:
    vector<Transaction> showAll_aux(BinaryTreeNode<string, Transaction>* n, vector<Transaction> v) const;
    vector<Transaction> showAllReverse_aux(BinaryTreeNode<string, Transaction>* n, vector<Transaction> v) const;
    BinaryTreeNode<string, Transaction>* showOldest_aux(BinaryTreeNode<string, Transaction>* n) const;
    BinaryTreeNode<string, Transaction>* showNewest_aux(BinaryTreeNode<string, Transaction>* n) const;
    float feesInTotal_aux(BinaryTreeNode<string, Transaction>* n) const;
    float feesSinceTime_aux(string date, BinaryTreeNode<string, Transaction>* root) const;
    float feesInTimeInterval_aux(pair<string, string> interval, BinaryTreeNode<string, Transaction>* n) const;
    float calculaComisio(BinaryTreeNode<string, Transaction>* node) const;

private:
    float sellingFee;
    float buyingFee;
};

TransactionManager::TransactionManager(float buyingFee, float sellingFee) {
    this->buyingFee = buyingFee;
    this->sellingFee = sellingFee;
}

TransactionManager::TransactionManager(string file_path, float buyingFee, float sellingFee) {
}

TransactionManager::~TransactionManager() {
}

void TransactionManager::loadFromFile(string file_path) {
    fstream arxiu(file_path);
    string linea, constructor_aux = "", llista_aux[2];
    int nombre_linea = 0, nombre_parametre = 0;
    string instant;
    int id;
    float quantitat;

    while (!arxiu.eof()) {
        getline(arxiu, linea);
        if (nombre_linea == 0 && linea.compare("") == 0)
            throw out_of_range("EXCEPCIÓ: Arxiu buit o amb nom incorrecte.");
        if (nombre_linea > 0) {
            for (int i = 0; i < linea.length(); i++) {
                if (linea[i] == ',') {
                    llista_aux[nombre_parametre] = constructor_aux;
                    constructor_aux = "";
                    nombre_parametre++;
                } else {
                    constructor_aux += linea[i];
                }
            }
            instant = llista_aux[0];
            id = stoi(llista_aux[1]);
            quantitat = stof(constructor_aux);
            nombre_parametre = 0;
            constructor_aux = "";
            Transaction t(instant, id, quantitat);
            this->add(instant, t);
        }
        nombre_linea++;
    }

    arxiu.close();
}

void TransactionManager::showAll(int n) const {
    int n_aux;
    vector<Transaction> transactions;
    transactions = showAll_aux(this->_root, transactions);
    int imprimides = 0;

    if (this->isEmpty())
        throw out_of_range("EXCEPCIÓ: L'estructura està buida.");
    else {
        // Cas sortir 0: Contemplat perque el for NO iterarà:
        for (int i = 0; i < n; i++) {
            if (imprimides >= transactions.size() or n > transactions.size())
                throw out_of_range("EXCEPCIÓ: No hi ha tantes transactions.");
            else {
                Transaction t = transactions[i];
                t.printTransaction();
                if (i == n - 1) {
                    cout << "Quantes transactions més vols mostrar?\n ";
                    cout << " >> ";
                    cin >> n_aux;
                    n += n_aux;
                }
                imprimides++;
            }
        }
    }

}

vector<Transaction> TransactionManager::showAll_aux(BinaryTreeNode<string, Transaction>* n, vector<Transaction> v) const {

    // Investigar porque con n->getLeft()!=nullptr / getRight()!=nullptr da error;

    if (n->getLeft() != nullptr) {
        v = showAll_aux(n->getLeft(), v);
    }
    vector<Transaction> t = n->getValues();
    for (int i = 0; i < t.size(); i++) {
        v.push_back(t[i]);
    }
    if (n->getRight() != nullptr) {
        v = showAll_aux(n->getRight(), v);
    }
    return v;
}

void TransactionManager::showAllReverse(int n) const {
    int n_aux;
    vector<Transaction> transactions;
    transactions = showAllReverse_aux(this->_root, transactions);
    int imprimides = 0;

    if (this->isEmpty())
        throw out_of_range("EXCEPCIÓ: L'estructura està buida.");
    else {
        // Cas sortir 0: Contemplat perque el for NO iterarà:
        for (int i = 0; i < n; i++) {
            if (imprimides >= transactions.size() or n > transactions.size())
                throw out_of_range("EXCEPCIÓ: No hi ha tantes transactions.");
            else {
                Transaction t = transactions[i];
                t.printTransaction();
                if (i == n - 1) {
                    cout << "Quantes transactions més vols mostrar?\n ";
                    cout << " >> ";
                    cin >> n_aux;
                    n += n_aux;
                }
                imprimides++;
            }
        }
    }

}

vector<Transaction> TransactionManager::showAllReverse_aux(BinaryTreeNode<string, Transaction>* n, vector<Transaction> v) const {
    // ÍDEM ERROR:
    // Investigar porque con n->getLeft()!=nullptr / getRight()!=nullptr da error;

    if (n->getRight() != nullptr) {
        v = showAllReverse_aux(n->getRight(), v);
    }
    vector<Transaction> t = n->getValues();
    for (int i = 0; i < t.size(); i++) {
        v.push_back(t[i]);
    }
    if (n->getLeft() != nullptr) {
        v = showAllReverse_aux(n->getLeft(), v);
    }
    return v;
}

void TransactionManager::showOldest() const {
    if (this->isEmpty())
        throw out_of_range("EXCEPCIÓ: L'estructura està buida");
    else {
        BinaryTreeNode<string, Transaction> *node = showOldest_aux(this->_root);
        vector<Transaction> transactions = node->getValues();
        Transaction t = transactions[0];
        t.printTransaction();
    }
}

BinaryTreeNode<string, Transaction>* TransactionManager::showOldest_aux(BinaryTreeNode<string, Transaction>* n) const {
    // Per la propietat de ser BST tenim la més antiga a l'esquerra:
    if (n->getLeft() != nullptr) {
        return showOldest_aux(n->getLeft());
    } else {
        return n;
    }
}

void TransactionManager::showNewest() const {
    if (this->isEmpty()) {
        throw out_of_range("EXCEPCIÓ: L'estructura està buida");
    } else {
        BinaryTreeNode<string, Transaction> *node = showNewest_aux(this->_root);
        vector<Transaction> transactions = node->getValues();
        Transaction t = transactions[0];
        t.printTransaction();

    }
}

BinaryTreeNode<string, Transaction>* TransactionManager::showNewest_aux(BinaryTreeNode<string, Transaction>* n) const {
    // Per la propietat de ser BST tenim la més nova a la dreta:
    if (n->getRight() != nullptr) {
        return showNewest_aux(n->getRight());
    } else {
        return n;
    }
}

float TransactionManager::feesInTotal() const {
    if (this->isEmpty())
        return 0;
    else
        return feesInTotal_aux(this->_root);
}

float TransactionManager::feesInTotal_aux(BinaryTreeNode<string, Transaction>* n) const {
    float preu_t, p = 0;
    if (n->getLeft() != nullptr) {
        p += feesInTotal_aux(n->getLeft());
    }
    vector<Transaction> t = n->getValues();
    for (int i = 0; i < t.size(); i++) {
        preu_t = t[i].getQuantitatTransaccions();
        if (preu_t > 0)
            p += preu_t * this->sellingFee;
        else
            p -= preu_t * this->buyingFee;
    }
    if (n->getRight() != nullptr) {
        p += feesInTotal_aux(n->getRight());
    }
    return p;
}

float TransactionManager::feesSinceTime(string date) const {
    if (this->isEmpty())
        return 0;
    else
        return feesSinceTime_aux(date, _root);
}

float TransactionManager::feesSinceTime_aux(string date, BinaryTreeNode<string, Transaction>* node) const {
    float preu_t, p = 0;

    if (node->getKey() >= date) {

        if (node->hasLeft())
            p += feesSinceTime_aux(date, node->getLeft());

        vector<Transaction> t = node->getValues();

        for (int i = 0; i < t.size(); i++) {
            preu_t = t[i].getQuantitatTransaccions();
            if (preu_t > 0)
                p += preu_t * sellingFee;
            else
                p -= preu_t * buyingFee;
        }
    }

    if (node->getRight() != nullptr)
        p += feesSinceTime_aux(date, node->getRight());

    return p;
}

float TransactionManager::feesInTimeInterval(pair<string, string> interval) const {

    if (interval.first > interval.second)
        throw out_of_range("L'interval no té sentit");
    if (this->isEmpty())
        return 0;
    
    else if (interval.first == interval.second){
        BinaryTreeNode<string,Transaction>* node = find(interval.first);
        return calculaComisio(node);
    }
    else
        return feesInTimeInterval_aux(interval, _root);

}

float TransactionManager::feesInTimeInterval_aux(pair<string, string> interval, BinaryTreeNode<string, Transaction>* n) const {
    float preu_t, p = 0;

    if (n->getKey() < interval.first) {
        if (n->hasRight())
            p += feesInTimeInterval_aux(interval, n->getRight());

    } else if (n->getKey() > interval.second) {
        if (n->hasLeft())
            p += feesInTimeInterval_aux(interval, n->getLeft());

    } else {

        if (n->hasRight()) {
            p += feesInTimeInterval_aux(interval, n->getRight());
        }

        if (n->hasLeft()) {
            p += feesInTimeInterval_aux(interval, n->getLeft());
        }

        vector<Transaction> t = n->getValues();

        for (unsigned i = 0; i < t.size(); i++) {
            preu_t = t[i].getQuantitatTransaccions();
            if (preu_t > 0)
                p += preu_t * sellingFee;
            else
                p -= preu_t * buyingFee;
        }
    }

    //cout<<"P retorna: "<<p<<endl;
    return p;
}

float TransactionManager::calculaComisio(BinaryTreeNode<string, Transaction>* node) const{
    
    cout<<"Entro a calcula comissio"<<endl;
    
    float comissio = 0;
    
    if(node == nullptr){
        cout<<"Node null";
        return 0;
    }
    
    for(Transaction t : node->getValues()){
        if(t.getQuantitatTransaccions() < 0){
            comissio += this->buyingFee * abs(t.getQuantitatTransaccions());
            cout<<"Com +: "<<comissio;
        }
        else{
            comissio += this->sellingFee * abs(t.getQuantitatTransaccions());
            cout<<"Com -:"<<comissio;
        }
    }
    cout<<"Comissio: "<<comissio;
    return comissio;
    
                
}


#endif /* TRANSACTIONMANAGER_H */


