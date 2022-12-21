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

}

void VilainHeros::afficher(std::ostream& os) const
{
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
