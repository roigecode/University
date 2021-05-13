
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

void graficarMenu() {
    const string opcions[10] = {"1. Introduir fitxer", "2. Transaccions ordenades",
        "3. Transaccions a´l'inrevés", "4. Transaccions del primer instant",
        "5. Transaccions del darrer instant", "6. Comisió total",
        "7. Comisió a partir d'una data", "8. Comisió entre dues dates",
        "9. Balanç de transaccions a queries.txt", "10. Sortir"};

    cout << "----------------------------------------" << endl;
    for (auto& opcio : opcions)
        cout << opcio << endl;
    cout << "----------------------------------------" << endl;
    cout << "\n >> ";
}

void tractarOpcio(int opcio, TransactionManager tm) {
    string arxiu;
    
    switch (opcio) {
        case 1:
            cout << "Introdueix la ruta del arxiu:";
            cin>>arxiu;
            try {
                tm.loadFromFile(arxiu);
            } catch (const out_of_range& ex) {
               cerr<<ex.what()<<endl;;
            }
            break;
            
        case 2: break;
        case 3: break;
        case 4: break;
        case 5: break;
        case 6: break;
        case 7: break;
        case 8: break;
        case 9: break;
        case 10: break;
        default: cout << "Opcio incorrecte.\n" << endl;
            break;
    }
}

int main(int argc, char** argv) {
    int opcio;
    TransactionManager tm;

    do {
        graficarMenu();
        cin>>opcio;
        tractarOpcio(opcio, tm);
    } while (opcio != 10);

    return 0;
}

