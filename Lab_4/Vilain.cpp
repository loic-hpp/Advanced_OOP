#include "Vilain.hpp"

Vilain::Vilain(const std::string& nom, const std::string& parution, const std::string& objectif) : 
	Personnage(nom, parution),
	objectif_(objectif)
{
}

Vilain::Vilain(const Vilain& vilain) : Personnage(vilain.getNom(), vilain.getParution())
{
	objectif_ = vilain.objectif_;
}

void Vilain::afficher(std::ostream& os) const
{
	changerCouleur(os, "\033[91m");
	
}

void Vilain::changerCouleur(std::ostream& os, const std::string& couleur) const
{
	os << couleur;
	Personnage::changerCouleur(os, couleur);
	os << couleur
		<< "\nObjectif: "
		<< objectif_
		<< CODE_COULEUR_FIN;
}
