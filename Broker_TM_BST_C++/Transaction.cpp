/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Transaction.cpp
 * Author: Roige
 *
 * Created on 11 de mayo de 2021, 20:18
 */

#include <cstdlib>
#include "Transaction.h"
#include <iostream>

using namespace std;

// Constructors

Transaction::Transaction(std::string data, int id_client, float quantitat_transaccio) {
    this->_data = data;
    this->_id_client = id_client;
    this->_quantitat_transaccio = quantitat_transaccio;
}

Transaction::Transaction(const Transaction& orig) {
    this->_data = orig._data;
    this->_id_client = orig._id_client;
    this->_quantitat_transaccio = orig._quantitat_transaccio;
}


// Consultors

int Transaction::getClient() {
    return this->_id_client;
}

string Transaction::getData() {
    return this->_data;
}

float Transaction::getQuantitatTransaccions() {
    return this->_quantitat_transaccio;
}


// Modificadors

void Transaction::setClient(int id_client) {
    this->_id_client = id_client;
}

void Transaction::setData(std::string data) {
    this->_data = data;
}

void Transaction::setQuantitatTransaccions(float quantitat_transaccio) {
    this->_quantitat_transaccio = quantitat_transaccio;
}

// Extra
void Transaction::printTransaction(){
    cout<<this->_data<<","<<this->_id_client<<","<<this->_quantitat_transaccio<<endl;
}


