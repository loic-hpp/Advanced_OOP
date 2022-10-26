#pragma once
#include <string>
#include "ListeConcepteurs.hpp"
#include "Liste.hpp"

struct Jeu
{
	std::string titre;
	int anneeSortie;
	std::string developpeur;
	Liste<Concepteur> concepteurs;

	template<typename F>
	std::shared_ptr<Concepteur> trouverConcepteur(const F fonction) {
		return concepteurs.trouverElementQuelconque(fonction);
	}
};

