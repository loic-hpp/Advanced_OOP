#include "VilainHeros.hpp"

VilainHeros::VilainHeros(const Heros& hero, const Vilain& vilain) :
	Heros(hero),
	Vilain(vilain),
	Personnage(vilain.getNom() + '-' + hero.getNom(), vilain.getParution() + '-' + hero.getParution()),
	missionSpeciale_(vilain.getObjectif() + "dans le monde de" + hero.getParution())

{
}

void VilainHeros::afficher(std::ostream& os) const
{
	changerCouleur(os);
	Heros::afficher(os);
	changerCouleur(os);
	os << "\nObjectif: "
		<< Vilain::getObjectif()
		<< "\nMission speciale: "
		<< missionSpeciale_
		<< CODE_COULEUR_FIN;
}

void VilainHeros::changerCouleur(std::ostream& os, const std::string& couleur) const
{
	os << couleur;
}
