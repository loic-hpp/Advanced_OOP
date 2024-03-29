﻿//	Déclaration de la classe ListeDeveloppeurs. 
//	Fichier:  ListeDeveloppeurs.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	2 octobre 2022
//	Créé le 26 septembre 2022

#pragma once
#include <cstddef>
#include <iostream>
#include "Developpeur.hpp"
#include "ListeJeux.hpp"
#include <string>

class ListeDeveloppeurs
{
public:
	ListeDeveloppeurs(int nElements = 0, int capacite = 0, Developpeur** elements = nullptr);
	~ListeDeveloppeurs();
	void afficher();
	void ajouterDeveloppeur(Developpeur* developpeur);
	void retirerDeveloppeur(Developpeur* developpeurParametre);

private:
	std::size_t nElements_, capacite_;
	Developpeur** elements_;
	void changerTailleListeDeveloppeurs();
	bool estDansListeDeveloppeur(std::string nom);
};
