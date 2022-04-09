/*
Nom : main.cpp
Sujet : programme console de test unitaire du jeu du mastermind
Auteur : Léo SEGUIN
Création : 10/05/2021
*/

#include <iostream>
#include "cmastermind.h"

using namespace std;

int main()
{
    CMastermind maPartie;
    unsigned short *tab;
    unsigned short proposition[4];
    int i;
    unsigned short nbBon,nbMal;
    maPartie.initialiserJeu(8,12);
    tab = maPartie.getCombinaison();

    /*
    for(i = 0; i < 4; i++)
        {
           cout << tab[i]<<"\t";
        }
        cout <<endl;
    //afficher le resultat
    */

    do
    {
        cout << "Essai numero " << maPartie.getNbEssai() +1 << " /12" << endl;

        for(i = 0; i < 4; i++)
        {
           cout << "Saisir la couleur du pion  " << i+1 << " : ";
           cin >> proposition[i];
        }

        maPartie.setProposition(proposition);
        maPartie.analyser();
        nbBon = maPartie.getNbBienPlacee();
        nbMal = maPartie.getNbBonneCouleur();
        cout << "Couleur bien placee : " << nbBon << " | Couleur mal placee : " << nbMal << "\n" << endl;
    }

    while ((maPartie.getNbEssai() < maPartie.getCoup())&&(nbBon!=4));

    if (nbBon == 4)
       cout << "Vous avez gagne !!!" <<endl;
    else
       cout << "Perdu..." << endl;

    return 0;
}
