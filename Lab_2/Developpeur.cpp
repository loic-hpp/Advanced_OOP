//	Implementation de la classe Developpeur.
//	Fichier:  Developpeur.cpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	2 octobre 2022
//	Créé le 26 septembre 2022

#include "Developpeur.hpp"

Developpeur::~Developpeur() {
	delete[] paireNomJeux_.second.elements;
	compteur--;
}

Developpeur::Developpeur(std::string nom, ListeJeux liste) {
	paireNomJeux_.first = nom;
	paireNomJeux_.second = liste;
	compteur++;
}

int Developpeur::nombreDinstances() { return compteur; }

std::string Developpeur::nomDeveloppeur() { return paireNomJeux_.first; }

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
	for (size_t i : iter::range(listeJeux.nElements)) {
		if (Developpeur::estDeveloppeur(listeJeux))
			paireNomJeux_.second.elements[i] = listeJeux.elements[i];
		paireNomJeux_.second.nElements++;
	}
}

void Developpeur::afficherDeveloppeur() {
	std::cout << "\nVoici la liste des jeux pour: " << paireNomJeux_.first << std::endl;
	for (int i = 0; i < paireNomJeux_.second.nElements; i++) {
		std::cout << "\n\t- " << paireNomJeux_.second.elements[i]->titre << std::endl;
	}
}

