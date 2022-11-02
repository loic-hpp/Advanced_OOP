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
	Heros::afficher(os);
	os << "\nObjectif: "
		<< Vilain::getObjectif()
		<< "\nMission speciale: "
		<< missionSpeciale_;
}

void VilainHeros::changerCouleur(std::ostream& os, const std::string& couleur) const
{
	os << couleur;
	afficher(os);
	os << CODE_COULEUR_FIN;
}
