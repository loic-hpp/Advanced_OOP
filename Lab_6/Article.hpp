#include <string>


struct Article
{
	std::string description;
	double prix;
	bool taxable;
	double totalAvantTaxes;

	// Conteneur STL pour les articles
	/*template<typename F>
	std::shared_ptr<Concepteur> trouverConcepteur(const F fonction) {
		return concepteurs.trouverElementQuelconque(fonction);
	}*/

	// fonction lambda pour total des taxes et algo STL -> parcourir articles dans vecteur SANS FOR OU WHILE

	// Retirer article -> iterateur pour vector -> INDEX INTERDIT
};

// TODO: lancer exception capturee par vue quand description vide ou prix = 0; Message different