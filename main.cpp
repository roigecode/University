
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
    try{
        
        // Es declara de forma estàtica per tant el destructor es cridarà
        // automàticament al acabar l'execució:
        
        BinarySearchTree<int,int> primer;
        
        int testKeys[] =   {2,0,8,45,76,5,3,40,50,99,250,82};
        int testValues[] = {5,5,1,88,99,12,9,11,3,77,123,19};
        
        for(unsigned i=0; i< sizeof(testKeys)/4 ; i++){
            primer.add(testKeys[i],testValues[i]);
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
        
        for(unsigned i=0; i<primer.height();i++){
            cout<<"\nNodes nivell "<< i<<": ";
            primer.printNodesNivell(i);
        }
        
        cout << "\nNodes nivell 6: ";
        // No hauria d imprimir res
        primer.printNodesNivell(6); 
        cout<<"\n\n";
        
        for(auto& i : testKeys){
            cout<<"Value de "<<i<<": ";
            primer.valuesOf(i);
            cout<<"\n";
        }
        
        //Imprimim el primer BST
        cout << "\n\nPreOrder primer: ";
        primer.showKeysPreorder();
        
        cout << "\nInOrder primer: ";
        primer.showKeysInorder();
        
        cout << "\nPostOrder primer: ";
        primer.showKeysPostorder();
         cout <<"\n\n";
         
        BinarySearchTree<int, int>segon(primer);
        
        if (primer.equals(segon))
            cout << "Cert\n\n";
        else 
            cout << "Fals\n\n";
        
        primer.add(1, 1);
        
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
        
        for(unsigned i=0; i<primer.height();i++){
            cout<<"\nNodes nivell "<< i<<": ";
            primer.printNodesNivell(i);
        }
        
        cout << "\n\nPreOrder primer: ";
        primer.showKeysPreorder();
        cout << "\nInOrder primer: ";
        primer.showKeysInorder();
        cout << "\nPostOrder primer: ";
        primer.showKeysPostorder();
         cout <<"\n\n";
        
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
        cout <<"Altura màxima primer BST: " << primer.height() << 
                "\nTamany primer BST no recursiu: " << primer.size() <<
                "\nTamany primer BST recursiu: " << primer.sizeRecursiu() << "\n\n";
        
        //tests per comprobar els mètodes de height() i size() del segon BST
        cout <<"Altura màxima segon BST: " << segon.height() <<
                "\nTamany segon BST no recursiu: " << segon.size() <<
                "\nTamany segon BST recursiu: " << segon.sizeRecursiu() << "\n\n";
        
    }catch(out_of_range& e){
        cout<<"EXCEPCIÓ: "<<e.what()<<endl;
    }
    
    return 0;
}

