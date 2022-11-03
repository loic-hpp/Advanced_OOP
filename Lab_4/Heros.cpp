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
	changerCouleur(os, "\033[94m");
	afficherAlie(os, "\033[94m");
}

void Heros::changerCouleur(std::ostream& os, const std::string& couleur) const
{
	os << couleur;
	Personnage::changerCouleur(os, couleur);
	os << couleur
		<< "\nEnnemi: "
		<< ennemi_;
	
}

void Heros::afficherAlie(std::ostream& os, const std::string& couleur) const {
	os << couleur
		<< "\nAlies: ";
	for (int i = 0; i < allies_.size(); i++) 
		os << "\n \t" << allies_[i];
	os << CODE_COULEUR_FIN;
}
