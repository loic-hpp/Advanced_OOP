//	Description: Impl�mentation de la classe Heros
//	Fichier:  Heros.cpp
//	Auteurs : Rodrigo A. Merino Martel et Lo�c Nguemegne Temena
//	Date	07 novembre 2022
//	Cr�� le 8 novembre 2022

#include "Heros.hpp"

Heros::Heros(const std::string& nom, const std::string& parution, const std::string& ennemi) :
	Personnage(nom, parution),
	ennemi_(ennemi)
{
}

Heros::Heros(const Heros& hero) : Personnage(hero.obtenirNom(), hero.obtenirParution())
{
	ennemi_ = hero.ennemi_;
	allies_ = hero.allies_;
}

void Heros::afficher(std::ostream& os) const
{
	changerCouleur(os, BLEU);
	afficherAllies(os, BLEU);
}

void Heros::changerCouleur(std::ostream& os, const std::string& couleur) const
{
	os << couleur;
	Personnage::changerCouleur(os, couleur);
	os << couleur
		<< "\nEnnemi: "
		<< ennemi_;

}

void Heros::afficherAllies(std::ostream& os, const std::string& couleur) const {
	os << couleur
		<< "\nAllies: ";
	for (int i = 0; i < allies_.size(); i++)
		os << "\n \t" << allies_[i];
	os << CODE_COULEUR_FIN;
}
