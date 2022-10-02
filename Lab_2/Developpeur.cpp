#include "Developpeur.hpp"

Developpeur::~Developpeur() {
	delete[] paireNomJeux_.second.elements;
	//delete this;
	compteur--;
}

Developpeur::Developpeur(std::string nom, ListeJeux liste){
	paireNomJeux_.first = nom;
	paireNomJeux_.second = liste;
	compteur++;
}

int Developpeur::nombreDinstances() { return compteur; }

std::string Developpeur::nomDeveloppeur() { return paireNomJeux_.first;}

int Developpeur::participationJeux(ListeJeux listeJeux) {
	int participation = 0;
	for(Jeu*& jeu : gsl::span(listeJeux.elements, listeJeux.nElements))
	{
		for (Jeu*& jeuDeveloppeur : gsl::span(paireNomJeux_.second.elements, paireNomJeux_.second.nElements)) {
			if (jeuDeveloppeur->titre == jeu->titre)
				participation++;
		}
	}
	return participation;
}
