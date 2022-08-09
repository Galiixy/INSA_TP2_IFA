/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if !defined(CATALOGUE_H)
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//contenir les différents trajets grâce à l'attribut trajetTableauCollection
// qui contient un tableau dynamique géré par la classe CollectionTrajets
//
//------------------------------------------------------------------------

class Catalogue
{
    //----------------------------------------------------------------- PUBLIC

public:
    CollectionTrajets *trajetTableauCollection;

    //-------------------------------------------- Constructeurs - destructeur

    Catalogue(CollectionTrajets traj);
    // Mode d'emploi : intialise un objet de type catalogue 
    Catalogue();

    virtual ~Catalogue();

    //------------------------------------------------------------------ PRIVE
    void Afficher();
    void AjouterSimple(char *depart, char *arrivee, Transport transp);
    void AjouterCompose(Trajet ** traj, int sizep, char *depart, char *arrivee);
    void Rechercher(char *depart, char *arrivee);
    void Charger(int filtre, int argc=0, char ** argv=NULL);
    // Mode d'emploi : 
    // int filtre : numero du chargement
    // int argc : le nombre de parametres associes a ce filtre
    // char * argv : les parametres du filtre
    // Contrat : le filtre doit etre non null
    void Sauvegarder(int filtre);
    // Mode d'emploi : 
    //renseigner la ville de départ et d'arrivée afin de rechercher 
    // Contrat : parametres non null
    //

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H
