#pragma once
#include <cstddef>
#include "Developpeur.hpp"

class ListeDeveloppeurs
{
public:
	ListeDeveloppeurs()
	{
		ListeDeveloppeurs listeDeveloppeurs = {};
		listeDeveloppeurs.capacite_ = 0;
		listeDeveloppeurs.nElements_ = 0;
	}
	
	size_t obtenirNElements() const;
	size_t obtenirCapacite() const;
	Developpeur** obtenirElements(int index) const;
	
	void modifierNElements(size_t nouveauNElements);
	void modifierCapacite(size_t nouvelleCapacite);
	void modifierElements(ListeDeveloppeurs liste);

	void afficher(ListeJeux listeJeux);
	void ajouterDeveloppeur(ListeDeveloppeurs& listeDeveloppeurs, Developpeur* developpeur);
	void changerTailleListeDeveloppeurs(ListeDeveloppeurs& listeDeveloppeurs);
	void retirerDeveloppeur(ListeDeveloppeurs& listeDeveloppeurs, Developpeur* developpeurParametre);

private:
	std::size_t nElements_, capacite_;
	Developpeur** elements_;
};