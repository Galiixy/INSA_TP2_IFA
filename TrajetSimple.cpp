/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//----- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetSimple::Afficher()const
{
    cout << "--Trajet Simple allant de " << depart << " à " << arrivee;
    cout << " avec le moyen de transport : ";
    switch (moyenTransport) // affichage en chaine de caractere 
                            // du moyen de Transport
    {
    case TRAIN:
        cout << "train\n";
        break;
    case AVION:
        cout << "avion\n";
        break;
    case BATEAU:
        cout << "bateau\n";
        break;
    case VOITURE:
        cout << "voiture\n";
        break;
    case MOTO:
        cout << "moto\n";
        break;
    case BUS:
        cout << "bus\n";
        break;
    }
    
} //----- Fin de Méthode

void TrajetSimple::ListerTransports()
{
    cout << TRAIN <<" "<< TransportValues[TRAIN] << endl;
    cout << AVION << " " << TransportValues[AVION] << endl;
    cout << BATEAU << " " << TransportValues[BATEAU] << endl;
    cout << VOITURE << " " << TransportValues[VOITURE] << endl;
    cout << MOTO << " " << TransportValues[MOTO] << endl;
    cout << BUS << " " << TransportValues[BUS] << endl;
} //----- Fin de Méthode

int TrajetSimple::GetTransport(char* moyenTransport) {
    int cpt;
    for (cpt = 0; cpt <=sizeof(Transport)+1; cpt++) {
        if (strcmp(moyenTransport, TransportValues[cpt])==0) {
            return cpt;
        }
    }
    return 0;
}//----- Fin de Méthode

string TrajetSimple::Sauver() const{
    string sauvegarde;
    sauvegarde = (string)depart + ";" + (string)arrivee + ";";
    sauvegarde = sauvegarde + (string)TransportValues[moyenTransport]+";";
    return sauvegarde;
}
int TrajetSimple::getNbTrajets()const {
    return 0;
}

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple(char *d, char *a, Transport t = VOITURE)
    : Trajet(d, a), moyenTransport(t)
// définition des attributs avec le transport défini 
// sur VOITURE si non renseigné
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple()
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
