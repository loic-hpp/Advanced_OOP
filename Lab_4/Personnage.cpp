<<<<<<< HEAD
//	Implementation de la classe Personnage.
//	Fichier:  Liste.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	8 novembre 2022
//	Créé le 6 novembre 2022

#include "Personnage.hpp"

Personnage::Personnage(string& nom, string& parution)
{
	nom_ = nom;
	parution_ = parution;
=======
//	Description: Implémentation de la classe Personnage
//	Fichier:  Personnage.cpp
//	Auteurs : Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	07 novembre 2022
//	Créé le 8 novembre 2022

#include "Personnage.hpp"

Personnage::Personnage(const std::string& nom, const std::string& parution) :
	nom_(nom),
	parution_(parution)
{
>>>>>>> main
}

void Personnage::afficher(std::ostream& os) const
{
<<<<<<< HEAD
	os <<
		"Nom : " << obtenirNom() << "\n" <<
		"Parution : " << obtenirParution() << "\n";
	// Loic fait CODE_COULEUR_FIN?
}

void Personnage::changerCouleur(std::ostream& os, const int couleurAffichage) const
{
	changerCouleur(os, 23);
}

string Personnage::obtenirNom() const
{
	return nom_;
}

string Personnage::obtenirParution() const
{
	return parution_;
}
=======
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
>>>>>>> main
