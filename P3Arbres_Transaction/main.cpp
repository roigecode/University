
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

using namespace std;

int main(int argc, char** argv) {
    
    Transaction tr1 = Transaction("2020-01-01 09:23", 11712, 107.78);
    tr1.printTransaction();
    return 0;
}

