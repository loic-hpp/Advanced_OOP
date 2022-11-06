#pragma once
#include <string>
#include "Personnage.hpp"
#include <vector>

using namespace std;

class Heros: virtual public Personnage
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
