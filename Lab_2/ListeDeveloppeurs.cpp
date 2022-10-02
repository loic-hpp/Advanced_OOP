#include "Developpeur.hpp"
#include "ListeDeveloppeurs.hpp"

ListeDeveloppeurs::~ListeDeveloppeurs()
{
	// Liberer
	// TODO: On veut pouvoir ajouter et enlever un Developpeur* de la liste, 
	// avec r�allocation dynamique tel que faite pour ListeJeux.
}

size_t ListeDeveloppeurs::obtenirNElements() const
{
	return nElements_;
}

size_t ListeDeveloppeurs::obtenirCapacite() const
{
	return capacite_;
}

Developpeur** ListeDeveloppeurs::obtenirElements(int index) const
{

}

void ListeDeveloppeurs::modifierNElements(size_t nouveauNElements)
{
	nElements_ = nouveauNElements;
}

void ListeDeveloppeurs::modifierCapacite(size_t nouvelleCapacite)
{
	capacite_ = nouvelleCapacite;
}

void ListeDeveloppeurs::modifierElements(ListeDeveloppeurs listeDeveloppeurs)
{
	// TODO
}

void afficher(ListeJeux listeJeux)
{
	afficherListeJeuxDeveloppes(listeJeux);
}

void ajouterDeveloppeur(ListeDeveloppeurs& listeDeveloppeurs, Developpeur* developpeur)
{
	//TODO: � adapter 
	size_t index = listeDeveloppeurs.obtenirNElements();
	if (listeDeveloppeurs.obtenirNElements() == listeDeveloppeurs.obtenirCapacite()) {
		if (listeDeveloppeurs.obtenirCapacite() == 0)
			index = 0;
		changerTailleListeDeveloppeurs(listeDeveloppeurs);
	}
	listeDeveloppeurs.elements[index] = developpeur;
	listeDeveloppeurs.modifierNElements(listeDeveloppeurs.obtenirNElements() + 1);
}

void changerTailleListeDeveloppeurs(ListeDeveloppeurs& listeDeveloppeurs)
{
	if (listeDeveloppeurs.obtenirCapacite() == 0)
		listeDeveloppeurs.modifierCapacite(1);
	else
		listeDeveloppeurs.modifierCapacite(listeDeveloppeurs.obtenirCapacite() * 2);
	Developpeur** nouvelleListe = new Developpeur * [listeDeveloppeurs.obtenirCapacite()];
	int i = 0;
	for (Developpeur* developpeur : gsl::span(listeDeveloppeurs.elements, listeDeveloppeurs.obtenirNElements())) {
		nouvelleListe[i] = developpeur;
		i++;
	}
	delete[] listeDeveloppeurs.elements;
	listeDeveloppeurs.elements = nullptr;
	listeDeveloppeurs.elements = nouvelleListe;
}

void retirerDeveloppeur(ListeDeveloppeurs& listeDeveloppeurs, Developpeur* developpeurParametre)
{
	int i = 0;
	for (Developpeur*& developpeur : gsl::span(listeDeveloppeurs.elements, listeDeveloppeurs.obtenirNElements())) {
		if (developpeurParametre == developpeur)
			listeDeveloppeurs.elements[i] = listeDeveloppeurs.elements[listeDeveloppeurs.obtenirNElements() - 1];
		i++;
	}
	listeDeveloppeurs.elements[listeDeveloppeurs.modifierNElements(listeDeveloppeurs.obtenirNElements() - 1)] = nullptr;
	listeDeveloppeurs.modifierNElements(listeDeveloppeurs.obtenirNElements() - 1);
}
//NOTE: Le code sera principalement copi� de certaines fonctions �crites pour la partie 1, mais mises dans une classe.
