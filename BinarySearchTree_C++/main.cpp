
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

using namespace std;

int main(int argc, char** argv) {
    try {

        // Construim un arbre que es declara de forma estàtica per tant 
        //el destructor es cridarà automàticament al acabar l'execució:

        BinarySearchTree<int, int> primer;

        // Creem dos arrays de prova per les Keys i els Values:
        int testKeys[] = {2, 0, 8, 45, 76, 5, 3, 40, 50, 99, 250, 82};
        int testValues[] = {5, 5, 1, 88, 99, 12, 9, 11, 3, 77, 123, 19};

        // Els afegim al arbre, dividim sizeof() entre 4 perquè són int's:
        for (unsigned i = 0; i< sizeof (testKeys) / 4; i++) {
            primer.add(testKeys[i], testValues[i]);
        }

        // El primer arbre (i la copia que en farem) queda així:

        /* (0)     2
         *        / \
         * (1)   0   8
         *          / \
         * (2)     5  45
         *        /  /  \
         * (3)   3  40  76
         *             /  \
         * (4)        50  99
         *               /  \
         * (5)          82  250
         * 
         * (6)  (no hi ha nodes)
         */

        cout << "\nBuscant 99: " << endl;
        cout << "El node buscat és: " << primer.findTestPublic(99)->getKey() << endl;
        if (primer.findTestPublic(99)->hasLeft()) {
            cout<<"Height de 99: "<<primer.findTestPublic(99)->getHeight()<<endl;
            cout<<"Té node esquerra? " << primer.findTestPublic(99)->hasLeft()<<endl;
            cout << "L'esquerra del node buscat és: " << primer.findTestPublic(99)->getLeft()->getKey() << endl;
            cout<<"Height del node esquerra és: "<< primer.findTestPublic(99)->getLeft()->getHeight()<<endl;
            cout<<"Té node dret? " << primer.findTestPublic(99)->hasRight()<<endl;
            cout << "El dret del node buscat és: " << primer.findTestPublic(99)->getRight()->getKey() << endl;
        }
        

        // Imprimim els nivells de l'arbre
        for (unsigned i = 0; i < primer.getHeight(); i++) {
            cout << "\nNodes nivell " << i << ": ";
            primer.printNodesNivell(i);
        }

        // Comprovem que el nivell 6 estigui buit, no hauria d'imprimir res:
        cout << "\nNodes nivell 6: ";
        primer.printNodesNivell(6);
        cout << "\n";

        //Test que imprimia els valors:
//                for(auto& i : testKeys){
//                    cout<<"Value de "<<i<<": ";
//                    primer.valuesOf(i);
//                    cout<<"\n";
//                }

        //Imprimim el primer BST de les tres formes:
        cout << "\n\nPreOrder primer: ";
        primer.showKeysPreorder();

        cout << "\nInOrder primer: ";
        primer.showKeysInorder();

        cout << "\nPostOrder primer: ";
        primer.showKeysPostorder();
        cout << "\n\n";

        // Fem una copia del primer arbre en un 'segon' BST:
        BinarySearchTree<int, int>segon(primer);

        // Comprovem que efectivament siguin iguals:
        if (primer.equals(segon))
            cout << "Cert\n\n";
        else
            cout << "Fals\n\n";

        // Afegim un element amb key 1 i value 101 al primer arbre
        primer.add(1, 101);

        //        cout<<"Value de 1: ";
        //        primer.valuesOf(1);
        //        cout<<"\n";


        // El primer arbre queda així:

        /* (0)       2
         *        /     \
         * (1)   0       8
         *        \     / \
         * (2)     1   5  45
         *            /  /  \
         * (3)       3  40  76
         *                 /  \
         * (4)            50  99
         *                   /  \
         * (5)              82  250
         * 
         * (6)  (no hi ha nodes)
         */

        for (unsigned i = 0; i < primer.getHeight(); i++) {
            cout << "\nNodes nivell " << i << ": ";
            primer.printNodesNivell(i);
        }

        cout << "\n\nPreOrder primer: ";
        primer.showKeysPreorder();
        cout << "\nInOrder primer: ";
        primer.showKeysInorder();
        cout << "\nPostOrder primer: ";
        primer.showKeysPostorder();
        cout << "\n\n";

        cout << "PreOrder segon: ";
        segon.showKeysPreorder();
        cout << "\nInOrder segon: ";
        segon.showKeysInorder();
        cout << "\nPostOrder segon: ";
        segon.showKeysPostorder();

        if (primer.equals(segon))
            cout << "\n\nCert\n\n";
        else
            cout << "\n\nFals\n\n";

        //tests per comprovar els mètodes de height() i size() del primer BST
        cout << "Altura màxima primer BST: " << primer.getHeight() <<
                "\nTamany primer BST no recursiu: " << primer.size() <<
                "\nTamany primer BST recursiu: " << primer.sizeRecursiu() << "\n\n";

        //tests per comprobar els mètodes de height() i size() del segon BST
        cout << "Altura màxima segon BST: " << segon.getHeight()<<
                "\nTamany segon BST no recursiu: " << segon.size() <<
                "\nTamany segon BST recursiu: " << segon.sizeRecursiu() << "\n\n";

    } catch (out_of_range& e) {
        cout << "EXCEPCIÓ: " << e.what() << endl;
    }

    return 0;
}

