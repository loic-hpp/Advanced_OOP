#include "Developpeur.hpp"

Developpeur::~Developpeur() {
	delete[] paireNomJeux_.second.elements;
	compteur--;
}

Developpeur::Developpeur(std::string nom, ListeJeux liste){
	paireNomJeux_.first = nom;
	paireNomJeux_.second = liste;
	compteur++;
}

int Developpeur::nombreDinstances() { return compteur; }

std::string Developpeur::nomDeveloppeur() { return paireNomJeux_.first;}

bool Developpeur::estDeveloppeur(const ListeJeux& listeJeux) {
	bool estdev = false;
	for (Jeu*& jeu : gsl::span(listeJeux.elements, listeJeux.nElements))
	{
			if (jeu->developpeur == paireNomJeux_.first)
				estdev = true;
	}
	return estdev;
}

int Developpeur::participationJeux(const ListeJeux& listeJeux) {
	int participation = 0;
	for (Jeu*& jeu : gsl::span(listeJeux.elements, listeJeux.nElements)){
	if (Developpeur::estDeveloppeur(listeJeux))
		participation++;
	}
	return participation;
}

void Developpeur::mettreAJourListe(ListeJeux listeJeux) {
	paireNomJeux_.second.elements = new Jeu * [Developpeur::participationJeux(listeJeux)];
	paireNomJeux_.second.capacite = participationJeux(listeJeux);
	paireNomJeux_.second.nElements = 0;
	int i = 0;
	for (Jeu*& jeu : gsl::span(listeJeux.elements, listeJeux.nElements)) {
		if (Developpeur::estDeveloppeur(listeJeux))
			paireNomJeux_.second.elements[i] = jeu;
		paireNomJeux_.second.nElements++;
		i++;
	}

}
