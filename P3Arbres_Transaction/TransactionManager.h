
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
    float feesInTotal_aux(BinaryTreeNode<string, Transaction>* n, float p) const;
    float feesSinceTime_aux(string date, BinaryTreeNode<string, Transaction>* n, float p) const;
    float feesInTimeInterval_aux(pair<string, string> interval, BinaryTreeNode<string, Transaction>* n, float p) const;

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
    if (this->isEmpty()) {
        throw out_of_range("EXCEPCIÓ: L'estructura està buida.");
    } else {
        vector<Transaction> transactions;
        transactions = showAll_aux(this->_root, transactions);
        
        // Mala logica porque solo lanza la excepcion al final, MIRAR:
        for (int i = 0; i < n; i++) {
            if (i >= transactions.size())
                throw out_of_range("EXCEPCIÓ: No hi ha tantes transactions.");  
            else {
                Transaction t = transactions[i];
                t.printTransaction();
                if (i == n - 1) {
                    cout << "Quantes transactions més vols mostrar?\n ";
                    cout<<" >> ";
                    cin >> n_aux;
                    n += n_aux;
                }
            }
        }
    }
}

vector<Transaction> TransactionManager::showAll_aux(BinaryTreeNode<string, Transaction>* n, vector<Transaction> v) const {

    // Investigar porque con n->hasLeft() / hasRight() da error;

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
    if (this->isEmpty()) {
        throw out_of_range("EXCEPCIÓ: L'estructura està buida.");
    } else {
        vector<Transaction> transactions;
        transactions = showAllReverse_aux(this->_root, transactions);
        for (int i = 0; i < n; i++) {
            if (i >= transactions.size())
                throw out_of_range("EXCEPCIÓ: No hi han tantes transaccions.");
            Transaction t = transactions[i];
            t.printTransaction();
            if (i == n - 1) {
                cout << "Quantes transaccions més vols mostrar?";
                cin >> n_aux;
                n += n_aux;
            }
        }
    }
}

vector<Transaction> TransactionManager::showAllReverse_aux(BinaryTreeNode<string, Transaction>* n, vector<Transaction> v) const {
    if (n->hasRight()) {
        v = showAllReverse_aux(n->getRight(), v);
    }
    vector<Transaction> t = n->getValues();
    for (int i = 0; i < t.size(); i++) {
        v.push_back(t[i]);
    }
    if (n->hasLeft()) {
        v = showAllReverse_aux(n->getLeft(), v);
    }
    return v;
}

void TransactionManager::showOldest() const {
    if (this->isEmpty()) {
        throw out_of_range("EXCEPCIÓ: L'estructura està buida");
    } else {
        BinaryTreeNode<string, Transaction> *node = showOldest_aux(this->_root);
        vector<Transaction> transactions = node->getValues();
        for (int i = 0; i < transactions.size(); i++) {
            Transaction t = transactions[i];
            t.printTransaction();
        }
    }
}

BinaryTreeNode<string, Transaction>* TransactionManager::showOldest_aux(BinaryTreeNode<string, Transaction>* n) const {
    if (n->hasLeft()) {
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
        for (int i = 0; i < transactions.size(); i++) {
            Transaction t = transactions[i];
            t.printTransaction();
        }
    }
}

BinaryTreeNode<string, Transaction>* TransactionManager::showNewest_aux(BinaryTreeNode<string, Transaction>* n) const {
    if (n->hasRight()) {
        return showNewest_aux(n->getRight());
    } else {
        return n;
    }
}

float TransactionManager::feesInTotal() const {
    if (this->isEmpty())
        return 0;
    else
        return feesInTotal_aux(this->_root, 0);
}

float TransactionManager::feesInTotal_aux(BinaryTreeNode<string, Transaction>* n, float p) const {
    float preu_t;
    if (n->hasLeft()) {
        p += feesInTotal_aux(n->getLeft(), 0);
    }
    vector<Transaction> t = n->getValues();
    for (int i = 0; i < t.size(); i++) {
        preu_t = t[i].getQuantitatTransaccions();
        if (preu_t > 0)
            p += preu_t * this->sellingFee;
        else
            p -= preu_t * this->buyingFee;
    }
    if (n->hasRight()) {
        p += feesInTotal_aux(n->getRight(), 0);
    }
    return p;
}

float TransactionManager::feesSinceTime(string date) const {
    if (this->isEmpty())
        return 0;
    else
        return feesSinceTime_aux(date, this->_root, 0);
}

float TransactionManager::feesSinceTime_aux(string date, BinaryTreeNode<string, Transaction>* n, float p) const {
    float preu_t;
    if (n->getKey() >= date) {
        if (n->hasLeft()) {
            p += feesSinceTime_aux(date, n->getLeft(), 0);
        }
        vector<Transaction> t = n->getValues();
        for (int i = 0; i < t.size(); i++) {
            preu_t = t[i].getQuantitatTransaccions();
            if (preu_t > 0)
                p += preu_t * this->sellingFee;
            else
                p -= preu_t * this->buyingFee;
        }
    }
    if (n->hasRight()) {
        p += feesSinceTime_aux(date, n->getRight(), 0);
    }
    return p;
}

float TransactionManager::feesInTimeInterval(pair<string, string> interval) const {
    if (interval.first > interval.second)
        throw out_of_range("EXCEPCIÓ: L'interval no té sentit");
    if (this->isEmpty())
        return 0;
    else
        return feesInTimeInterval_aux(interval, this->_root, 0);
}

float TransactionManager::feesInTimeInterval_aux(pair<string, string> interval, BinaryTreeNode<string, Transaction>* n, float p) const {
    float preu_t;
    if (n->getKey() < interval.first) {
        if (n->hasRight())
            p += feesInTimeInterval_aux(interval, n->getRight(), 0);
    } else if (n->getKey() > interval.second) {
        if (n->hasLeft())
            p += feesInTimeInterval_aux(interval, n->getLeft(), 0);
    } else {
        if (n->hasRight())
            p += feesInTimeInterval_aux(interval, n->getRight(), 0);
        if (n->hasLeft())
            p += feesInTimeInterval_aux(interval, n->getLeft(), 0);
        vector<Transaction> t = n->getValues();
        for (int i = 0; i < t.size(); i++) {
            preu_t = t[i].getQuantitatTransaccions();
            if (preu_t > 0)
                p += preu_t * this->sellingFee;
            else
                p -= preu_t * this->buyingFee;
        }
    }
    return p;
}


#endif /* TRANSACTIONMANAGER_H */


