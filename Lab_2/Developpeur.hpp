#pragma once
#include <string>
#include "ListeJeux.hpp"
#include <string>
#include <gsl/span>
#include <iostream>
#include <cppitertools/range.hpp>

using namespace std;

class Developpeur
{
	//TODO: En faire une classe qui suit les principes OO.
public:
	Developpeur()
	{
		ListeJeux listeJeuxDeveloppes = {}; // Repétitif avec autre constructeur
		nom_ = "inconnu";
		paireNomJeux_ = { obtenirNom(), listeJeuxDeveloppes};
		nJeuxDeveloppes_ = 0;
	}

	Developpeur(const string& nom)
	{
		ListeJeux listeJeuxDeveloppes = {};
		nom_ = nom;
		paireNomJeux_ = { obtenirNom(), listeJeuxDeveloppes };
		nJeuxDeveloppes_ = 0;
	};

	const string obtenirNom() const;
	int obtenirNombreJeuxDeveloppes(ListeJeux listeJeux);
	ListeJeux mettreAJourListeJeux(ListeJeux listeJeuxComplete);
	void afficherListeJeuxDeveloppes(ListeJeux listeJeuxDeveloppes);

private:
	string nom_;
	std::pair<std::string, ListeJeux> paireNomJeux_;
	int nJeuxDeveloppes_;
};

Developpeur::~Developpeur()
{
	delete[] paireNomJeux_.second; // Comment faire ici?
	//TODO: La destruction d'un Developpeur doit s'assurer que la désallocation 
	// de ListeJeux est faite.
};

const string Developpeur::obtenirNom() const
{
	return nom_;
}

// La méthode s’applique sur un développeur et reçoit la liste des jeux dans 
// laquelle compter le nombre de fois où on trouve ce développeur.
int Developpeur::obtenirNombreJeuxDeveloppes(ListeJeux listeJeuxDeveloppes)
{
	for (Jeu*& jeu : gsl::span(listeJeuxDeveloppes.elements, listeJeuxDeveloppes.nElements))
	{
		if (jeu->developpeur == obtenirNom()) 
		{
			nJeuxDeveloppes_++;
		}
	}
	return nJeuxDeveloppes_;
}

ListeJeux mettreAJourListeJeux(ListeJeux listeJeuxComplete)
{
	// TODO: Doit utiliser obtenirNombreJeuxDeveloppes() pour eviter de faire plusieurs réallocations
	// pendant que les jeux developpes par ce developpeur sont ajoutés a la liste.
}

void afficherListeJeuxDeveloppes(const ListeJeux& listeJeuxDeveloppes, Jeu* jeu)
{
	for (Jeu*& jeu : gsl::span(listeJeuxDeveloppes.elements, listeJeuxDeveloppes.nElements)) {
		cout << "\nInformations" << endl;
		cout << "\n\t" << jeu->titre << endl; //erreur dans jeu ici?
		cout << "\n_____________________________________________________\n";
	}
}
