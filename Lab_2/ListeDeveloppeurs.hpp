#pragma once
#include <cstddef>
#include "Developpeur.hpp"

class ListeDeveloppeurs
{
	//TODO: En faire une classe qui suit les principes OO.
public:
	ListeDeveloppeurs();

private:
	std::size_t nElements, capacite;
	Developpeur** elements;
};

// TODO: On veut pouvoir ajouter et enlever un Developpeur* de la liste, 
// avec réallocation dynamique tel que faite pour ListeJeux.
ListeDeveloppeurs::~ListeDeveloppeurs()
{
	// Liberer
}

void afficher(ListeJeux listeJeux)
{
	//TODO
}

void ajouterDeveloppeur(ListeJeux listeJeux) 
{
	//TODO
}

void retirerDeveloppeur(ListeJeux listeJeux)
{
	//TODO
}

//NOTE: Le code sera principalement copié de certaines fonctions écrites pour la partie 1, mais mises dans une classe.
};
