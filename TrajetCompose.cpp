/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//--- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"
#include "CollectionTrajets.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetCompose::Afficher() const
// Affichage du trajet global puis des trajets simples
{
    cout << "Trajet Composé allant de " << depart << " à " << arrivee;
    cout << " avec les trajets suivants :" << endl;
    cout << "  ";
    trajetsComposes->Afficher();
    
}

string TrajetCompose::Sauver() const{
    return trajetsComposes->Sauvegarder();
}
int TrajetCompose::getNbTrajets() const {
    return trajetsComposes->getTaille()-1;
}

//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose(Trajet **trajetsComposesTab, int sizep, char *d, char *a)
    : Trajet(d, a)
// Création de l'attribut avec l'appel au constructeur de la classe 
// qui stocke les trajets et aussi appel au constructeur parent
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
    trajetsComposes = new CollectionTrajets(trajetsComposesTab, sizep);
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose()
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetCompose>" << endl;
    #endif
    delete trajetsComposes; // suppression de l'attribut dynamique
} //----- Fin de ~TrajetCompose

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
