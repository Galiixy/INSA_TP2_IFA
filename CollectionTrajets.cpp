/*************************************************************************
                           CollectionTrajets  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <CollectionTrajets> (fichier Xxx.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"

#include "CollectionTrajets.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes
const int CHARMAX = 256;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void CollectionTrajets::Afficher()
{
    if (this->cardAct == 0)
    {
        cout << "Aucun trajet" << endl;
    }
    else
    {
        unsigned int i;
        for (i = 0; i < this->cardAct; i++)
        {
            cout << "Trajet " << i + 1 << " :" << "\r\n";
            this->TrajetTab[i]->Afficher();
            
            
        }
    }
}

void CollectionTrajets::AjouterSimple(char *depart, char *arrivee, Transport transp)
{
    Trajet *temp = new TrajetSimple(depart, arrivee, transp);
    ajuster(1);
    if (cardAct < cardMax)
    {
        this->TrajetTab[this->cardAct] = temp;
        this->cardAct = this->cardAct + 1;
    }
}

void CollectionTrajets::AjouterCompose(Trajet **traj, int sizep, char *depart, char *arrivee)
{

    Trajet *temp = new TrajetCompose(traj, sizep, depart, arrivee);
    ajuster(1); 
    //ajuste le cardMax
    if (cardAct < cardMax)
    {
        this->TrajetTab[this->cardAct] = temp;
        this->cardAct = this->cardAct + 1;
    }
}

string CollectionTrajets::Sauvegarder(int filtre) {
    string sauvegarde;
    if (this->cardAct == 0)
    {
        cout << "Aucun trajet" << endl;
    }
    else
    {
        char villeChoisiPourFiltre[CHARMAX];
        int borneInf, borneSup;
        borneInf = 0;
        borneSup = 0;
        if (filtre == 4 or filtre == 5)
        {
            cout << "Veuillez entrer la ville de votre choix : ";
            cin >> villeChoisiPourFiltre;
        }
        else if (filtre == 6)
        {
            cout << "Veuiller entrer la borne inférieure (a partir de 1): ";
            cin >> borneInf;
            cout << "Veuiller entrer la borne supérieure (jusqu'a l'index " << cardAct << " ) :";
            cin >> borneSup;
        }

        unsigned int cpt;
        unsigned int index=0;
        for (cpt = 0; cpt < this->cardAct; cpt++)
        {   
            if(conditionSauvegarde(filtre, cpt, villeChoisiPourFiltre, borneInf, borneSup)){
                sauvegarde = sauvegarde + std::to_string(index) + ";";
                sauvegarde = sauvegarde + std::to_string(TrajetTab[cpt]->getNbTrajets()) + ";";
                sauvegarde = sauvegarde +TrajetTab[cpt]->Sauver();
                sauvegarde = sauvegarde + "\n";
                index++;
            }
        }
    }
    return sauvegarde;
}
string CollectionTrajets::Sauvegarder() {
    string sauvegarde;
    if (this->cardAct == 0)
    {
        cout << "Aucun trajet" << endl;
    }
    else
    {
        unsigned int i;
        for (i = 0; i < this->cardAct; i++)
        {
            sauvegarde = sauvegarde + TrajetTab[i]->Sauver();
        }
    }
    return sauvegarde;
}

unsigned int CollectionTrajets::getTaille() {
    return this->cardAct;
}
//-------------------------------------------- Constructeurs - destructeur

CollectionTrajets::CollectionTrajets()
{
#ifdef MAP
    cout << "Appel au constructeur de <CollectionTrajets>" << endl;
#endif
    cardMax = 0;
    TrajetTab = NULL;
    cardAct = 0;

} //----- Fin de CollectionTrajets

CollectionTrajets::CollectionTrajets(Trajet **trajetTabP, int sizep)
{
#ifdef MAP
    cout << "Appel au constructeur de <CollectionTrajets>" << endl;
#endif
    //TrajetTab == tableau de pointeurs de trajet
    this->TrajetTab = trajetTabP;
    this->cardAct = sizep;
    this->cardMax = sizep;
} //----- Fin de CollectionTrajets

CollectionTrajets::~CollectionTrajets()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CollectionTrajets>" << endl;
#endif
    unsigned int i;
    for (i = 0; i < cardAct; i++)
    {
        delete TrajetTab[i];
    }
    delete[] TrajetTab;
} //----- Fin de ~CollectionTrajets



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void CollectionTrajets::ajuster(int delta)
{
    if (cardMax + delta < cardAct)
        cardMax = cardAct;
    else
        cardMax = cardMax + delta;
    Trajet **newTrajetTab = new Trajet *[cardMax];
    for (unsigned int i = 0; i < cardAct; ++i)
        newTrajetTab[i] = TrajetTab[i];
    delete[] TrajetTab;
    TrajetTab = newTrajetTab;
}

bool CollectionTrajets::conditionSauvegarde(int filtre, int index, char* ville, int borneInf, int borneSup) {
    if (filtre == 1) {
        return true;
    }
    else if (filtre == 2 && TrajetTab[index]->getNbTrajets() == 0) {
        return true;
    }
    else if (filtre == 3 && TrajetTab[index]->getNbTrajets() != 0) {
        return true;
    }
    else if (filtre == 4 && TrajetTab[index]->ComparerDepart(ville)) {
        return true;
    }
    else if (filtre == 5 && TrajetTab[index]->ComparerArrivee(ville)) {
        return true;
    }
    else if (filtre==6 && index >= (borneInf - 1) && index <= (borneSup - 1)){
        return true;
    }
    return false;
}
