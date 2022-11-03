#include "Vilain.hpp"

Vilain::Vilain(const std::string& nom, const std::string& parution, const std::string& objectif) : 
	Personnage(nom, parution),
	objectif_(objectif)
{
}

void Vilain::afficher(std::ostream& os) const
{
	changerCouleur(os);
	Personnage::afficher(os);
	changerCouleur(os);
	os << "\nObjectif: "
		<< objectif_
		<< CODE_COULEUR_FIN;
}

void Vilain::changerCouleur(std::ostream& os, const std::string& couleur) const
{
	os << couleur;
}
