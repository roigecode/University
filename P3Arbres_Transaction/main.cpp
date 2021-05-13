
/* 
 * File:   main.cpp
 * Author: Roige
 *
 * Created on 8 de mayo de 2021, 22:33
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <chrono>

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

void opcio_1(TransactionManager& tm) {
    cout << "Introdueix la ruta del arxiu: " << endl;

    //cin>>arxiu;
    try {
        chrono::steady_clock::time_point begin = chrono::steady_clock::now();
        tm.loadFromFile("transaction-cas-de-prova.txt" /*arxiu*/);
        chrono::steady_clock::time_point end = chrono::steady_clock::now();
        cout << "Temps transcorregut: " << chrono::duration_cast<chrono::seconds>(end - begin).count() << " s." << endl;
    } catch (const out_of_range& ex) {
        cerr << ex.what() << endl;
    }
}

void opcio_2(TransactionManager& tm, int n_mostrar) {
    cout << "Quantes transaccions vols mostrar?" << endl;
    cout << " >> ";
    cin>>n_mostrar;
    try {
        tm.showAll(n_mostrar);
    } catch (const out_of_range& ex) {
        cerr << ex.what() << endl;
    }
}

void opcio_3(TransactionManager& tm, int n_mostrar) {
    cin.ignore();
    cout << "Quantes transaccions vols mostrar?" << endl;
    cout << " >> ";
    cin>>n_mostrar;
    try {
        tm.showAllReverse(n_mostrar);
    } catch (const out_of_range& ex) {
        cerr << ex.what() << endl;
    }
}

void opcio_4(TransactionManager& tm) {
    cin.ignore();
    cout << "Mostrant transacció més antiga: " << endl;
    try {
        tm.showOldest();
    } catch (const out_of_range& ex) {
        cerr << ex.what() << endl;
    }
}

void opcio_5(TransactionManager& tm) {
    cin.ignore();
    cout << "Mostrant transacció més recent: " << endl;
    try {
        tm.showNewest();
    } catch (const out_of_range& ex) {
        cerr << ex.what() << endl;
    }
}

void opcio_6(TransactionManager& tm) {
    cout << "Comissió total: " << tm.feesInTotal() << endl;
}

void opcio_7(TransactionManager& tm) {
    cin.ignore();
    string date;
    cout << "Introdueix una data (aaaa-mm-dd hh:mm): ";
    getline(cin, date);
    cout << "Comisions desde " << date << ": " << tm.feesSinceTime(date) << endl;
}

void opcio_8(TransactionManager& tm, pair <string, string> ival) {
    cin.ignore();

    cout << "Introdueix la data d'inici: " << endl;
    cout << " >> ";
    getline(cin, ival.first);

    cout << "Introdueix la data final: " << endl;
    cout << " >> ";
    getline(cin, ival.second);

    cout << "Comissions entre " << ival.first << " i " << ival.second << " : "
            << tm.feesInTimeInterval(ival) << endl;
}

void opcio_9(TransactionManager&) {
    cin.ignore();
    string queries;
}

int main(int argc, char** argv) {
    int opcio, n_mostrar;
    string data_inici, data_final;
    TransactionManager tm;
    pair<string, string> ival;

    do {
        graficarMenu();
        cin>>opcio;

        switch (opcio) {
            case 1:opcio_1(tm);
                break;

            case 2:opcio_2(tm, n_mostrar);
                break;

            case 3: opcio_3(tm, n_mostrar);
                break;

            case 4: opcio_4(tm);
                break;

            case 5: opcio_5(tm);
                break;

            case 6: opcio_6(tm);
                break;

            case 7: opcio_7(tm);
                break;

            case 8: opcio_8(tm,ival);
//
//                ival.first = "2020-01-01 13:47";
//                ival.second = "2020-01-02 10:07";
//                cout << "Comissions entre " << ival.first << " i " << ival.second << " : "
//                        << tm.feesInTimeInterval(ival) << endl;
                break;

            case 9: opcio_9(tm);
                break;

            case 10: break;

            default: cout << "Opcio incorrecte.\n" << endl;
                cin.ignore();
                break;
        }
    } while (opcio != 10);

    return 0;
}

