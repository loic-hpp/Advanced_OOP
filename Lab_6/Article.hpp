#pragma once
#include <iostream>
#include <string>


struct Article
{
	std::string description;
	double price;
	bool taxable;
	~Article() = default;
	std::string displayArticle() { return "a completer"; }
	std::string displayPrice() { return "a completer"; }

	// Conteneur STL pour les articles
	/*template<typename F>
	std::shared_ptr<Concepteur> trouverConcepteur(const F fonction) {
		return concepteurs.trouverElementQuelconque(fonction);
	}*/

	// fonction lambda pour total des taxes et algo STL -> parcourir articles dans vecteur SANS FOR OU WHILE

	// Retirer article -> iterateur pour vector -> INDEX INTERDIT
};

// TODO: lancer exception capturee par vue quand description vide ou prix = 0; Message different