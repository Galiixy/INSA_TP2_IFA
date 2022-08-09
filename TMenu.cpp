/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <Xxx> (fichier Xxx.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <vector>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"
#include "CollectionTrajets.h"
#include "TrajetCompose.h"
#include "Catalogue.h"
#include "TMenu.h"

#pragma warning(disable : 4996)
#pragma warning(disable : 4703)
///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes
const int CHARMAX = 256;
// contient le nombre caractères max pour la définition d'un type char*

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

int afficherMenu()
{
  int selection;
  cout << "\nFaites votre choix\n";
  cout << "1. Ajouter un trajet\n";
  cout << "2. Afficher le catalogue\n";
  cout << "3. Chercher un parcours\n";
  cout << "4. Chargement d'un catalogue\n";
  cout << "5. Sauvegarder le catalogue\n";
  cout << "6. Sortir de l'application\n";
  cin >> selection;
  return selection;
} //----- fin de afficherMenu

void afficherCatalogue(Catalogue &catalogue)
{
  catalogue.Afficher();
} //----- fin de afficherCatalogue

void rechercherParcours(Catalogue &catalogue)
// demande à l'utilisateur les villes de départ et arrivée
// pour l'envoyer à Catalogue qui affichera le résultat de recherche
{
  char choixDepart[CHARMAX];
  char choixArrivee[CHARMAX];

  cout << "Ville de départ : ";
  cin >> choixDepart;
  char *depart = new char[strlen(choixDepart) + 1];
  strcpy(depart, choixDepart);

  cout << "Ville d'arrivée : ";
  cin >> choixArrivee;
  char *arrivee = new char[strlen(choixArrivee) + 1];
  strcpy(arrivee, choixArrivee);

  catalogue.Rechercher(depart, arrivee);

  delete[] depart;
  delete[] arrivee;
} //----- fin de recharcherParcours

void ajoutSimple(Catalogue &catalogue)
// création d'un trajet simple avec la demande à l'utilisateur des informations
// pour un trajet simple puis envoie au catalogue
{
  char choixDepart[CHARMAX];
  char choixArrivee[CHARMAX];
  Transport choixTransport;
  int temp;

  cout << "Ville de départ : ";
  cin >> choixDepart;

  cout << "Ville d'arrivée : ";
  cin >> choixArrivee;

  TrajetSimple::ListerTransports();
  cin >> temp;
  choixTransport = (Transport)temp;
  catalogue.AjouterSimple(choixDepart, choixArrivee, choixTransport);
} //----- fin de ajoutSimple

void ajoutCompose(Catalogue &catalogue)
// Mode d'emploi :
// il faut d'abord rentrer le nombre de trajets et ensuite
// renseigner les villes de départ et arrivée et le moyen de transport
// pour chaque trajet
// Algorithme :
// une boucle est lancée avec un nombre d'itérations égale au nombre de trajets
// demandé par l'utilisateur. puis on stocke les informations dans un type
// Trajet** contenant chaque trajet simple pour ensuite l'envoyer au catalogue.
// la ville de départ de chaque trajet suivant devant correspondre à la ville
// d'arrivée du trajet précédent, l'algo pré rempli automatiquement pour
// éviter des erreurs à la saisie
{
  int i;
  int nbTrajets;
  int temp;
  char depart[CHARMAX];
  char arrivee[CHARMAX];
  char choixDepart[CHARMAX];
  char choixArrivee[CHARMAX];
  Transport choixTransport;

  Trajet **tabTrajetSimple;

  cout << "Veuillez renseigner le nombre de trajets à rentrer : ";
  cin >> nbTrajets;

  tabTrajetSimple = new Trajet *[nbTrajets];

  for (i = 0; i < nbTrajets; i++)
  {
    if (i == 0)
    {
      cout << "Ville de départ : ";
      cin >> choixDepart;
    }

    if (i > 0)
    {
      strcpy(choixDepart, choixArrivee);
      cout << "Ville de départ : " << choixDepart << endl;
    }

    cout << "Ville d'arrivée : ";
    cin >> choixArrivee;

    TrajetSimple::ListerTransports();
    cin >> temp;
    choixTransport = (Transport)temp;

    tabTrajetSimple[i] = new TrajetSimple(choixDepart, choixArrivee, choixTransport);
  }
  strcpy(depart, tabTrajetSimple[0]->depart);
  strcpy(arrivee, tabTrajetSimple[nbTrajets - 1]->arrivee);

  catalogue.AjouterCompose(tabTrajetSimple, nbTrajets, depart, arrivee);

} //----- fin de ajoutCompose

void afficherAjout(Catalogue &catalogue)
// affiche les deux types d'ajout et appelle la fonction correspondante
// en fonction du choix utilisateur
// le catalogue est passé en paramètre par référence
// il est possible de revenir au menu précédent
{
  int selection;
  cout << "\nFaites votre choix\n";
  cout << "1. Ajouter un trajet simple\n";
  cout << "2. Ajouter un trajet composé\n";
  cout << "3. Retour\n";
  cin >> selection;
  if (selection == 1)
  {
    ajoutSimple(catalogue);
  }
  else if (selection == 2)
  {
    ajoutCompose(catalogue);
  }
} //----- fin de afficherAjout

void chargement(Catalogue &catalogue)
{
  int selection;
  cout << "\nFaites votre choix\n";
  cout << "1. Charger tout le catalogue\n";
  cout << "2. Charger seulement les trajets simples\n";
  cout << "3. Charger seulement les trajets composés\n";
  cout << "4. Charger selon une ville de depart\n";
  cout << "5. Charger selon une ville d'arrivée\n";
  cout << "6. Charger une intervalle de trajets\n";
  cout << "7. Retour\n";
  cin >> selection;
  if (selection >=1 && selection <=6){
    catalogue.Sauvegarder(selection);
  }
}

void sauvegarde(Catalogue &catalogue)
{
  int selection;
  cout << "\nFaites votre choix\n";
  cout << "1. Sauvegarder tout le catalogue\n";
  cout << "2. Sauvegarder seulement les trajets simples\n";
  cout << "3. Sauvegarder seulement les trajets composés\n";
  cout << "4. Sauvegarder selon une ville de depart\n";
  cout << "5. Sauvegarder selon une ville d'arrivée\n";
  cout << "6. Sauvegarder une intervalle de trajets\n";
  cout << "7. Retour\n";
  cin >> selection;
  
  if (selection >=1 && selection <=6){
    catalogue.Sauvegarder(selection);
  }
}

int main()
// fonction principale
// affiche les différentes possibilités :
// ajouter, afficher, rechercher ou sortir
// et appellle les fonctions correspondantes en fonction du choix
// les fonctions passent toutes le catalogue en paramètre par référence
{
  int navigation = 0;         // variable de choix de l'utilisateur
  Catalogue CatalogueTrajets; // instanciation du catalogue
  cout << "Bienvenue dans notre application de trajets\n";
  while (navigation != 6)
  {
    navigation = afficherMenu();
    switch (navigation)
    {
    case 1:

      afficherAjout(CatalogueTrajets);
      break;
    case 2:
      afficherCatalogue(CatalogueTrajets);
      break;
    case 3:
      rechercherParcours(CatalogueTrajets);
      break;
    case 4:
      chargement(CatalogueTrajets);
      break;
    case 5:
      sauvegarde(CatalogueTrajets);
      break;
    }
  }
  cout << "Au revoir\n";
  return 0;
} //----- fin de main

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
