
/* 
 * File:   TransactionManager.h
 * Author: Roige
 *
 * Created on 12 de mayo de 2021, 0:18
 */

using namespace std;

#include <iostream>
#include <fstream>

#include "Transaction.h"
#include "BinarySearchTree.h"

#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

class TransactionManager : protected BinarySearchTree<string, Transaction> {
public:
    TransactionManager(float buyingFee = 0.02, float sellingFee = 0.03);
    TransactionManager(string file_path, float buyingFee = 0.02, float sellingFee = 0.03);
    virtual ~TransactionManager();

    void loadFromFile(string file_path);
    void showAll() const;
    void showAllReverse() const;
    void showOldest() const;
    void showNewest() const;

    float feesInTotal() const;
    float feesSinceTime(string date) const;
    float feesInTimeInterval(pair<string, string> interval) const;

private:
    float sellingFee;
    float buyingFee;
    string file_path;
};

TransactionManager::TransactionManager(float buyingFee, float sellingFee) {
    this->buyingFee = buyingFee;
    this->sellingFee = sellingFee;
}

TransactionManager::TransactionManager(string file_path, float buyingFee, float sellingFee)
: TransactionManager(buyingFee, sellingFee) {

}

TransactionManager::~TransactionManager() {
    BinarySearchTree::~BinarySearchTree();
}

void TransactionManager::loadFromFile(string file_path) {
    ifstream archiu(file_path);
    string myText;
    
    // La primera linia té 26 caràcters, els ignorem fins a trobat una nova linia
    
    archiu.ignore(26,'\n');
    
    while (getline(archiu, myText)) {
        // Output the text from the file
        cout << myText<<endl;
    }
    
    archiu.close();
}

void TransactionManager::showAll() const {

}

void TransactionManager::showAllReverse() const {

}

void TransactionManager::showOldest() const {

}

void TransactionManager::showNewest() const {

}

float TransactionManager::feesInTotal() const {
    return 0;
}

float TransactionManager::feesSinceTime(string date) const {
    return 0;
}

float TransactionManager::feesInTimeInterval(pair<string, string> interval) const {
    return 0;
}


#endif /* TRANSACTIONMANAGER_H */

