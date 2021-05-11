
/* 
 * File:   main.cpp
 * Author: Roige
 *
 * Created on 8 de mayo de 2021, 22:33
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include "BinarySearchTree.h"
#include "Transaction.h"
#include "TransactionManager.h"

using namespace std;

int main(int argc, char** argv) {
    
    string casdeprova1 = "transaction-cas-de-prova.txt";
    
    Transaction tr1 = Transaction("2020-01-01 09:23", 11712, 107.78);
    tr1.printTransaction();
    
    cout<<"Obrim manager: "<<endl;
    TransactionManager tm = TransactionManager();
    tm.loadFromFile(casdeprova1);
    
    return 0;
}

