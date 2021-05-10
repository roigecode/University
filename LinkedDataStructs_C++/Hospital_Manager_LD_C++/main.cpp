
/* 
 * File:   main.cpp
 * Author: Roige
 *
 * Created on 21 de marzo de 2021, 20:04
 */

/**
*  EN ESTE EJERCICIO HE CONSIDERADO QUE NO DEBE HABER
* '_max_size' YA QUE PRECISAMENTE ES LA GRACIA DE LA 
*  LINKEDLIST
*/

#include <cstdlib>
#include <iostream>
#include "LinkedDeque.h"
#include "Patient.h"
#include <vector>
#include <fstream> // Manipulacion de ficheros
#include <sstream> // Manipulación de strings

using namespace std;



void entradaTexto(LinkedDeque<Patient*> &arraydeque) {
    int exit = 1; string entrada = "";

    while (exit != 0) {
        string codi, nom, cognom, estat;

        cout << ">> Codi: "; cin>>entrada; codi = entrada;
        cout << ">> Nom: "; cin>>entrada; nom = entrada;
        cout << ">> Cognom: "; cin>>entrada; cognom = entrada;
        cout << ">> Estat: "; cin>>entrada; estat = entrada;

        Patient* patient = new Patient(codi, nom, cognom, estat);
        if (patient->getEstat() == "NOT_OK") {
            arraydeque.enqueueFront(patient);
        } else {
            arraydeque.enqueueBack(patient);
        }

        cout << "Pacient afegit amb èxit! Premi '0' per sortir, '1' per continuar: "; cin>>exit;
    }
}

void leerFichero(LinkedDeque<Patient*> &arraydeque) {
    string ruta, linia;
    vector<string> dades;
    vector<Patient*> pacients;

    cout << "Entra la ruta al fitxer: "; cin >> ruta;
    ifstream fitxer(ruta);
    while (getline(fitxer, linia)) {

        stringstream s_stream(linia);
        while (s_stream.good()) {
            string sub_str;
            getline(s_stream, sub_str, ',');
            dades.push_back(sub_str);
        }

        pacients.push_back(new Patient(dades[0], dades[1], dades[2], dades[3]));
        dades.clear();
    }

    for (int i = 0; i < pacients.size(); i++) {
        if (pacients[i]->getEstat() == "OK") {
            arraydeque.enqueueBack(pacients[i]);
        } else {//NOT_OK
            arraydeque.enqueueFront(pacients[i]);
        }
    }

    cout << "Pacients afegits correctament" << endl;
}

void procesarOpcions(int opcio, LinkedDeque<Patient*> &arraydeque, LinkedDeque<Patient>* ptr_arraydeque) {
    switch (opcio) {
        case 1: leerFichero(arraydeque); break;
        case 2: arraydeque.print(); break;
        case 3: try{arraydeque.dequeueFront();}catch(const out_of_range){"EXCEPCIÓ: No hi ha pacients a la cua";} break;
        case 4: try{arraydeque.dequeueBack();}catch(const out_of_range){"EXCEPCIÓ: No hi ha pacients a la cua";} break;
        case 5: entradaTexto(arraydeque); break;
        case 6: try{arraydeque.getFront()->print();}catch(const out_of_range){"EXCEPCIÓ: No hi ha pacients a la cua";} break;
        case 7: try{arraydeque.getBack()->print();}catch(const out_of_range){"EXCEPCIÓ: No hi ha pacients a la cua";}break;
        case 8: delete ptr_arraydeque; break;
        default: cout << "Opció incorrecta.\n\n"; break;
        }
}

int main(int argc, char** argv) {

    int opcio;
    LinkedDeque<Patient*> arraydeque;
    LinkedDeque<Patient>* ptr_arraydeque;

    vector<string> opcions = {"1. Llegir un fitxer amb les entrades de pacients",
        "2. Imprimir la cua de pacients", "3. Eliminar el primer pacient de la cua",
        "4. Eliminar el darrer pacient de la cua", "5. Inserir n entrades de pacients des de teclat (0 per finalitzar)",
        "6. Consultar el primer pacient de la cua", "7. Consultar el darrer pacient de la cua", "8. Sortir"};

    do{
        for(int i = 0; i < opcions.size(); i++){
            cout << opcions[i] << endl;  
        }
        
        cin >> opcio;
        procesarOpcions(opcio, arraydeque, ptr_arraydeque);
        
    } while(opcio != 8);
        return 0;
    }

