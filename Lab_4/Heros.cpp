#include "Heros.hpp"

Heros::Heros(const std::string& nom, const std::string& parution, const std::string& ennemi) : 
	Personnage(nom, parution),
	ennemi_(ennemi)
{
}

Heros::Heros(const Heros& hero) : Personnage(hero.getNom(), hero.getParution())
{
	ennemi_ = hero.ennemi_;
	allies_ = hero.allies_;
}

void Heros::afficher(std::ostream& os) const
{
	changerCouleur(os);
	Personnage::afficher(os);
	changerCouleur(os);
	os << "\nEnnemi: "
		<< ennemi_;
	os << "\nAlies: ";
	for (int i = 0; i < allies_.size(); i++) {
	changerCouleur(os);
	os << "\n \t" << allies_[i] << CODE_COULEUR_FIN;
	}
}

void Heros::changerCouleur(std::ostream& os, const std::string& couleur) const
{
	os << couleur;
}
