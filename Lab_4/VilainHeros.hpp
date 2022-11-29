<<<<<<< HEAD
//	Definition de la classe VillainHeros.
//	Fichier:  Liste.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	8 novembre 2022
//	Créé le 6 novembre 2022

#pragma once
#include <string>
#include "Heros.hpp"
#include "Vilain.hpp"

// TODO: Pourquoi cette erreur?
class VilainHeros : public Heros, public Vilain
{
public:
	VilainHeros(const Heros& hero, const Vilain& villain);
	virtual void afficher(std::ostream& os) const override;
	virtual void changerCouleur(std::ostream& os, const int couleurAffichage) const override;

private:
	string mission_;
};
=======
//	Description: Définition de la classe VilainHeros
//	Fichier:  VilainHeros.hpp
//	Auteurs partiels : Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	07 novembre 2022
//	Créé le 8 novembre 2022

#pragma once
#include "Heros.hpp"
#include "Vilain.hpp"

const std::string MAUVE = "\033[95m";

class VilainHeros :
	public Heros,
	public Vilain
{
public:
	VilainHeros(const Heros& hero, const Vilain& vilain);
	virtual void afficher(std::ostream& os) const override;
	virtual void changerCouleur(std::ostream& os, const std::string& couleur = MAUVE) const override;

private:
	std::string missionSpeciale_;
};

>>>>>>> main
