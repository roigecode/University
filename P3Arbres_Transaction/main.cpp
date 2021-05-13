
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

int main(int argc, char** argv) {
    int opcio, n_mostrar;
    string arxiu, data_inici, data_final;
    TransactionManager tm;

    do {
        graficarMenu();
        cin>>opcio;

        // MIRAR PQ DA ERROR SI ESTO LO METO EN UN MÉTODO DE GESTION:
        // ERROR: <<BST buit>> al pasarlo por parámetro:

        switch (opcio) {
            case 1:
                cout << "Introdueix la ruta del arxiu: " << endl;

                //cin>>arxiu;
                try {
                    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
                    tm.loadFromFile("transaction-cas-de-prova.txt" /*arxiu*/);
                    chrono::steady_clock::time_point end = chrono::steady_clock::now();
                    cout << "Temps transcorregut: " << chrono::duration_cast<chrono::seconds>(end - begin).count() << " ms." << endl;
                } catch (const out_of_range& ex) {
                    cerr << ex.what() << endl;
                }
                break;

            case 2:
                cout << "Quantes transaccions vols mostrar?" << endl;
                cout << " >> ";
                cin>>n_mostrar;
                try {
                    tm.showAll(n_mostrar);
                } catch (const out_of_range& ex) {
                    cerr << ex.what() << endl;
                }
                break;

            case 3: cout << "Quantes transaccions vols mostrar?" << endl;
                cout << " >> ";
                cin>>n_mostrar;
                try {
                    tm.showAllReverse(n_mostrar);
                } catch (const out_of_range& ex) {
                    cerr << ex.what() << endl;
                }
                break;

            case 4:
                cout << "Mostrant transacció més antiga: " << endl;
                try {
                    tm.showOldest();
                } catch (const out_of_range& ex) {
                    cerr << ex.what() << endl;
                }
                break;

            case 5:
                cout << "Mostrant transacció més recent: " << endl;
                try {
                    tm.showNewest();
                } catch (const out_of_range& ex) {
                    cerr << ex.what() << endl;
                }
                break;

            case 6:
                cout << "Comissió total: " << endl;
                try {
                    cout << " " << tm.feesInTotal() << endl;
                } catch (const out_of_range& ex) {
                    cerr << ex.what() << endl;
                }
                break;

            case 7:
                // Solucionar error:
                cout << "Introdueix la data d'inici: " << endl;
                //"2020-01-01 14:52"
                cout << " >> ";
                cin>>data_inici;
                try {
                    float fees_since_time = tm.feesSinceTime(data_inici);
                    cout<<fees_since_time<<endl;
                } catch (const out_of_range& ex) {
                    cerr << ex.what() << endl;
                }
                break;

            case 8:
                cout << "Introdueix la data d'inici: " << endl;
                cout << " >> ";
                cin>>data_inici;

                cout << "Introdueix la data final: " << endl;
                cout << " >> ";
                cin>>data_final;
                
                //auto data = std::pair<string, string>(data_inici, data_final);
                try {
                    //cout << " " << tm.feesInTimeInterval(data) << endl;
                } catch (const out_of_range& ex) {
                    cerr << ex.what() << endl;
                }
                break;


            case 9: break;
            case 10: break;
            default: cout << "Opcio incorrecte.\n" << endl;
                break;
        }
    } while (opcio != 10);

    return 0;
}

