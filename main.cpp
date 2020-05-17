#include <stdio.h>
#include <limits.h>
#include <iostream>
using namespace std;
#include <math.h>
#include"tipe.h"

int main() {
    unsigned int matrice_adjacence[50][50];
    unsigned int * pointeur;
    pointeur = new unsigned int;
    pointeur = (unsigned int *)matrice_adjacence[50][50];
    initialisation_matrice_0(matrice_adjacence);
    ///////////////////// DEMANDE CHOIX UTILISATEUR //////////////////////
    unsigned int rang;
    cout << "Pour commencer l'algorithme, merci de saisir la valeur du rang de votre matrice : ";
    cin >> rang;
    while (rang == 0 || rang > 50) {
        cout << " ERREUR de saisie !\n Merci de saisir une valeur entre 1 et 50 : ";
        cin >> rang;
    }
    cout << endl << endl;
    choix(matrice_adjacence, rang);
    


    delete[]pointeur;
    return 0;
}
