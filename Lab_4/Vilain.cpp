#include "Vilain.hpp"

Vilain::Vilain(const std::string& nom, const std::string& parution, const std::string& objectif) : 
	Personnage(nom, parution),
	objectif_(objectif)
{
}

void Vilain::afficher(std::ostream& os) const
{
	Personnage::afficher(os);
	os << "Objectif: "
		<< objectif_;
}

void Vilain::changerCouleur(std::ostream& os, const std::string& couleur) const
{
	os << couleur;
	afficher(os);
	os << CODE_COULEUR_FIN;
}
