/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h)
#if !defined(TRAJETCOMPOSE_H)
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Classe enfant de Trajet stockant un trajet entre deux villes avec de
// multiples trajets simples 
// Cette classe possède donc un attribut gardant l'enchaînement de trajets
// simples ainsi que les attributs de la classe mère
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    virtual void Afficher()const;
    // Mode d'emploi :
    // méthode servant à afficher les trajets simple de l'objet appelé
    virtual string Sauver()const;
    virtual int getNbTrajets()const;

//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose(Trajet **trajetsComposesTab, int sizep, char *d, char *a);
    // Mode d'emploi :
    // Constructeur prenant en paramètre :
    // -Un tableau de pointeur de trajets pour initialiser la collection de 
    // trajets simples. Ce tableau de trajet est créé dans la classe du main
    // puis passé en paramètre.
    // -La taille du tableau correspondant au nombre de trajets
    // -Les villes de départ et arrivée pour les définir en appelant
    // le constructeur de la classe mère

    virtual ~TrajetCompose();
    // Mode d'emploi :
    // destructeur servant à libérer la mémoire pour 
    // l'attribut trajetsComposes qui est dynamique
    
    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    CollectionTrajets* trajetsComposes;
    // Attribut contenant les trajets simples composant l'objet
};

#endif // TRAJETCOMPOSE_H
