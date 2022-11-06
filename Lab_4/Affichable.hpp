#pragma once
#include "Couleur.hpp"
#include <string>
#include <iostream>
using namespace std;

class Affichable {
public:
	virtual ~Affichable() = default;
	virtual string afficher(string texte) = 0;
	// couleurAffichage peut aussi etre char our char[]
	virtual Couleur changerCouleur(Couleur couleur, int couleurAffichage) = 0;

private:
	Couleur couleur;
};