#pragma once
#include <string>
#include <Affichable.hpp>

using namespace std;

class Heros: public Affichable
{
public:
	Heros();
	string afficher(string texte) const override;
	Couleur changerCouleur(Couleur couleur) const override;
private:
	string nom;
};
