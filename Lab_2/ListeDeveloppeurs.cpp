#include "ListeDeveloppeurs.hpp"

//NOTE: Le code sera principalement copié de certaines fonctions écrites pour la partie 1, mais mises dans une classe.
ListeDeveloppeurs::~ListeDeveloppeurs()
{
	/*for (int i : iter::range(nElements_)) {
		elements_[i] -> ~Developpeur();
	}*/
	delete[] elements_;
}
ListeDeveloppeurs::ListeDeveloppeurs(int nelt, int capacite, Developpeur** elements) : nElements_(nelt), capacite_(capacite), elements_(elements)
{
}

void ListeDeveloppeurs::afficher()
{
	for (int i = 0; i < nElements_; i++) {
		elements_[i]->afficheListeJeuxDev();
	}
}

void ListeDeveloppeurs::ajouterDeveloppeur(Developpeur* developpeur)
{
	size_t index = nElements_;
	if (nElements_ == capacite_) {
		if (capacite_ == 0)
			index = 0;
		this->changerTailleListeDeveloppeurs();
	}
	elements_[index] = developpeur;
	nElements_++;
}

void ListeDeveloppeurs::changerTailleListeDeveloppeurs()
{
	if (capacite_ == 0)
		capacite_ = 1;
	else
		capacite_ *=2;
	Developpeur** nouvelleListe = new Developpeur * [capacite_];
	int i = 0;
	for (Developpeur* developpeur : gsl::span(elements_, nElements_)) {
		nouvelleListe[i] = developpeur;
		i++;
	}
	delete[] elements_;
	elements_ = nullptr;
	elements_ = nouvelleListe;
}

void ListeDeveloppeurs::retirerDeveloppeur(Developpeur* developpeurParametre)
{
	int i = 0;
	for (Developpeur*& developpeur : gsl::span(elements_, nElements_)) {
		if (developpeurParametre->nomDeveloppeur() == developpeur->nomDeveloppeur())
			elements_[i] = elements_[nElements_ - 1];
		i++;
	}
	elements_[nElements_ - 1] = nullptr;
	nElements_--;
}