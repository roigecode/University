/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Patient.h
 * Author: Roige
 *
 * Created on 31 de marzo de 2021, 20:57
 */

#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
using namespace std;

class Patient{
public:
    Patient();
    Patient(string id, string nom, string cognom, string estat);    
    void print();
    string getEstat();
private:
    string _id;
    string _nom;
    string _cognom;
    string _estat;
};

#endif /* PATIENT_H */

