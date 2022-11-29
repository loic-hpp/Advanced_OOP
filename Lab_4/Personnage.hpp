<<<<<<< HEAD
//	Definition de la classe Personnage.
//	Fichier:  Liste.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	8 novembre 2022
//	Créé le 6 novembre 2022

#pragma once
#include "Affichable.hpp"
#include <string>

class Personnage : public Affichable
{
public:
	Personnage(string& nom, string& parution);
	void afficher(std::ostream& os) const override;
	void changerCouleur(std::ostream& os, const int couleurAffichage) const override;

	virtual string obtenirNom() const;
	virtual string obtenirParution() const;

	virtual ~Personnage() = default;
private:
	string nom_;
	string parution_;
};
=======
//	Description: Définition de la classe Personnage
//	Fichier:  Personnage.hpp
//	Auteurs : Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	07 novembre 2022
//	Créé le 8 novembre 2022

#pragma once
#include "Affichable.hpp"
const std::string CODE_COULEUR_FIN = "\033[0m";
class Personnage :
	public Affichable
{
public:
	Personnage() = default;
	Personnage(const std::string& nom, const std::string& parution);
	virtual void afficher(std::ostream& os) const override;
	virtual void changerCouleur(std::ostream& os, const std::string& couleur = CODE_COULEUR_FIN) const override;
	virtual ~Personnage() = default;
	virtual std::string obtenirNom()const { return nom_; }
	virtual std::string obtenirParution()const { return parution_; }
	Personnage(const Personnage&) = delete;
	Personnage& operator= (const Personnage&) = delete;
private:
	std::string nom_;
	std::string parution_;

};

>>>>>>> main
