//	Implementation de la classe Villain.
//	Fichier:  Liste.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	8 novembre 2022
//	Créé le 6 novembre 2022

#pragma once
#include "Villain.hpp"

Villain::Villain(string& nom, string& parution, string& objectif) :
	Personnage(nom, parution),
	objectif_(objectif)
{
}

void Villain::afficher(std::ostream& os) const
{

}

void Villain::changerCouleur(std::ostream& os, const int couleurAffichage) const
{

}

string Villain::obtenirNom() const
{

}

string Villain::obtenirParution() const
{

}

void Villain::obtenirObjectif() const
{

}

void Villain::afficherObjectif(ostream& os, int& couleur) const
{

}