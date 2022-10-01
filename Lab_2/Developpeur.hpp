#pragma once
#include <string>
#include "ListeJeux.hpp"
#include <string>

using namespace std;

class Developpeur
{
	//TODO: En faire une classe qui suit les principes OO.
public:
	Developpeur(string name)
	{
		name_ = name;
		ListeJeux listeJeux = {};
		paireNomJeux_ = {obtenirNom(), listeJeux};
	}

	string obtenirNom() const;
	int obtenirNombreJeuxDeveloppes(ListeJeux listeJeux);
	ListeJeux mettreAJourListeJeux(ListeJeux listeJeuxComplete);
	void afficherListeJeuxDeveloppes(ListeJeux listeJeuxDeveloppes);

private:
	string name_;
	/* Quel type doit etre ici? */ paireNomJeux_[2];
	int nombreJeuxDeveloppes_;
};

//TODO: La destruction d'un Developpeur doit s'assurer que la désallocation de ListeJeux est faite.
Developpeur::~Developpeur()
{
	//Desallocation ici
};

//TODO: Les méthodes à faire...
string Developpeur::obtenirNom() const
{
	return name_;
}

int Developpeur::obtenirNombreJeuxDeveloppes(ListeJeux listeJeux)
{
	//TODO
}

ListeJeux mettreAJourListeJeux(ListeJeux listeJeuxComplete)
{
	//TODO
}

void afficherListeJeuxDeveloppes(ListeJeux listeJeuxDeveloppes)
{
	int i = 0;
	for (auto i : listeJeuxDeveloppes)
	{
		//TODO
	}

}

std::pair<std::string, ListeJeux> paireNomJeux_;
};
