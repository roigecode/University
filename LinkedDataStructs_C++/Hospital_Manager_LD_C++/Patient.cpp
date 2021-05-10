#include <iostream>
#include "Patient.h"

using namespace std;

Patient::Patient(string id, string nom, string cognom, string estat) {
    _id = id;
    _nom = nom;
    _cognom = cognom;
    _estat = estat;
}

void Patient::print(){
    cout << "ID: " << _id << ", Nom: " << _nom << ", Cognom: " << _cognom
            << ", Estat: " << _estat << endl;
}

string Patient::getEstat(){
    return _estat;
}