/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#pragma warning(disable : 4703)
#pragma warning(disable : 4996)
//------------------------------------------------------ Include personnel
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


Trajet::Trajet(char *departp, char *arriveep)
{
    #ifdef MAP
        cout << "Appel au constructeur de <Trajet>" << endl;
    #endif
    this->depart = new char [strlen(departp)+1];
    strcpy(depart, departp);
    this->arrivee = new char [strlen(arriveep)+1];
    strcpy(arrivee, arriveep);
    
} //----- Fin de Trajet

Trajet::~Trajet()
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
delete [] depart;
delete [] arrivee;
} //----- Fin de ~Trajet

bool Trajet::ComparerDepart(char* pDepart)
{
    if (strcmp(pDepart, this->depart) == 0){
        return true;
    }
    return false;
} //----- Fin de ~Trajet

bool Trajet::ComparerArrivee(char* pArrivee)
{
    if (strcmp(pArrivee, this->arrivee) == 0) {
        return true;
    }
    return false;
} //----- Fin de ~Trajet
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées