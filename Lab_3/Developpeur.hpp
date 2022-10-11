//	Déclaration de la classe Developpeur. 
//	Fichier:  Developpeur.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	2 octobre 2022
//	Créé le 26 septembre 2022

#pragma once
#include <string>
#include <iostream>
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
	Developpeur(std::string nomDeveloppeur, ListeJeux listeJeux = {});
	~Developpeur();
	int nombreDinstances();
	std::string nomDeveloppeur();
	std::string getNom() { return paireNomJeux_.first; }
	int participationJeux(const ListeJeux& listeJeux);
	void mettreAJourListe(ListeJeux listeJeux);
	void afficherDeveloppeur();

private:
	std::pair<std::string, ListeJeux> paireNomJeux_;
	bool estDeveloppeur(const ListeJeux& listeJeux);
	int compteur = 0;	//Compteur d'instances
};
