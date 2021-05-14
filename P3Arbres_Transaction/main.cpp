
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
#include <fstream>

#include "BinarySearchTree.h"
#include "Transaction.h"
#include "TransactionManager.h"

using namespace std;

void opcio_1(TransactionManager& tm) {
    cout << "Introdueix la ruta del arxiu: " << endl;

    //cin>>arxiu;
    try {
        chrono::steady_clock::time_point begin = chrono::steady_clock::now();
        tm.loadFromFile("transactions-cas-de-prova.txt" /*arxiu*/);
        chrono::steady_clock::time_point end = chrono::steady_clock::now();
        cout << "Temps transcorregut: " << chrono::duration_cast<chrono::seconds>(end - begin).count()
                << " s." << endl;
    } catch (const out_of_range& ex) {
        cerr << ex.what() << endl;
    }
}

void opcio_2(TransactionManager& tm, int n_mostrar) {
    cin.ignore();
    cout << "Quantes transaccions vols mostrar? \n >> ";
    cin>>n_mostrar;
    try {
        tm.showAll(n_mostrar);
    } catch (const out_of_range& ex) {
        cerr << ex.what() << endl;
    }
}

void opcio_3(TransactionManager& tm, int n_mostrar) {
    cin.ignore();
    cout << "Quantes transaccions vols mostrar? \n >> ";
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

string opcio_7() {
    cin.ignore();
    string date;
    cout << "Introdueix una data (aaaa-mm-dd hh:mm):\n >> ";
    cin.ignore();
    getline(cin, date);
    cout << "Comissió desde: " << date << " és de: \n";
    return date;
}

pair<string, string> opcio_8() {
    string d1;
    string d2;

    cin.ignore();

    cout << "Introdueix la data d'inici (aaaa-mm-dd hh:mm):\n >> ";
    cin.ignore();
    getline(cin, d1);

    cout << "Introdueix la data final (aaaa-mm-dd hh:mm): \n >> ";
    cin.ignore();
    getline(cin, d2);

    cout << "Comissions entre " << d1 << " i " << d2 << " :\n ";
    pair<string, string> ival = pair<string, string>(d1, d2);
    return ival;
}

float opcio_9(TransactionManager &tm) {

    cin.ignore();
    float c;
    string path = "queries.txt"; // Enunciat
    string data;
    ifstream fitxer;
    fitxer.open(path);
    
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    while (getline(fitxer, data)) {
        pair<string, string> ival;
        ival.first = data;
        ival.second = data;
        c += tm.feesInTimeInterval(ival);
    }

    cout << "Comissions de l'arxiu: " << c <<"\n";

    chrono::steady_clock::time_point end = chrono::steady_clock::now();

    cout << "Temps transcorregut: " << chrono::duration_cast<chrono::seconds>(end - begin).count()
            << " s." << endl;

    fitxer.close();
    return c;


    //    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    //
    //    ifstream fitxer("queries.txt");
    //    string date;
    //
    //    float com = 0;
    //    while (!fitxer.eof()) {
    //
    //        getline(fitxer, date);
    //        pair<string, string> i;
    //        i.first = date;
    //        i.second = date;
    //        com += tm.feesInTimeInterval(i);
    //    }
    //
    //    fitxer.close();
    //
    //    cout << "Comissions de l'arxiu: " << com << endl;
    //
    //    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    //    cout << "Temps transcorregut: " << chrono::duration_cast<chrono::seconds>(end - begin).count() << " s." << endl;

}

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

int main(int argc, char** argv) {
    int opcio, n_mostrar;
    TransactionManager tm;
    
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

            case 7: cout << tm.feesSinceTime(opcio_7()) << endl;
                break;

            case 8: try {
                    cout << tm.feesInTimeInterval(opcio_8()) << endl;
                } catch (const out_of_range& ex) {
                    cerr << ex.what() << endl;
                } break;

            case 9: cout<< opcio_9(tm)<<endl;
                break;

            case 10: break;

            default: cout << "Opcio incorrecte.\n" << endl;
                cin.ignore();
                break;
        }
    } while (opcio != 10);

    return 0;
}

