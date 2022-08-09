/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if !defined(TRAJET_H)
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//classe abstraite --> jamais instancié
// contenir les trajets
//Classe parent des classes TrajetSimple et TrajetComposé
//------------------------------------------------------------------------

class Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    
    char *depart;
    char *arrivee;
    //-------------------------------------------- Constructeurs - destructeur
  
    Trajet(char *departp, char *arriveep);
    /// Mode d'emploi :
    // constructeur avec comme paramètres
    // les villes de départ (d) et d'arrivée (a) qui sont des chaînes de 
    // caractères 
    //paramètres dont vont hériter les classes enfants

    Trajet();
    virtual ~Trajet();
    // Mode d'emploi :
    //destructeur 
    
    bool ComparerDepart(char* pDepart);
    // Mode d'emploi :
    // Comparaison de deux chaines de caractères
    // en paramètre la chaine que l'on souhaite comparer avec le depart 
    // du trajet

    bool ComparerArrivee(char* pArrivee);
    // Mode d'emploi :
    // Comparaison de deux chaines de caractères
    // en paramètre la chaine que l'on souhaite comparer avec l'arrivee 
    // du trajet

    virtual void Afficher() const = 0;
    //methode virtuelle pure 
    //permet que la classe Trajet ne soit pas instanciable

    virtual string Sauver() const =0;
    // methode virtuelle pure

    virtual int getNbTrajets() const = 0;

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};


#endif // XXX_H
