/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Transaction.h
 * Author: Roige
 *
 * Created on 11 de mayo de 2021, 19:01
 */

#include <iostream>
#ifndef TRANSACTION_H
#define TRANSACTION_H
using namespace std;

class Transaction{
public:
    // Constructors:
    Transaction(string data, int id_client, float quantitat_transaccio);
    Transaction(const Transaction& orig);
    
    // Consultors:
    string getData();
    int getClient();
    float getQuantitatTransaccions();
    
    // Modificadors:
    void setData(string data);
    void setClient(int id_client);
    void setQuantitatTransaccions(float quantitat_transaccio);
    
    // Mètodes extra:
    void printTransaction();
    
private:
    string _data;
    int _id_client;
    float _quantitat_transaccio;
};

#endif /* TRANSACTION_H */
