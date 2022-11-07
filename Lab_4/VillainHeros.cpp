//	Implementation de la classe VillainHeros.
//	Fichier:  Liste.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	8 novembre 2022
//	Créé le 6 novembre 2022

#pragma once
#include "VillainHeros.hpp"

VillainHeros::VillainHeros(const Heros& hero, const Villain& villain) :
	Heros(hero),
	Villain(villain),
	Personnage(villain.obtenirNom() + "-" + hero.obtenirNom(),
		villain.obtenirParution() + "-" + hero.obtenirParution()),
	mission_(villain.obtenirObjectif() + " dans le monde de " + hero.obtenirParution())
{

}

void afficher(std::ostream& os) const
{
	changerCouleur(os, 50);
}

void changerCouleur(std::ostream& os, const int couleurAffichage) const
{
	os << couleurAffichage;
	Villain::changerCouleur(os, couleurAffichage);
	Heros::afficherAllies(os, couleurAffichage);
	os << couleurAffichage;
	os <<
		"Mission spéciale : "
		<< mission_;
		// CODE COULEUR FIN
}

