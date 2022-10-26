#pragma once
#include "Couleur.hpp"
#include <string>
#include <iostream>
using namespace std;

class Affichable {
public:
	// Des méthodes virtuelles pures -> créent interface pour travailler
	virtual string afficher(string texte) = 0;
	virtual Couleur changerCouleur(Couleur couleur) = 0; // 2e paramètre??

	// Destructeur par défaut à faire

private:
	Couleur couleur;
};