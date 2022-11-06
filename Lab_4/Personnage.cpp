#include "Personnage.hpp"

Personnage::Personnage(string& nom, string& parution)
{
	nom_ = nom;
	parution_ = parution;
}

void Personnage::afficher(std::ostream& os) const
{
	os <<
		"Nom : " << obtenirNom() << "\n" <<
		"Parution : " << obtenirParution() << "\n";
	// Loic fait CODE_COULEUR_FIN?
}

void Personnage::changerCouleur(std::ostream& os, const int couleurAffichage) const
{
	changerCouleur(os, 23);
}

string Personnage::obtenirNom() const
{
	return nom_;
}

string Personnage::obtenirParution() const
{
	return parution_;
}