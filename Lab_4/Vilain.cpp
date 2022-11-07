//	Implementation de la classe Villain.
//	Fichier:  Liste.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	8 novembre 2022
//	Créé le 6 novembre 2022

#pragma once
#include "Vilain.hpp"

Vilain::Vilain(string& nom, string& parution, string& objectif) :
	Personnage(nom, parution),
	objectif_(objectif)
{
}

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
}
