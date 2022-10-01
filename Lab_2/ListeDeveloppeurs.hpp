#pragma once
#include <cstddef>
#include "Developpeur.hpp"

class ListeDeveloppeurs
{
	//TODO: En faire une classe qui suit les principes OO.
public:
	ListeDeveloppeurs()
	{
		ListeDeveloppeurs listeDeveloppeurs = {};
	}

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
	afficherListeJeuxDeveloppes(listeJeux);
}

void ajouterDeveloppeur(ListeJeux& listeJeux, Developpeur* developpeur)
{
	//TODO: à adapter 
	size_t index = listeJeux.nElements;
	if (listeJeux.nElements == listeJeux.capacite) {
		if (listeJeux.capacite == 0)
			index = 0;
		changerTailleListeJeux(listeJeux);
	}
	listeJeux.elements[index] = developpeur;
	listeJeux.nElements++;
}

void changerTailleListeJeux(ListeJeux& listeJeux) {
	if (listeJeux.capacite == 0)
		listeJeux.capacite = 2;
	else
		listeJeux.capacite *= 2;
	Developpeur** nouvelleListe = new Developpeur * [listeJeux.capacite];
	int i = 0;
	for (Developpeur* developpeur : gsl::span(listeJeux.elements, listeJeux.nElements)) {
		nouvelleListe[i] = developpeur;
		i++;
	}
	delete[] listeJeux.elements;
	listeJeux.elements = nullptr;
	listeJeux.elements = nouvelleListe;
}

void retirerDeveloppeur(ListeJeux& listeJeux, Developpeur* developpeur)
{
	int i = 0;
	for (Jeu*& jeu : gsl::span(listeJeux.elements, listeJeux.nElements)) {
		if (developpeur == jeu)
			listeJeux.elements[i] = listeJeux.elements[listeJeux.nElements - 1];
		i++;
	}
	listeJeux.elements[listeJeux.nElements - 1] = nullptr;
	listeJeux.nElements--;
}
//NOTE: Le code sera principalement copié de certaines fonctions écrites pour la partie 1, mais mises dans une classe.
