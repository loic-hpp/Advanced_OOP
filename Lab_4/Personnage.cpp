#include "Personnage.hpp"

Personnage::Personnage(const std::string& nom, const std::string& parution) :
	nom_(nom),
	parution_(parution)
{
}

void Personnage::afficher(std::ostream& os) const
{
	changerCouleur(os,"\033[0m");
}

void Personnage::changerCouleur(std::ostream& os, const std::string& couleur) const
{
	os << couleur
		<< "\nNom: "
		<< nom_
		<< "\nParution: "
		<< parution_
		<< CODE_COULEUR_FIN;
}
