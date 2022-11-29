<<<<<<< HEAD
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

=======
//	Description: Implémentation de la classe VilainHeros
//	Fichier:  VilainHeros.cpp
//	Auteurs partiels : Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	07 novembre 2022
//	Créé le 8 novembre 2022

#include "VilainHeros.hpp"

VilainHeros::VilainHeros(const Heros& hero, const Vilain& vilain) :
	Heros(hero),
	Vilain(vilain),
	Personnage(vilain.obtenirNom() + '-' + hero.obtenirNom(), 
		vilain.obtenirParution() + '-' + hero.obtenirParution()),
	missionSpeciale_(vilain.obtenirObjectif() + " dans le monde de " 
		+ hero.obtenirParution())
{
>>>>>>> main
}

void VilainHeros::afficher(std::ostream& os) const
{
<<<<<<< HEAD
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

=======
	changerCouleur(os, MAUVE);
}

void VilainHeros::changerCouleur(std::ostream& os, const std::string& couleur) const
{
	os << couleur;
	Vilain::changerCouleur(os, couleur);
	Heros::afficherAllies(os, couleur);
	os << couleur;
	os << "\nMission speciale: "
		<< missionSpeciale_
		<< CODE_COULEUR_FIN;
}
>>>>>>> main
