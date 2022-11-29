<<<<<<< HEAD
//	Definition de la classe Villain.
//	Fichier:  Liste.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	8 novembre 2022
//	Créé le 6 novembre 2022

#pragma once
#include <string>
#include "Personnage.hpp"
#include <vector>

using namespace std;

class Vilain : virtual public Personnage
{
public:
	Vilain(string& nom, string& parution, string& objectif);
	void afficher(std::ostream& os) const override;
	void changerCouleur(std::ostream& os, const int couleurAffichage) const override;
	string obtenirNom() const override;
	string obtenirParution() const override;

	virtual string obtenirObjectif() const;

	virtual ~Vilain() = default;
private:
	string objectif_;
};
=======
//	Description: Définition de la classe Vilain
//	Fichier:  Vilain.hpp
//	Auteurs : Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	07 novembre 2022
//	Créé le 8 novembre 2022

#pragma once
#include "Personnage.hpp"
const std::string ROUGE = "\033[91m";
class Vilain :
	virtual public Personnage
{
public:
	Vilain(const std::string& nom, const std::string& parution, const std::string& objectif);
	Vilain(const Vilain& vilain);
	virtual void afficher(std::ostream& os) const override;
	virtual void changerCouleur(std::ostream& os, const std::string& couleur = ROUGE) const override;
	virtual std::string obtenirObjectif()const { return objectif_; }
	virtual ~Vilain() = default;
private:
	std::string objectif_;
};

>>>>>>> main
