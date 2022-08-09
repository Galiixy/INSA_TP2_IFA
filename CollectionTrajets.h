
/*************************************************************************
                           CollectionTrajets  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//------- Interface de la classe <CollectionTrajets> (fichier CollectionTrajets.h) 
#if !defined(COLLECTIONTRAJETS_H)
#define COLLECTIONTRAJETS_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CollectionTrajets>
// Modèle de tableau dynamique qui a pour but de factoriser le code et éviter
// la réecriture de code
//
//------------------------------------------------------------------------

class CollectionTrajets
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    unsigned int cardAct;
    unsigned int cardMax;

    CollectionTrajets(unsigned int cardinalMax);
    CollectionTrajets();
    CollectionTrajets(Trajet **trajetTabP, int sizep);
    // paramètres : tableau de pointeur de trajet + taille du tableau
    // Mode d'emploi : initialise un objet type collection de trajet

    virtual ~CollectionTrajets();

    Trajet **TrajetTab;

    void Afficher();

    void AjouterSimple(char *depart, char *arrivee, Transport transp);

    void AjouterCompose(Trajet **traj, int sizep, char *depart, char *arrivee);

    unsigned int getTaille();

    string Sauvegarder(int filtre);

    string Sauvegarder();
    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    void ajuster(int delta);
    // type Méthode ( liste des paramètres );
    // Mode d'emploi : à utiliser à chaque appel de la fonction ajuster afin d'ajuster
    // cardMAx avec cardAct
    bool conditionSauvegarde(int filtre, int index, char *ville, int borneInf, int borneSup);
    //----------------------------------------------------- Attributs protégés
};

#endif // XXX_H
