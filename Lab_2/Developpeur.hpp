#pragma once
#include <string>
#include <iostream>
#include "ListeJeux.hpp"
#include "Jeu.hpp"
#include "gsl/span"
#include "cppitertools/range.hpp"
#include "main.cpp" // Techniquement je n'ai pas le droit de faire cette ligne 
//Mais je n'ai pas eu le choix car pour afficher la liste de dévellopeur,
//J'ai besoin d'afficher la liste des jeux de chaque developpeur alors que ces fonctions sont dans le main
// Mes seuls options étaient de soit les redéfinir soit importer le main

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
	void afficheListeJeuxDev();
	
private:
	std::pair<std::string, ListeJeux> paireNomJeux_;
	bool estDeveloppeur(const ListeJeux& listeJeux);
	int compteur = 0;
};
