/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if !defined(TRAJETSIMPLE_H)
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
// Enumeration permettant le choix des différents moyens de transports
enum Transport
{
    TRAIN,
    AVION,
    BATEAU,
    VOITURE,
    MOTO,
    BUS
};
static const char* const TransportValues[] = { "Train", "Avion", "Bateau", "Voiture", "Moto", "Bus"};
//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Classe enfant de Trajet stockant un trajet entre 2 villes 
// avec un moyen de transport
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    virtual void Afficher()const;
    // Mode d'emploi :
    // méthode servant à afficher les attributs de l'objet appelé

    virtual string Sauver()const;
    // Mode d'emploi
    // méthode retournant la valeur de sauvegarde du trajet simple

    virtual int getNbTrajets()const;

    static void ListerTransports();
    // Mode d'emploi :
    // méthode de classe permettant l'affichage des moyens de transport
    // notamment pour simplifier la sélection par l'utilisateur

    static int GetTransport(char* moyenTransport);
    // Mode d'emploi :
    // Méthode de classe permettant d'obtenir l'enumeration Transport 
    // a partir d'une chaine de caracteres

    //-------------------------------------------- Constructeurs - destructeur

    TrajetSimple(char *d, char *a, Transport m);
    // Mode d'emploi :
    // constructeur avec comme paramètres
    // les villes de départ (d) et d'arrivée (a) qui sont des chaînes de 
    // caractères et qui seront définies avec l'appel au constructeru de Trajet
    // le moyen de transport pour le trajet (m) 
    // du type Transport, énumeration créée au préalable

    virtual ~TrajetSimple();
    // Mode d'emploi :
    // destructeur de la classe servant uniquement pour la mise au point


    //------------------------------------------------------------------ PRIVE
protected:
    //----------------------------------------------------- Attributs protégés
    Transport moyenTransport;

    //----------------------------------------------------- Méthodes protégées
};

#endif // TRAJETSIMPLE_H
