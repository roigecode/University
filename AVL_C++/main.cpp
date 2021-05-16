

/* 
 * File:   main.cpp
 * Author: Roige
 *
 * Created on 8 de mayo de 2021, 22:33
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include "AVL.h"

using namespace std;

int main(int argc, char** argv) {
    try {
        
        int value_unitary_test = 420;
        
        // TEST UNITARI EXERCICI 1
        AVL<int, int> ex1;

        int testKeys_[] = {2, 0, 8, 45, 76, 5, 3, 40};
        int testValues[] = {5, 5, 1, 88, 99, 12, 9, 11};

        for (int i = 0; i < 8; i++) {
            ex1.add(testKeys_[i], testValues[i]);
        }

        // ex1.showKeysInorder();


        // TEST RIGHT ROTATION - Cas (1):
        AVL<int, int> RR;

        int testKeys[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 0; i < 9; i++) {
            RR.add(testKeys[i], testValues[i]);
        }

        // RR.showKeysInorder();



        // TEST LEFT ROTATION - Cas (2):
        AVL<int, int> LR;
        for (int i = 8; i >= 0; i--) {
            LR.add(testKeys[i], testValues[i]);
        }

        //LR.showKeysInorder();


        // TEST LR - Cas (3):
        AVL<int, int> case3;
        case3.add(6, value_unitary_test);
        case3.add(2, value_unitary_test);
        case3.add(5, value_unitary_test);
        //case3.showKeysInorder();


        // TEST RL - Cas(4):
        AVL<int, int> case4;
        case4.add(11, value_unitary_test);
        case4.add(13, value_unitary_test);
        case4.add(12, value_unitary_test);
        //case4.showKeysInorder();
        
        cout<<"\n+-------------------------+";
        cout<<"\n|     INORDER OUTPUTS     |";
        cout<<"\n+-------------------------+";
        cout<<"\n|EX 1: ";
        ex1.showKeysInorder();
        cout<<"|\n|RR: ";
        RR.showKeysInorder();
        cout<<"   |\n|LR: ";
        LR.showKeysInorder();
        cout<<"   |\n|Case 3: ";
        case3.showKeysInorder();
        cout<<"\t\t  |\n|Case 4: ";
        case4.showKeysInorder();
        cout<<"\t  |\n+-------------------------+";
        cout<<"\n\n";

    } catch (out_of_range& e) {
        cout << "EXCEPCIÓ: " << e.what() << endl;
    }

    return 0;
}


