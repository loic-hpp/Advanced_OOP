#include "Heros.hpp"

Heros::Heros(const std::string& nom, const std::string& parution, const std::string& ennemi, const std::vector<std::string>& allies) : 
	Personnage(nom, parution),
	ennemi_(ennemi),
	allies_(allies)
{
}

void Heros::afficher(std::ostream& os) const
{
	Personnage::afficher(os);
	os << "\nEnnemi: "
		<< ennemi_;
	os << "\nAlies: ";
	for (int i = 0 < allies_.size(); i++;)
		os << "\n \t" << allies_[i];
}

void Heros::changerCouleur(std::ostream& os, const std::string& couleur) const
{
	os << couleur;
	afficher(os);
	os << CODE_COULEUR_FIN;
}
