/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Roige
 *
 * Created on 21 de marzo de 2021, 20:04
 */

#include <cstdlib>
#include <iostream>
#include "ArrayDeque.h"
using namespace std;

int main(int argc, char** argv) {
    int opcio;
    ArrayDeque arraydeque(3);

    vector<string> opcions = {"1. Inserir element al davant de la cua",
        "2. Inserir element al darrera de la cua", "3. Treure element pel davant de la cua",
        "4. Treure element pel darrera de la cua", "5. Consultar el primer element",
        "6. Consultar el darrer element", "7. Imprimir tot el contingut de l’ArrayDeque", "8. Sortir"};

    int nombre;

    do {
        for (unsigned i = 0; i < opcions.size(); i++) {
            cout << opcions[i] << "\n";
        }

        cin>>opcio;
        switch (opcio) {
            case 1: cout << "Nombre a inserir front: ";
                cin>>nombre;
                try {
                    arraydeque.enqueueFront(nombre);
                } catch (const std::out_of_range) {
                    cout << "EXCEPTION: L'estructura està plena\n\n";
                }
                break;
                break;

            case 2: cout << "Nombre a inserir back: ";
                cin>>nombre;
                try {
                    arraydeque.enqueueBack(nombre);
                } catch (const std::out_of_range) {
                    cout << "EXCEPTION: L'estructura està plena\n\n";
                }
                break;

            case 3: try {
                    arraydeque.dequeueFront();
                } catch (const std::out_of_range) {
                    cout << "EXCEPTION: L'estructura està buida\n\n";
                }
                break;

            case 4: try {
                    arraydeque.dequeueBack();
                } catch (const std::out_of_range) {
                    cout << "EXCEPTION: L'estructura està buida\n\n";
                }
                break;

            case 5: try {
                    cout << arraydeque.getFront() << endl << endl;
                } catch (const std::out_of_range) {
                    cout << "EXCEPTION: L'estructura està buida\n\n";
                }
                break;

            case 6: try {
                    cout << arraydeque.getBack() << endl << endl;
                } catch (const std::out_of_range) {
                    cout << "EXCEPTION: L'estructura està buida\n\n";
                }
                break;

            case 7: arraydeque.print();
                break;
            case 8: break;
            default: cout << "Opció incorrecta.\n\n";
                break;
        }
    } while (opcio != 8);

    return 0;
}

