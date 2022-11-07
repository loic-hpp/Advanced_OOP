//	Description: Impl�mentation de la classe Personnage
//	Fichier:  Personnage.cpp
//	Auteurs : Rodrigo A. Merino Martel et Lo�c Nguemegne Temena
//	Date	07 novembre 2022
//	Cr�� le 8 novembre 2022

#include "Personnage.hpp"

Personnage::Personnage(const std::string& nom, const std::string& parution) :
	nom_(nom),
	parution_(parution)
{
}

void Personnage::afficher(std::ostream& os) const
{
	changerCouleur(os, CODE_COULEUR_FIN);
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
