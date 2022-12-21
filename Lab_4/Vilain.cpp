//	Description: Implémentation de la classe Vilain
//	Fichier:  Vilain.cpp
//	Auteurs : Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	07 novembre 2022
//	Créé le 8 novembre 2022

#include "Vilain.hpp"

Vilain::Vilain(const std::string& nom, const std::string& parution, const std::string& objectif) :
	Personnage(nom, parution),
	objectif_(objectif)
{
}



Vilain::Vilain(const Vilain& vilain) : Personnage(vilain.obtenirNom(), vilain.obtenirParution())
{
	objectif_ = vilain.objectif_;
}

void Vilain::afficher(std::ostream& os) const
{
	changerCouleur(os, ROUGE);

}

void Vilain::changerCouleur(std::ostream& os, const std::string& couleur) const
{
	os << couleur;
	Personnage::changerCouleur(os, couleur);
	os << couleur
		<< "\nObjectif: "
		<< objectif_
		<< CODE_COULEUR_FIN;
}
