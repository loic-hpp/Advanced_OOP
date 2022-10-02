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
		listeDeveloppeurs.capacite_ = 0;
		listeDeveloppeurs.nElements_ = 0;
	}
	
	size_t obtenirNElements() const;
	size_t obtenirCapacite() const;
	Developpeur** obtenirElements(int index) const;
	
	void modifierNElements(size_t nouveauNElements);
	void modifierCapacite(size_t nouvelleCapacite);
	void modifierElements(ListeDeveloppeurs liste);

	void afficher(ListeJeux listeJeux);
	void ajouterDeveloppeur(ListeDeveloppeurs& listeDeveloppeurs, Developpeur* developpeur);
	void changerTailleListeDeveloppeurs(ListeDeveloppeurs& listeDeveloppeurs);
	void retirerDeveloppeur(ListeDeveloppeurs& listeDeveloppeurs, Developpeur* developpeurParametre);

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

size_t ListeDeveloppeurs::obtenirNElements() const
{
	return nElements_;
}

size_t ListeDeveloppeurs::obtenirCapacite() const
{
	return capacite_;
}

Developpeur** ListeDeveloppeurs::obtenirElements(int index) const
{    
	
}

void ListeDeveloppeurs::modifierNElements(size_t nouveauNElements)
{
	nElements_ = nouveauNElements;
}

void ListeDeveloppeurs::modifierCapacite(size_t nouvelleCapacite)
{
	capacite_ = nouvelleCapacite;
}

void ListeDeveloppeurs::modifierElements(ListeDeveloppeurs listeDeveloppeurs)
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
	size_t index = listeDeveloppeurs.obtenirNElements();
	if (listeDeveloppeurs.obtenirNElements() == listeDeveloppeurs.obtenirCapacite()) {
		if (listeDeveloppeurs.obtenirCapacite() == 0)
			index = 0;
		changerTailleListeDeveloppeurs(listeDeveloppeurs);
	}
	listeDeveloppeurs.elements[index] = developpeur;
	listeDeveloppeurs.modifierNElements(listeDeveloppeurs.obtenirNElements() + 1);
}

void changerTailleListeDeveloppeurs(ListeDeveloppeurs& listeDeveloppeurs)
{
	if (listeDeveloppeurs.obtenirCapacite() == 0)
		listeDeveloppeurs.modifierCapacite(1);
	else
		listeDeveloppeurs.modifierCapacite(listeDeveloppeurs.obtenirCapacite() * 2);
	Developpeur** nouvelleListe = new Developpeur * [listeDeveloppeurs.obtenirCapacite()];
	int i = 0;
	for (Developpeur* developpeur : gsl::span(listeDeveloppeurs.elements, listeDeveloppeurs.obtenirNElements())) {
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
	for (Developpeur*& developpeur : gsl::span(listeDeveloppeurs.elements, listeDeveloppeurs.obtenirNElements())) {
		if (developpeurParametre == developpeur)
			listeDeveloppeurs.elements[i] = listeDeveloppeurs.elements[listeDeveloppeurs.obtenirNElements() - 1];
		i++;
	}
	listeDeveloppeurs.elements[listeDeveloppeurs.modifierNElements(listeDeveloppeurs.obtenirNElements() - 1)] = nullptr;
	listeDeveloppeurs.modifierNElements(listeDeveloppeurs.obtenirNElements() - 1);
}
//NOTE: Le code sera principalement copié de certaines fonctions écrites pour la partie 1, mais mises dans une classe.
