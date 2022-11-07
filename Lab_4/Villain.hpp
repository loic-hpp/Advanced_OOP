//	Definition de la classe Villain.
//	Fichier:  Liste.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	8 novembre 2022
//	Créé le 6 novembre 2022

#pragma once
#include <string>
#include "Personnage.hpp"
#include <vector>

using namespace std;

class Villain : virtual public Personnage
{
public:
	Villain(string& nom, string& parution, string& objectif);
	void afficher(std::ostream& os) const override;
	void changerCouleur(std::ostream& os, const int couleurAffichage) const override;
	string obtenirNom() const override;
	string obtenirParution() const override;

	virtual void obtenirObjectif() const;
	virtual void afficherObjectif(ostream& os, int& couleur) const;

	virtual ~Villain() = default;
private:
	string objectif_;
};
