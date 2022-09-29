#pragma once
#include <string>
#include "ListeJeux.hpp"
#include <string>

using namespace std;

class Developpeur
{
	//TODO: En faire une classe qui suit les principes OO.
public:
	Developpeur(ListeJeux listeJeux);
	string obtenirNom() const;
	int obtenirNombreJeuxDeveloppes(ListeJeux listeJeux);
	ListeJeux mettreAJourListeJeux(ListeJeux listeJeuxComplete);

private:
	string name_;
	string paireNomJeux_;
	int nombreJeuxDeveloppes;
};

//TODO: La destruction d'un Developpeur doit s'assurer que la désallocation de ListeJeux est faite.
~Developpeur() {};

//TODO: Les méthodes à faire...
string Developpeur::obtenirNom() const
{
	//TODO	
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
