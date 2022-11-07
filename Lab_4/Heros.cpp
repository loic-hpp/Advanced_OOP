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