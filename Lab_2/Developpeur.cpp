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
	for (int i = 0; i < listeJeux.nElements; i++) {
	if (Developpeur::estDeveloppeur(listeJeux))
		participation++;
	}
	return participation;
}

void Developpeur::mettreAJourListe(ListeJeux listeJeux) {
	paireNomJeux_.second.elements = new Jeu * [Developpeur::participationJeux(listeJeux)];
	paireNomJeux_.second.capacite = participationJeux(listeJeux);
	paireNomJeux_.second.nElements = 0;
	for(size_t i : iter::range(listeJeux.nElements)){
		if (Developpeur::estDeveloppeur(listeJeux))
			paireNomJeux_.second.elements[i] = listeJeux.elements[i];
		paireNomJeux_.second.nElements++;
	}

}

void Developpeur::afficheListeJeuxDev() {
	std::cout << "\nVoici la liste de jeu du d�veloppeur: " << paireNomJeux_.first << "\n" << std::endl;
	afficherListeJeux(paireNomJeux_.second);
}
