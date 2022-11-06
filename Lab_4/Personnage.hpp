#pragma once
#include "Affichable.hpp"

class Personnage : public Affichable
{
public:

	string afficher(string texte) override;
	Couleur changerCouleur(Couleur couleur, int couleurAffichage) override;
private:
	string nom_;
};