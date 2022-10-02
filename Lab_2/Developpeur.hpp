#pragma once
#include <string>
#include "ListeJeux.hpp"
#include "Jeu.hpp"
#include "gsl/span"
#include "cppitertools/range.hpp"

class Developpeur
{
	//TODO: En faire une classe qui suit les principes OO.
	
	//TODO: La destruction d'un Developpeur doit s'assurer que la désallocation de ListeJeux est faite.
	
	//TODO: Les méthodes à faire...
public:
	Developpeur(std::string nomDeveloppeur, ListeJeux listejeux = {});
	~Developpeur();
	int nombreDinstances();
	std::string nomDeveloppeur();
	int participationJeux(const ListeJeux& listejeux);
	void mettreAJourListe(ListeJeux listeJeux);
	
private:
	std::pair<std::string, ListeJeux> paireNomJeux_;
	bool estDeveloppeur(const ListeJeux& listeJeux);
	int compteur = 0;
};