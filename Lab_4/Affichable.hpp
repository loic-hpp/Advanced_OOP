#pragma once
#include "Couleur.hpp"
#include <string>
#include <iostream>
using namespace std;

class Affichable {
public:
	// Des m�thodes virtuelles pures -> cr�ent interface pour travailler
	virtual string afficher(string texte) = 0;
	virtual Couleur changerCouleur(Couleur couleur) = 0; // 2e param�tre??

	// Destructeur par d�faut � faire

private:
	Couleur couleur;
};