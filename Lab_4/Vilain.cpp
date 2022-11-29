<<<<<<< HEAD
//	Implementation de la classe Villain.
//	Fichier:  Liste.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	8 novembre 2022
//	Créé le 6 novembre 2022

#pragma once
#include "Vilain.hpp"

Vilain::Vilain(string& nom, string& parution, string& objectif) :
=======
//	Description: Implémentation de la classe Vilain
//	Fichier:  Vilain.cpp
//	Auteurs : Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	07 novembre 2022
//	Créé le 8 novembre 2022

#include "Vilain.hpp"

Vilain::Vilain(const std::string& nom, const std::string& parution, const std::string& objectif) :
>>>>>>> main
	Personnage(nom, parution),
	objectif_(objectif)
{
}

<<<<<<< HEAD
void Vilain::afficher(std::ostream& os) const
{
	changerCouleur(os, 199);
}

void Vilain::changerCouleur(std::ostream& os, const int couleurAffichage) const
{
	os <<
		"Objectif : " << obtenirObjectif() << "\n";
	// Code couleur qqch.
}

string Vilain::obtenirObjectif() const
{
	return objectif_;
=======
Vilain::Vilain(const Vilain& vilain) : Personnage(vilain.obtenirNom(), vilain.obtenirParution())
{
	objectif_ = vilain.objectif_;
}

void Vilain::afficher(std::ostream& os) const
{
	changerCouleur(os, ROUGE);

}

void Vilain::changerCouleur(std::ostream& os, const std::string& couleur) const
{
	os << couleur;
	Personnage::changerCouleur(os, couleur);
	os << couleur
		<< "\nObjectif: "
		<< objectif_
		<< CODE_COULEUR_FIN;
>>>>>>> main
}
