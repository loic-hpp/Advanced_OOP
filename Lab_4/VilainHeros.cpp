//	Description: Implémentation de la classe VilainHeros
//	Fichier:  VilainHeros.cpp
//	Auteurs partiels : Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	07 novembre 2022
//	Créé le 26 octobre 2022

#include "VilainHeros.hpp"

VilainHeros::VilainHeros(const Heros& hero, const Vilain& vilain) :
	Heros(hero),
	Vilain(vilain),
	Personnage(vilain.getNom() + '-' + hero.getNom(), vilain.getParution() + '-' + hero.getParution()),
	missionSpeciale_(vilain.getObjectif() + " dans le monde de " + hero.getParution())

{
}

void VilainHeros::afficher(std::ostream& os) const
{
	changerCouleur(os , MAUVE);
}

void VilainHeros::changerCouleur(std::ostream& os, const std::string& couleur) const
{
	os << couleur;
	Vilain::changerCouleur(os, couleur);
	Heros::afficherAlie(os, couleur);
	os << couleur;
	os << "\nMission speciale: "
		<< missionSpeciale_
		<< CODE_COULEUR_FIN;
}
