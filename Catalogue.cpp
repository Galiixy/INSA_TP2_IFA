/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"
#include "CollectionTrajets.h"
#include "Catalogue.h"

#pragma warning(disable : 4996)
#pragma warning(disable : 4703)
//------------------------------------------------------------- Constantes
const int CHARMAX = 256;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue()
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    this->trajetTableauCollection = new CollectionTrajets();
}

Catalogue::~Catalogue()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
delete trajetTableauCollection;
} //----- Fin de ~Catalogue

void Catalogue::Afficher()
{
    this->trajetTableauCollection->Afficher();
}

void Catalogue::Rechercher(char *depart, char *arrivee)
{
    unsigned int i;
    cout << "Resultat de la recherche : " << endl;
    unsigned int compteur = 0;
    for (i = 0; i < this->trajetTableauCollection->cardAct; i++)
    {
        //comparaison des parametres avec chaque trajet
        if (strcmp(trajetTableauCollection->TrajetTab[i]->depart, depart) == 0 
            && strcmp(trajetTableauCollection->TrajetTab[i]->arrivee, arrivee) == 0)
        {
            compteur++;
            cout << "Trajet " << compteur << " : " << endl;
            trajetTableauCollection->TrajetTab[i]->Afficher();
        }
    }
    if (compteur == 0)
    {
        cout << "Aucun trajet trouvé " << endl;
    }
}

void Catalogue::AjouterSimple(char *depart, char *arrivee, Transport transp)
{
    //ajout d'un trajet dans l'attribut de la classe CollectionTrajets
    trajetTableauCollection->AjouterSimple(depart, arrivee, transp);
}

void Catalogue::AjouterCompose(Trajet **traj, int sizep, char *depart, char *arrivee)
{
    //traj == liste de trajets simple
    trajetTableauCollection->AjouterCompose(traj, sizep, depart, arrivee);
}
void Catalogue::Charger(int filtre, int argc, char ** argv) {
    char nomFic[CHARMAX];
    cout << "Veuillez entrer le nom de votre fichier de chargement textuel." << endl;
    cout << "Taper FichierCatalogue si vous n'en n'avez pas : ";
    cin >> nomFic;
    
   
    ifstream monFlux(nomFic);
    if (monFlux)
    {
        char villeChoisiPourFiltre[CHARMAX];
        int borneInf, borneSup;
        if (filtre == 4 or filtre == 5)
        {
            cout << "Veuillez entrer la ville de votre choix : ";
            cin >> villeChoisiPourFiltre;
        }
        else if (filtre == 6)
        {
            cout << "Veuiller entrer la borne inférieure (a partir de 1): " << endl;
            cin >> borneInf;
            cout << "Veuiller entrer la borne supérieure (jusqu'a l'index maximum +1): " << endl;
            cin >> borneSup;
        }
        int indice;
        int compteurParam;
        int compteurTrajet;
        int nbTrajets;
        char departSimple[CHARMAX];
        char departCompose[CHARMAX];
        char arriveeSimple[CHARMAX];
        char arriveeCompose[CHARMAX];
        char moyenTransport[CHARMAX];
        Transport choixTransport;
        Trajet** tabTrajetSimple;

        //SPLIT
        string ligne;
        while (getline(monFlux, ligne))
        { //On lit une ligne complète

            stringstream ss(ligne);
            string token;

            /*initialisation des variables*/
            nbTrajets = 0;
            compteurParam = 0;
            compteurTrajet = 0;
            choixTransport = Transport::VOITURE;

            while (getline(ss, token, ';'))
            {
                switch (compteurParam)
                {
                case 0:
                    indice = atoi(token.c_str());
                    break;
                case 1:
                    nbTrajets = atoi(token.c_str());
                    if (nbTrajets > 0)
                    { // si trajet compose, creation d'un tableau
                        compteurTrajet = 0;
                        tabTrajetSimple = new Trajet * [nbTrajets];
                    }
                    break;
                case 2:
                    strcpy(departSimple, token.c_str());
                    if (compteurTrajet == 0 && nbTrajets != 0)
                    { // 1ere ville de depart de trajet compose
                        strcpy(departCompose, departSimple);
                    }
                    break;
                case 3:
                    strcpy(arriveeSimple, token.c_str());
                    if (compteurTrajet == nbTrajets && nbTrajets != 0)
                    { // 1ere ville de depart de trajet compose
                        strcpy(arriveeCompose, arriveeSimple);
                    }
                    break;

                case 4:
                    strcpy(moyenTransport, token.c_str());
                    choixTransport = (Transport)TrajetSimple::GetTransport(moyenTransport);
                    if (nbTrajets > 0)
                    {
                        tabTrajetSimple[compteurTrajet] = new TrajetSimple(departSimple, arriveeSimple, choixTransport);
                        compteurTrajet++;
                        compteurParam = 1;
                    }
                    break;
                }
                compteurParam++;
            }

            // Ajout du trajet en fonction du filtre
            if (filtre == 1) //catalogue entier
            {
                if (nbTrajets == 0)
                {
                    AjouterSimple(departSimple, arriveeSimple, choixTransport);
                }
                else
                {
                    AjouterCompose(tabTrajetSimple, nbTrajets + 1, departCompose, arriveeCompose);
                }
            }
            else if (filtre == 2) //Que les trajets simples
            {
                if (nbTrajets == 0)
                {
                    AjouterSimple(departSimple, arriveeSimple, choixTransport);
                }
            }
            else if (filtre == 3) //Que les trajets composés
            {
                if (nbTrajets > 0)
                {
                    AjouterCompose(tabTrajetSimple, nbTrajets + 1, departCompose, arriveeCompose);
                }
            }
            else if (filtre == 4) //Selon ville de départ
            {
                if (nbTrajets == 0)
                {
                    if (strcmp(departSimple, villeChoisiPourFiltre) == 0)
                    {
                        AjouterSimple(departSimple, arriveeSimple, choixTransport);
                    }
                }
                else
                {
                    if (strcmp(departCompose, villeChoisiPourFiltre) == 0)
                    {

                        AjouterCompose(tabTrajetSimple, nbTrajets + 1, departCompose, arriveeCompose);
                    }
                }
            }
            else if (filtre == 5) //Selon ville d'arrivée
            {
                if (nbTrajets == 0)
                {
                    if (strcmp(arriveeSimple, villeChoisiPourFiltre) == 0)
                    {
                        AjouterSimple(departSimple, arriveeSimple, choixTransport);
                    }
                }
                else
                {
                    if (strcmp(arriveeCompose, villeChoisiPourFiltre) == 0)
                    {

                        AjouterCompose(tabTrajetSimple, nbTrajets + 1, departCompose, arriveeCompose);
                    }
                }
            }
            else if (filtre == 6) //Selon une intervalle
            {

                if (indice >= (borneInf - 1) && indice <= (borneSup - 1))
                {
                    cout << "indice : " << indice << endl;
                    if (nbTrajets == 0)
                    {
                        AjouterSimple(departSimple, arriveeSimple, choixTransport);
                    }
                    else
                    {
                        AjouterCompose(tabTrajetSimple, nbTrajets + 1, departCompose, arriveeCompose);
                    }
                }
            }
        }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    monFlux.close();

}
void Catalogue::Sauvegarder(int filtre) {
    char nomFic[CHARMAX];
    cout << "Veuillez entrer le nom de la future sauvegarde : ";
    cin >> nomFic;
    
    ofstream fic(nomFic);
   if ((fic.rdstate() & ifstream::failbit) != 0)
    {
        cerr << "Erreur d’ouverture de "<<nomFic << endl;
    }
    else {
       fic << trajetTableauCollection->Sauvegarder(filtre); 
    }
    fic.close();
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées