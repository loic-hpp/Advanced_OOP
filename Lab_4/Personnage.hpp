#pragma once
#include "Affichable.hpp"
#include <string>

class Personnage : public Affichable
{
public:
	Personnage(string& nom, string& parution);
	void afficher(std::ostream& os) const override;
	void changerCouleur(std::ostream& os, const int couleurAffichage) const override;
	
	virtual string obtenirNom() const;
	virtual string obtenirParution() const;

	virtual ~Personnage() = default;
private:
	string nom_;
	string parution_;
};