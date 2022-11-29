<<<<<<< HEAD
//	Definition de la classe Heros.
//	Fichier:  Liste.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	8 novembre 2022
//	Créé le 6 novembre 2022

#pragma once
#include <string>
#include "Personnage.hpp"
#include <vector>

using namespace std;

class Heros : virtual public Personnage
{
public:
	Heros(string& nom, string& parution, string& nomEnnemi);
	void afficher(std::ostream& os) const override;
	void changerCouleur(std::ostream& os, const int couleurAffichage) const override;
	string obtenirNom() const override;
	string obtenirParution() const override;

	virtual void obtenirNomEnnemi() const;
	virtual void afficherAllies(ostream& os, int& couleur) const;
	virtual void mettreAllies(const vector<string> nomAllies);

	virtual ~Heros() = default;
private:
	vector<string> nomAllies_;
	string nomEnnemi_;
};
=======
//	Description: Définition de la classe Heros
//	Fichier:  Heros.hpp
//	Auteurs : Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	07 novembre 2022
//	Créé le 8 novembre 2022

#pragma once
#include "Personnage.hpp"
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
>>>>>>> main
