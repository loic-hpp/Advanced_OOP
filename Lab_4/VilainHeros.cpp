//	Implementation de la classe VillainHeros.
//	Fichier:  Liste.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	8 novembre 2022
//	Créé le 6 novembre 2022

#pragma once
#include "VilainHeros.hpp"

VilainHeros::VilainHeros(const Heros& hero, const Vilain& villain) :
	Heros(hero),
	Vilain(villain),
	Personnage(villain.obtenirNom() + "-" + hero.obtenirNom(),
		villain.obtenirParution() + "-" + hero.obtenirParution()),
	mission_(villain.obtenirObjectif() + " dans le monde de " + hero.obtenirParution())
{

}

void VilainHeros::afficher(std::ostream& os) const
{
	changerCouleur(os, 50);
}

void VilainHeros::changerCouleur(std::ostream& os, const int couleurAffichage) const
{
	os << couleurAffichage;
	Vilain::changerCouleur(os, couleurAffichage);
	Heros::afficherAllies(os, couleurAffichage);
	os << couleurAffichage;
	os <<
		"Mission spéciale : "
		<< mission_;
		// CODE COULEUR FIN
}

