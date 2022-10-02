﻿#pragma once
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
	
	const size_t obtenirNElements(ListeDeveloppeurs liste) const;
	const size_t obtenirCapacite(ListeDeveloppeurs liste) const;
	const Developpeur** obtenirElements(ListeDeveloppeurs liste) const;
	
	const void modifierNElements(ListeDeveloppeurs liste) const;
	const void modifierCapacite(ListeDeveloppeurs liste) const;
	const void modifierElements(ListeDeveloppeurs liste) const;

private:
	std::size_t nElements_, capacite_;
	Developpeur** elements_;
};

ListeDeveloppeurs::~ListeDeveloppeurs()
{
	// Liberer
	// TODO: On veut pouvoir ajouter et enlever un Developpeur* de la liste, 
	// avec réallocation dynamique tel que faite pour ListeJeux.
}

const size_t ListeDeveloppeurs::obtenirNElements(ListeDeveloppeurs liste) const
{
	return liste.nElements_;
}

const size_t ListeDeveloppeurs::obtenirCapacite(ListeDeveloppeurs liste) const
{
	return liste.capacite_;
}
const Developpeur** ListeDeveloppeurs::obtenirElements(ListeDeveloppeurs liste) const
{
	return liste.elements_;
}

const void ListeDeveloppeurs::modifierNElements(ListeDeveloppeurs liste) const
{
	// TODO
}

const void ListeDeveloppeurs::modifierCapacite(ListeDeveloppeurs liste) const
{
	// TODO
}
const void ListeDeveloppeurs::modifierElements(ListeDeveloppeurs liste) const
{
	// TODO
}

void afficher(ListeJeux listeJeux)
{
	afficherListeJeuxDeveloppes(listeJeux);
}

void ajouterDeveloppeur(ListeDeveloppeurs& listeDeveloppeurs, Developpeur* developpeur)
{
	//TODO: à adapter 
	size_t index = listeDeveloppeurs.nElements;
	if (listeDeveloppeurs.nElements == listeDeveloppeurs.capacite) {
		if (listeDeveloppeurs.capacite == 0)
			index = 0;
		changerTailleListeDeveloppeurs(listeDeveloppeurs);
	}
	listeDeveloppeurs.elements[index] = developpeur;
	listeDeveloppeurs.nElements++;
}

void changerTailleListeDeveloppeurs(ListeDeveloppeurs& listeDeveloppeurs) {
	if (listeDeveloppeurs.capacite == 0)
		listeDeveloppeurs.capacite = 2;
	else
		listeDeveloppeurs.capacite *= 2;
	Developpeur** nouvelleListe = new Developpeur * [listeDeveloppeurs.capacite];
	int i = 0;
	for (Developpeur* developpeur : gsl::span(listeDeveloppeurs.elements, listeDeveloppeurs.nElements)) {
		nouvelleListe[i] = developpeur;
		i++;
	}
	delete[] listeDeveloppeurs.elements;
	listeDeveloppeurs.elements = nullptr;
	listeDeveloppeurs.elements = nouvelleListe;
}

void retirerDeveloppeur(ListeDeveloppeurs& listeDeveloppeurs, Developpeur* developpeurParametre)
{
	int i = 0;
	for (Developpeur*& developpeur : gsl::span(listeDeveloppeurs.elements, listeDeveloppeurs.nElements)) {
		if (developpeurParametre == developpeur)
			listeDeveloppeurs.elements[i] = listeDeveloppeurs.elements[listeDeveloppeurs.nElements - 1];
		i++;
	}
	listeDeveloppeurs.elements[listeDeveloppeurs.nElements - 1] = nullptr;
	listeDeveloppeurs.nElements--;
}
//NOTE: Le code sera principalement copié de certaines fonctions écrites pour la partie 1, mais mises dans une classe.
