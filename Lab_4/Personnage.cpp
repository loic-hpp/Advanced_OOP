#include "Personnage.hpp"

Personnage::Personnage(const std::string& nom, const std::string& parution) :
	nom_(nom),
	parution_(parution)
{
}

void Personnage::afficher(std::ostream& os) const
{
	os << "\nNom: "
		<< nom_
		<< "\nParution: "
		<< parution_;
}

void Personnage::changerCouleur(std::ostream& os, const std::string& couleur) const
{
	os << couleur;
	afficher(os);
	os << CODE_COULEUR_FIN;
}
