//	Definition de la classe VillainHeros.
//	Fichier:  Liste.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	8 novembre 2022
//	Créé le 6 novembre 2022

#pragma once
#include <string>
#include "Heros.hpp"
#include "Villain.hpp"

// TODO: Pourquoi cette erreur?
class VillainHeros : public Heros, public Villain
{
public:
	VillainHeros(const Heros& hero, const Villain& villain);
	virtual void afficher(std::ostream& os) const override;
	virtual void changerCouleur(std::ostream& os, const int couleurAffichage) const override;

private:
	string mission_;
};