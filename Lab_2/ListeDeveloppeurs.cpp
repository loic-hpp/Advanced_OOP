#include "Developpeur.hpp"
#include "ListeDeveloppeurs.hpp"

//NOTE: Le code sera principalement copié de certaines fonctions écrites pour la partie 1, mais mises dans une classe.
ListeDeveloppeurs::~ListeDeveloppeurs()
{
	for (int i : iter::range(nElements_)) {
		elements_[i] -> ~Developpeur();
	}
	delete[] elements_;
}

size_t ListeDeveloppeurs::obtenirNElements() const
{
	return nElements_;
}

size_t ListeDeveloppeurs::obtenirCapacite() const
{
	return capacite_;
}

Developpeur** ListeDeveloppeurs::obtenirElements() const
{
	return elements_;
}

Developpeur* ListeDeveloppeurs::obtenirElements(int index) const
{
	return elements_[index];
}

void ListeDeveloppeurs::modifierNElements(size_t nouveauNElements)
{
	nElements_ = nouveauNElements;
}

void ListeDeveloppeurs::modifierCapacite(size_t nouvelleCapacite)
{
	capacite_ = nouvelleCapacite;
}

void ListeDeveloppeurs::modifierElements(Developpeur** elements)
{
	elements_ = elements;
}

void ListeDeveloppeurs::modifierElements(Developpeur* elements, int index)
{
	elements_[index] = elements;
}

void afficher(ListeJeux listeJeux)
{
	afficherListeJeuxDeveloppes(listeJeux);
}

void ajouterDeveloppeur(ListeDeveloppeurs& listeDeveloppeurs, Developpeur* developpeur)
{
	size_t index = listeDeveloppeurs.obtenirNElements();
	if (listeDeveloppeurs.obtenirNElements() == listeDeveloppeurs.obtenirCapacite()) {
		if (listeDeveloppeurs.obtenirCapacite() == 0)
			index = 0;
		changerTailleListeDeveloppeurs(listeDeveloppeurs);
	}
	listeDeveloppeurs.modifierElements(developpeur, index);
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
	for (Developpeur* developpeur : gsl::span(listeDeveloppeurs.obtenirElements(), listeDeveloppeurs.obtenirNElements())) {
		nouvelleListe[i] = developpeur;
		i++;
	}
	delete[] listeDeveloppeurs.obtenirElements();
	listeDeveloppeurs.modifierElements(nullptr);
	listeDeveloppeurs.modifierElements(nouvelleListe);
}

void retirerDeveloppeur(ListeDeveloppeurs& listeDeveloppeurs, Developpeur* developpeurParametre)
{
	int i = 0;
	for (Developpeur*& developpeur : gsl::span(listeDeveloppeurs.obtenirElements(), listeDeveloppeurs.obtenirNElements())) {
		if (developpeurParametre == developpeur)
			listeDeveloppeurs.modifierElements(listeDeveloppeurs.obtenirElements(listeDeveloppeurs.obtenirNElements() - 1), i);
		i++;
	}
	listeDeveloppeurs.modifierNElements(listeDeveloppeurs.obtenirNElements() - 1);
	listeDeveloppeurs.modifierElements(nullptr, listeDeveloppeurs.obtenirNElements());
	listeDeveloppeurs.modifierNElements(listeDeveloppeurs.obtenirNElements() - 1);
}