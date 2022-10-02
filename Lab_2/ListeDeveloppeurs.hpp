#pragma once
#include <cstddef>
#include <iostream>
#include "Developpeur.hpp"
#include "ListeJeux.hpp"
#include <string>


class ListeDeveloppeurs
{
public:
	ListeDeveloppeurs(int nElt = 0, int capacite = 0, Developpeur** element = nullptr);
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
