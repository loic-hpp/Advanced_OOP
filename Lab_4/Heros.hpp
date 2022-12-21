//	Description: Définition de la classe Heros
//	Fichier:  Heros.hpp
//	Auteurs : Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	07 novembre 2022
//	Créé le 8 novembre 2022

#pragma once
#include <string>
#include "Personnage.hpp"
#include <vector>
const std::string BLEU = "\033[94m";
class Heros :
	virtual public Personnage
{
public:
	Heros(const std::string& nom, const std::string& parution, const std::string& ennemi);
	Heros(const Heros& hero);
	virtual void afficher(std::ostream& os) const override;
	virtual void changerCouleur(std::ostream& os, const std::string& couleur = BLEU) const override;
	virtual void mettreListeAllies(const std::vector<std::string>& allies) { allies_ = allies; }
	void afficherAllies(std::ostream& os, const std::string& couleur) const;
	virtual ~Heros() = default;

private:
	std::string ennemi_;
	std::vector<std::string> allies_;
};
