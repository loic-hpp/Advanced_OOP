<<<<<<< HEAD
//	Definition de la classe abstraite Affichable.
//	Fichier:  Liste.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	8 novembre 2022
//	Créé le 6 novembre 2022

#pragma once
#include "Couleur.hpp"
#include <string>
#include <iostream>
using namespace std;

class Affichable {
public:
	virtual ~Affichable() = default;
	virtual void afficher(std::ostream& os) const = 0;
	// couleurAffichage peut aussi etre char our char[]
	virtual void changerCouleur(std::ostream& os, const int couleurAffichage) const = 0;
};
=======
//	Description: Définition de la classe interface Affichable
//	Fichier: Affichable.hpp
//	Auteurs  Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	07 novembre 2022
//	Créé le 8 novembre 2022

#pragma once
#include <iostream>
#include <vector>
class Affichable
{
public:
	virtual void afficher(std::ostream& os) const = 0;
	virtual void changerCouleur(std::ostream& os, const std::string& couleur) const = 0;
	virtual ~Affichable() = default;
};

>>>>>>> main
