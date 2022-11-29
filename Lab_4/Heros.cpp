<<<<<<< HEAD
//	Implementation de la classe Heros.
//	Fichier:  Liste.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	8 novembre 2022
//	Créé le 6 novembre 2022

#include "Heros.hpp"
#include "cppitertools/range.hpp"
using namespace iter;

Heros::Heros(string& nom, string& parution, string& nomEnnemi) :
	Personnage(nom, parution),
	nomEnnemi_(nomEnnemi)
{
}

void Heros::afficher(std::ostream& os) const
{
	changerCouleur(os, 94);
	afficherAllies;
}

void Heros::changerCouleur(std::ostream& os, const int couleurAffichage) const
{
	os <<
		couleurAffichage;
	Personnage::changerCouleur(os, couleurAffichage);
	os <<
		couleurAffichage << "Ennemmi : " << obtenirNomEnnemi() << "\n";
	// TODO: Pourquoi erreur sur << ?
}

void Heros::afficherAllies(ostream& os, int& couleur) const
{
	os <<
		"Allies : ";
	for (int i = 0; i < nomAllies_.size(); i++)
	{
		os << "\t" << nomAllies_[i];
	}
	//os << CODE_COULEUR_FIN; // Verifier c'est quoi!
}

void Heros::mettreAllies(const vector<string> nomAllies)
{
	nomAllies_ = nomAllies;
}
=======
//	Description: Implémentation de la classe Heros
//	Fichier:  Heros.cpp
//	Auteurs : Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	07 novembre 2022
//	Créé le 8 novembre 2022

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
>>>>>>> main
